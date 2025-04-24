#include "branching.hpp"

// =========================================================================================
// ======================================== IF NODE ========================================
// =========================================================================================

IfNode::IfNode( int line, Expression* condition, ProgramNode* accept ) : ProgramNode(line) {
    this->condition = condition;
    this->accept = accept;
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

void IfNode::runSemanticChecker(Scope* scope) {
    if (condition->getExpectedType(scope) == TUNDEFINED) {
        ErrorDetail error(Severity::ERROR, "Ivalid Expression For The If Condition");
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    } 

    if (accept)
        accept->runSemanticChecker(scope);
    if (reject)
        reject->runSemanticChecker(scope);
}

void IfNode::run(Scope* scope) {
    if (condition->getValue(scope) != 0) {
        accept->run(scope);
    } else if (reject) {
        reject->run(scope);
    }
}

// =========================================================================================
// ====================================== Switch Node ======================================
// =========================================================================================

std::string SwitchNode::nodeName() { return "SwitchNode"; }

SwitchNode::SwitchNode( int line, std::string id, SwitchBody* body ) : ProgramNode(line) { 
    this->body = body;
    this->identifier = new IdentifierContainer(id);
    this->logLineInfo();
}

void SwitchNode::runSemanticChecker(Scope* scope) {
    ScopeNode* switchScope = new ScopeNode(-1, scope);
    switchScope->getScope()->defineBreak();

    if (body) {
        bool caseMatched = false;
        for (CaseNode* caseNode : body->getCases()) {
            caseNode->runSemanticChecker(switchScope->getScope());
        }
    }

    delete switchScope;
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

std::vector<CaseNode*> SwitchBody::getCases() { 
    return cases; 
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

