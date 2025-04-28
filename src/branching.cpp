#include "branching.hpp"
#include "enums.hpp"
#include "expression.hpp"
#include "organizer.hpp"
#include <vector>

extern int quadruplesLabel;
extern std::vector<int> breakJumpTo;
extern std::vector<int> continueJumpTo;

// =========================================================================================
// ======================================== IF NODE ========================================
// =========================================================================================

IfNode::IfNode( int line, Expression* condition, ProgramNode* accept, bool inverted ) : ProgramNode(line) {

    this->inverted = inverted;
    this->condition = condition;
    this->accept = accept;
    this->logLineInfo();
} 

IfNode::IfNode( int line, AssignNode* assignment, ProgramNode* accept ) : ProgramNode(line) {
    this->assignment = assignment;
    this->accept = accept;
    this->inverted = false;
    this->logLineInfo();
}


IfNode::~IfNode() {
    if (condition) delete condition, condition = nullptr;
    if (accept) delete accept, accept = nullptr;
    if (reject) delete reject, reject = nullptr;
}

std::string IfNode::nodeName() { return "IfNode"; }

IfNode* IfNode::setElse(ProgramNode* reject) { 
    this->reject = reject; 
    return this; 
}


void IfNode::run(Scope* scope) {
    Operand conditionValue;
    if (assignment) {
        assignment->run(scope);
        conditionValue = assignment->getValue();
    } else {
        conditionValue = condition->getValue(scope);
    }

    if ((bool)conditionValue != inverted) {
        accept->run(scope);
    } else if (reject) {
        reject->run(scope);
    }
}

void IfNode::runSemanticChecker(Scope* scope) {
    OperandType type = TUNDEFINED;
    try {
        type = assignment ? assignment->getType(scope) : condition->getExpectedType(scope);
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type == TUNDEFINED) {
        ErrorDetail error(Severity::ERROR, "Ivalid Expression For The If Condition");
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    } 

    if (accept)
        accept->runSemanticChecker(scope);
    if (reject)
        reject->runSemanticChecker(scope);
}

void IfNode::generateQuadruples(Scope* scope) {
    std::string condition = "";
    if (assignment) {
        assignment->generateQuadruples(scope);
        condition = assignment->varName();
    } else {
        condition = this->condition->generateQuadruples();
    }

    if (!reject) {
        int label = quadruplesLabel++;
        CompilerOrganizer::addQuadruple( 
            inverted ? QUAD_GOTO_IF_TRUE : QUAD_GOTO_IF_FALSE, 
            condition, 
            "", 
            "L" + std::to_string(label));
        accept->generateQuadruples(scope);
        CompilerOrganizer::addLabel(label);
    } else {
        int label1 = quadruplesLabel++;
        int label2 = quadruplesLabel++;
        CompilerOrganizer::addQuadruple( inverted ? QUAD_GOTO_IF_TRUE : QUAD_GOTO_IF_FALSE, 
            condition, 
            "", 
            "L" + std::to_string(label1));
        accept->generateQuadruples(scope);
        CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(label2));
        CompilerOrganizer::addLabel(label1);
        reject->generateQuadruples(scope);
        CompilerOrganizer::addLabel(label2);
    }
}

// =========================================================================================
// ====================================== Switch Node ======================================
// =========================================================================================

std::string SwitchNode::nodeName() { return "SwitchNode"; }

SwitchNode::SwitchNode( int line, Expression* id, SwitchBody* body ) : ProgramNode(line) { 
    this->body = body;
    this->identifier = id;
    this->logLineInfo();
}

void SwitchNode::run(Scope* scope) {
    ScopeNode* switchScope = new ScopeNode(-1, scope);
    switchScope->getScope()->defineBreak();

    if (body) {
        bool caseMatched = false;
        for (CaseNode* caseNode : body->getCases()) {
            caseNode->run(switchScope->getScope(), identifier, caseMatched);
            caseMatched |= caseNode->isMatched;
            if (switchScope->getScope()->hasBreak()) break;
        }
    }

    delete switchScope;
}

