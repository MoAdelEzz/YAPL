#include "loop.hpp"
#include "enums.hpp"
#include "organizer.hpp"
#include "var-op.hpp"
extern int scopeDepth;
extern int quadruplesLabel;

extern std::vector<int> breakJumpTo;
extern std::vector<int> continueJumpTo;
// =========================================================================================
// ======================================== For Loop =======================================
// =========================================================================================

ForNode::ForNode( int line, ProgramNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body, bool inverted ) : ProgramNode(line) {  
    this->preLoop = preLoop; 
    this->condition = condition; 
    this->postLoop = postLoop; 
    this->body = body; 
    this->inverted = inverted;
    this->logLineInfo();
}

ForNode::ForNode( int line, ProgramNode* preLoop, AssignNode* assignment, ProgramNode* postLoop, ScopeNode* body ) : ProgramNode(line) {
    this->preLoop = preLoop; 
    this->assignment = assignment; 
    this->postLoop = postLoop; 
    this->body = body; 
    this->logLineInfo();
}

ForNode::~ForNode() {
    if(preLoop) delete preLoop;
    if(assignment) delete assignment;
    if(condition) delete condition;
    if(postLoop) delete postLoop;
    if(body) delete body;
}

std::string ForNode::nodeName() { return "ForNode"; }

void ForNode::checkCondition(Scope* forScope) {
    if (condition == nullptr && assignment == nullptr) {
        ErrorDetail error(Severity::WARNING, "Possible Infinite Loop", "", this->line);
        CompilerOrganizer::addError(error);
        return;
    }

    OperandType type = TUNDEFINED;

    if (condition) {
        try {
            type = condition->getExpectedType(forScope);
        } catch (ErrorDetail error) {
            error.setLine(this->line);
            CompilerOrganizer::addError(error);
        }
    } else {
        OperandType type = TUNDEFINED;
        try {
            assignment->runSemanticChecker(forScope);
            type = assignment->getType(forScope);
        } catch (ErrorDetail error) {
            error.setLine(this->line);
            CompilerOrganizer::addError(error);
        }
    }

    if (type > TSTRING) {
        ErrorDetail error(Severity::WARNING, "Something Wrong With The Operation inside the condition", "", this->line);
        CompilerOrganizer::addError(error);
    }
}

bool ForNode::getLoopCondition(Scope* forScope) {
    if (condition == nullptr && assignment == nullptr) {
        return true;
    }
    
    bool loopCondition = false;
    if (condition) {
        loopCondition = condition->getValue(forScope) != inverted;
    } else {
        assignment->run(forScope);
        loopCondition = assignment->getValue() != inverted;
    }

    return loopCondition;
}

void ForNode::run(Scope* scope) {
    Scope* forScope = new Scope(scope);

    scopeDepth++;
        if(preLoop) preLoop->run(forScope);
        forScope->defineBreak();
        forScope->defineContinue();
    scopeDepth--;

    while (getLoopCondition(forScope)) {
    
        if(body) body->run(forScope);

        if(postLoop) postLoop->run(forScope);

        if(body) body->resetScope();

        if (forScope->hasContinued()) {
            // disable this continue for the next iteration
            forScope->assignContinue(true);
        }

        if (forScope->hasBreak()) {
            break;
        }
    }

    delete forScope;
}

void ForNode::runSemanticChecker(Scope* scope) {
    Scope* forScope = new Scope(scope);
    forScope->defineBreak();
    forScope->defineContinue();
    if(body) body->haltLogging = true;

    scopeDepth++;
        CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeEntry());
        if(preLoop) preLoop->runSemanticChecker(forScope);
        checkCondition(forScope);
        if(body) body->runSemanticChecker(forScope);
        if(postLoop) postLoop->runSemanticChecker(forScope);

    scopeDepth--;
    
    CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeExit());

    delete forScope;
}

