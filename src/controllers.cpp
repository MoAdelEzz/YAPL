#include "controllers.hpp" 

// =========================================================================================
// ======================================= Continue ========================================
// =========================================================================================

ContinueNode::ContinueNode(int line) : ProgramNode(line) {
    this->logLineInfo();
}

std::string ContinueNode::nodeName() {
    return "ContinueNode";
}

void ContinueNode::run(Scope* scope) {
    scope->assignContinue();
}

void ContinueNode::runSemanticChecker(Scope* scope) {
    if(!scope->canContinue()) {
        ErrorDetail error(Severity::ERROR, "Continue Statement Not Allowed Here");
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }
}

// =========================================================================================
// ========================================= Break =========================================
// =========================================================================================

BreakNode::BreakNode(int line) : ProgramNode(line) {
    this->logLineInfo();
}

std::string BreakNode::nodeName() {
    return "BreakNode";
}

void BreakNode::run(Scope* scope) {
    scope->assignBreak();
}

void BreakNode::runSemanticChecker(Scope* scope) {
    if(!scope->canBreak()) {
        ErrorDetail error(Severity::ERROR, "Break Statement Not Allowed Here");
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }
}