void SwitchNode::runSemanticChecker(Scope* scope) {
    ScopeNode* switchScope = new ScopeNode(-1, scope);
    switchScope->getScope()->defineBreak();

    try {
        identifier->getExpectedType(scope);
    } catch(ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }
    
    if (body) {
        bool caseMatched = false;
        for (CaseNode* caseNode : body->getCases()) {
            caseNode->runSemanticChecker(switchScope->getScope());
        }
    }

    delete switchScope;
}

void SwitchNode::generateQuadruples(Scope* scope) {
    if (body) {
        int breakLabel = quadruplesLabel++;
        breakJumpTo.push_back(quadruplesLabel++);

        IdentifierContainer* idContainer = dynamic_cast<IdentifierContainer*>(identifier);
        std::string name;
        if (idContainer) {
            name = idContainer->getIdentifier();
        } else {
            name = identifier->generateQuadruples(scope);
        }

        body->generateCaseLabels(name);

        const std::vector<CaseNode*>& cases = body->getCases();
        for (int i = 0; i < cases.size(); i++) {
            CaseNode* caseNode = cases[i];

            if (i == cases.size() - 1) {
                continueJumpTo.push_back(breakLabel);
            } else {
                continueJumpTo.push_back(body->getCaseLabel(i + 1));
            }

            caseNode->generateQuadruples(scope);

            if (breakJumpTo.back() != breakLabel) breakJumpTo.push_back(breakLabel);
        }
    
        CompilerOrganizer::addLabel(breakLabel);
        
        breakJumpTo.pop_back();
    }
}

SwitchNode::~SwitchNode() {
    if (identifier) delete identifier, identifier = nullptr;
    if (body) delete body, body = nullptr;
}

// =========================================================================================
// ====================================== Switch Body ======================================
// =========================================================================================

SwitchBody::SwitchBody() {}

SwitchBody::SwitchBody(CaseNode* cn) { 
    addCase(cn); 
}

SwitchBody::~SwitchBody() {
    for (CaseNode*& caseNode : cases) {
        delete caseNode;
        caseNode = nullptr;
    }
    cases.clear();
}

SwitchBody* SwitchBody::addCase(CaseNode* caseNode) { 
    cases.push_back(caseNode); return this; 
}

void SwitchBody::generateCaseLabels(std::string varName) {
    for (int i = 0; i < cases.size(); i++) {
        labels.push_back(quadruplesLabel++);
        cases[i]->skipConditionLabel = labels[i];
        cases[i]->varName = varName;
    }
}


std::vector<CaseNode*> SwitchBody::getCases() { 
    return cases; 
}

int SwitchBody::getCaseLabel(int index) { 
    return labels[index]; 
}

// =========================================================================================
// ======================================= Case Node =======================================
// =========================================================================================
CaseNode::CaseNode( int line, Expression* condition) : ProgramNode(line) {
    this->condition = condition;
    this->body = nullptr;
    this->logLineInfo();
}

CaseNode::~CaseNode() {
    if (condition) delete condition, condition = nullptr;
    if (body) delete body, body = nullptr;
}

std::string CaseNode::nodeName() {
    return "CaseNode";
}

CaseNode* CaseNode::assignBody(ProgramNode* node) {
    body = new ScopeNode(-1, node);
    return this;
}

void CaseNode::run(Scope *scope, Expression* identifier, bool forceMatch) {
    bool isSatisfied = forceMatch || condition == nullptr || condition->getValue(scope) == identifier->getValue(scope);

    if (isSatisfied) {
        body->run(scope);
        isMatched = true;
    }
    else {
        isMatched = false;
    }
}

void CaseNode::runSemanticChecker(Scope* scope) {
    body->runSemanticChecker(scope); 
}

void CaseNode::generateQuadruples(Scope* scope) {
    int skipLabel = quadruplesLabel++;

    int continueLabel = continueJumpTo.back();
    continueJumpTo.pop_back();
    
    if (condition != nullptr) {
        std::string target = condition->generateQuadruples();
        std::string cond = CompilerOrganizer::createQuadEntry(OP_EQ, varName, target);
        CompilerOrganizer::addQuadruple(QUAD_GOTO_IF_FALSE, cond, "", "L" + std::to_string(skipLabel));
    }
    
    CompilerOrganizer::addLabel(skipConditionLabel);

    body->generateQuadruples(scope);

    CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(continueLabel));

    CompilerOrganizer::addLabel(skipLabel);
}