void ForNode::generateQuadruples(Scope* scope) {
    int loopBodyLabel = quadruplesLabel++;
    int loopConditionLabel = quadruplesLabel++;
    int breakLabel = quadruplesLabel++;

    breakJumpTo.push_back(breakLabel);
    continueJumpTo.push_back(loopConditionLabel);

    if (preLoop) preLoop->generateQuadruples(scope);
    CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(loopConditionLabel));

    CompilerOrganizer::addLabel(loopBodyLabel);
        if (body) body->generateQuadruples(scope);
        if(postLoop) postLoop->generateQuadruples(scope);

    std::string bodyLabelStr = "L" + std::to_string(loopBodyLabel);
    OperationType jumpIf = inverted ? QUAD_GOTO_IF_FALSE : QUAD_GOTO_IF_TRUE;

    CompilerOrganizer::addLabel(loopConditionLabel);
        if (condition == nullptr && assignment == nullptr) {
            CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", bodyLabelStr);
        } else if (condition) {
            std::string condition = this->condition->generateQuadruples();
            CompilerOrganizer::addQuadruple(jumpIf, condition, "", bodyLabelStr);
        } else {
            assignment->generateQuadruples(scope);
            CompilerOrganizer::addQuadruple(jumpIf, assignment->varName(), "" , bodyLabelStr);
        }

    CompilerOrganizer::addLabel(breakLabel);

    if (breakJumpTo.back() == breakLabel) breakJumpTo.pop_back();
    if (continueJumpTo.back() == loopConditionLabel) continueJumpTo.pop_back();
}   

// =========================================================================================
// ======================================= While Loop ======================================
// =========================================================================================

WhileNode::WhileNode( int line, Expression* condition, ScopeNode* body, bool inverted ) : ProgramNode(line) {
    this->condition = condition; 
    this->body = body; 
    this->logLineInfo();        
    this->inverted = inverted;
}

WhileNode::WhileNode( int line, AssignNode* assignment, ScopeNode* body ) : ProgramNode(line) {
    this->assignment = assignment; 
    this->body = body; 
    this->logLineInfo();
}

WhileNode::~WhileNode() {
    if(condition) delete condition;
    if(body) delete body;
}

std::string WhileNode::nodeName() { return "WhileNode"; }

bool WhileNode::getLoopCondition(Scope* whileScope) {
    if (condition == nullptr && assignment == nullptr) {
        return true;
    } else if (condition) {
        return condition->getValue(whileScope) != inverted;
    } else {
        assignment->run(whileScope);
        return assignment->getValue() != inverted;
    } 
}

void WhileNode::checkCondition(Scope* whileScope) {
    if (condition == nullptr && assignment == nullptr) {
        ErrorDetail error(Severity::WARNING, "Possible Infinite Loop", "", this->line);
        CompilerOrganizer::addError(error);
        return;
    } 
    
    OperandType type = TUNDEFINED;
    
    try {
        if (condition) {
            type = condition->getExpectedType(whileScope); 
        } else {
            assignment->runSemanticChecker(whileScope);
            type = assignment->getType(whileScope);
        }
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type > TSTRING) {
        ErrorDetail error(Severity::ERROR, "Something Wrong With The Operation inside the condition", "", this->line);
        CompilerOrganizer::addError(error);
    }
}

void WhileNode::run(Scope* scope) {
    Scope* whileScope = new Scope(scope);
    whileScope->defineBreak();
    whileScope->defineContinue();

    while (getLoopCondition(whileScope)) {
        body->run(whileScope);

        body->resetScope();

        if (whileScope->hasContinued()) {
            // disable this continue for the next iteration
            whileScope->assignContinue(true);
        }

        if (whileScope->hasBreak()) {
            break;
        }
    }

    delete whileScope;
}

void WhileNode::runSemanticChecker(Scope* scope) {
    Scope* whileScope = new Scope(scope);
    whileScope->defineBreak();
    whileScope->defineContinue();

    checkCondition(whileScope);
    body->runSemanticChecker(whileScope);

    delete whileScope;
}

void WhileNode::generateQuadruples(Scope* scope) {
    int loopBodyLabel = quadruplesLabel++;
    int loopConditionLabel = quadruplesLabel++;
    int breakLabel = quadruplesLabel++;

    breakJumpTo.push_back(breakLabel);
    continueJumpTo.push_back(loopConditionLabel);

    CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(loopConditionLabel));

    CompilerOrganizer::addLabel(loopBodyLabel);
        body->generateQuadruples(scope);

    std::string bodyLabelStr = "L" + std::to_string(loopBodyLabel);
    OperationType jumpIf = inverted ? QUAD_GOTO_IF_FALSE : QUAD_GOTO_IF_TRUE;

    CompilerOrganizer::addLabel(loopConditionLabel);
        if (condition == nullptr && assignment == nullptr) {
            CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", bodyLabelStr);
        } else if (condition == nullptr) {
            assignment->generateQuadruples(scope);
            CompilerOrganizer::addQuadruple(jumpIf, assignment->varName(), "" , bodyLabelStr);
        } else {
            std::string condition = this->condition->generateQuadruples();
            CompilerOrganizer::addQuadruple(jumpIf, condition, "", bodyLabelStr);
        }

    CompilerOrganizer::addLabel(breakLabel);

    if (breakJumpTo.back() == breakLabel) breakJumpTo.pop_back();
    if (continueJumpTo.back() == loopConditionLabel) continueJumpTo.pop_back();
}

