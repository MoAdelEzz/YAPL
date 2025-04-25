#include "loop.hpp"
#include "enums.hpp"
extern int scopeDepth;

// =========================================================================================
// ======================================== For Loop =======================================
// =========================================================================================

ForNode::ForNode( int line, DefineNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body ) : ProgramNode(line) {  
    this->preLoop = preLoop; 
    this->condition = condition; 
    this->postLoop = postLoop; 
    this->body = body; 
    this->logLineInfo();
}

ForNode::~ForNode() {
    if(preLoop) delete preLoop;
    if(condition) delete condition;
    if(postLoop) delete postLoop;
    if(body) delete body;
}

std::string ForNode::nodeName() { return "ForNode"; }

void ForNode::checkCondition(Scope* forScope) {
    if (condition == nullptr) {
        throw "Possible Infinite Loop";
    }

    OperandType type = TUNDEFINED;
    try {
        type = condition->getExpectedType(forScope);
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type > TSTRING) {
        throw "Something Wrong With The Operation inside the condition";
    }
}

bool ForNode::getLoopCondition(Scope* forScope) {
    bool loopCondition = false;
    try {
        loopCondition = condition != nullptr && condition->getValue(forScope) != 0;
    } catch(ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
        return false;
    }
    return loopCondition;
}

void ForNode::run(Scope* scope) {
    Scope* forScope = new Scope(scope);

    scopeDepth++;
        preLoop->run(forScope);
        forScope->defineBreak();
        forScope->defineContinue();
    scopeDepth--;

    while (getLoopCondition(forScope)) {
    
        body->run(forScope);

        postLoop->run(forScope);

        body->resetScope();

        if (forScope->hasBreak()) {
            break;
        }
    }

    delete forScope;
}

void ForNode::runSemanticChecker(Scope* scope) {
    Scope* forScope = new Scope(scope);
    body->haltLogging = true;

    scopeDepth++;

        CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeEntry());
        preLoop->runSemanticChecker(forScope);
        checkCondition(forScope);
        body->runSemanticChecker(forScope);
        postLoop->runSemanticChecker(forScope);

    scopeDepth--;
    
    CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeExit());

    delete forScope;
}

// =========================================================================================
// ======================================= While Loop ======================================
// =========================================================================================

WhileNode::WhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(line) {
    this->condition = condition; 
    this->body = body; 
    this->logLineInfo();        
}

WhileNode::~WhileNode() {
    if(condition) delete condition;
    if(body) delete body;
}

std::string WhileNode::nodeName() { return "WhileNode"; }

bool WhileNode::getLoopCondition(Scope* whileScope) {
    bool loopCondition = false;
    try {
        loopCondition = condition != nullptr && condition->getValue(whileScope) != 0;
    } catch(ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
        return false;
    }
    return loopCondition;
}

void WhileNode::checkCondition(Scope* whileScope) {
    if (condition == nullptr) {
        throw "Possible Infinite Loop";
    }
    OperandType type = TUNDEFINED;
    try {
        type = condition->getExpectedType(whileScope);
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type > TSTRING) {
        throw "Something Wrong With The Operation inside the condition";
    }
}

void WhileNode::run(Scope* scope) {
    body->getScope()->defineBreak();
    body->getScope()->defineContinue();

    while (getLoopCondition(scope)) {
        body->run(scope);

        body->resetScope();

        if (body->getScope()->hasBreak()) {
            break;
        }
    }
}

void WhileNode::runSemanticChecker(Scope* scope) {
    checkCondition(scope);
    body->runSemanticChecker(scope);
}


// ========================================================================================
// ===================================== Do While Loop ====================================
// ========================================================================================

DoWhileNode::DoWhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(line) {
    this->condition = condition; 
    this->body = body; 
    this->logLineInfo();
}

DoWhileNode::~DoWhileNode() {
    if(condition) delete condition;
    if(body) delete body;
}

std::string DoWhileNode::nodeName() { return "DoWhileNode"; }

bool DoWhileNode::getLoopCondition(Scope* whileScope) {
    bool loopCondition = false;
    try {
        loopCondition = condition != nullptr && condition->getValue(whileScope) != 0;
    } catch(ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
        return false;
    }
    return loopCondition;
}

void DoWhileNode::checkCondition(Scope* doWhileScope) {
    if (condition == nullptr) {
        throw "Possible Infinite Loop";
    }
    OperandType type = TUNDEFINED;
    try {
        type = condition->getExpectedType(doWhileScope);
    } catch (ErrorDetail error) {
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (type > TSTRING) {
        throw "Something Wrong With The Operation inside the condition";
    }
}

void DoWhileNode::runSemanticChecker(Scope* scope) {
    checkCondition(scope);
    body->runSemanticChecker(scope);
}


void DoWhileNode::run(Scope* scope) {
    do {
        body->run(scope);
        body->resetScope();

        if (body->getScope()->hasBreak()) {
            break;
        }
    } while ( getLoopCondition(scope) );
}