// ========================================================================================
// ===================================== Do While Loop ====================================
// ========================================================================================

DoWhileNode::DoWhileNode( int line, Expression* condition, ScopeNode* body, bool inverted ) : ProgramNode(line) {
    this->condition = condition; 
    this->body = body; 
    this->inverted = inverted;
    this->logLineInfo();
}

DoWhileNode::DoWhileNode(int line, AssignNode* assignment, ScopeNode* body ) : ProgramNode(line) {
    this->assignment = assignment; 
    this->body = body; 
    this->logLineInfo();
}

DoWhileNode::~DoWhileNode() {
    if(condition) delete condition;
    if(assignment) delete assignment;
    if(body) delete body;
}

std::string DoWhileNode::nodeName() { return "DoWhileNode"; }

bool DoWhileNode::getLoopCondition(Scope* whileScope) {
    if (condition == nullptr && assignment == nullptr) {
        return true;
    } else if (condition) {
        return condition->getValue(whileScope) != inverted;
    } else {
        assignment->run(whileScope);
        return assignment->getValue() != inverted;
    }
}

void DoWhileNode::checkCondition(Scope* doWhileScope) {
    if (condition == nullptr && assignment == nullptr) {
        ErrorDetail error(Severity::WARNING, "Possible Infinite Loop", "", this->line);
        CompilerOrganizer::addError(error);
        return;
    }
    OperandType type = TUNDEFINED;
    try {
        if (condition) {
            type = condition->getExpectedType(doWhileScope);
        } else {
            assignment->runSemanticChecker(doWhileScope);
            type = assignment->getType(doWhileScope);
        }
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type > TSTRING) {
        ErrorDetail error(Severity::ERROR, "Something Wrong With The Operation inside the condition", "", this->line);
        CompilerOrganizer::addError(error);
    }
}

void DoWhileNode::runSemanticChecker(Scope* scope) {
    Scope* doWhileScope = new Scope(scope);
    doWhileScope->defineBreak();
    doWhileScope->defineContinue();

    checkCondition(doWhileScope);
    body->runSemanticChecker(doWhileScope);

    delete doWhileScope;
}

void DoWhileNode::run(Scope* scope) {
    Scope* doWhileScope = new Scope(scope);
    doWhileScope->defineBreak();
    doWhileScope->defineContinue();

    do {
        body->run(doWhileScope);
        body->resetScope();
                
        if (doWhileScope->hasContinued()) {
            // disable this continue for the next iteration
            doWhileScope->assignContinue(true);
        }

        if (doWhileScope->hasBreak()) {
            break;
        }

    } while ( getLoopCondition(doWhileScope) );

    delete doWhileScope;
}

void DoWhileNode::generateQuadruples(Scope* scope) {
    int loopBodyLabel = quadruplesLabel++;
    int breakLabel = quadruplesLabel++;

    breakJumpTo.push_back(breakLabel);
    continueJumpTo.push_back(loopBodyLabel);

    CompilerOrganizer::addLabel(loopBodyLabel);
        body->generateQuadruples(scope);

    std::string bodyLabelStr = "L" + std::to_string(loopBodyLabel);
    OperationType jumpIf = inverted ? QUAD_GOTO_IF_FALSE : QUAD_GOTO_IF_TRUE;

    if (condition == nullptr && assignment == nullptr) {
        CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", bodyLabelStr);
    } else if (condition) {
        std::string condition = this->condition->generateQuadruples();
        CompilerOrganizer::addQuadruple(jumpIf, condition, "", "L" + std::to_string(loopBodyLabel));
    } else {
        assignment->generateQuadruples(scope);
        CompilerOrganizer::addQuadruple(jumpIf, assignment->varName(), "", "L" + std::to_string(loopBodyLabel));
    }

    CompilerOrganizer::addLabel(breakLabel);

    if (breakJumpTo.back() == breakLabel) breakJumpTo.pop_back();
    if (continueJumpTo.back() == loopBodyLabel) continueJumpTo.pop_back();   
}