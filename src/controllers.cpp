#include "controllers.hpp" 
#include <vector>

extern std::vector<int> breakJumpTo;
extern std::vector<int> continueJumpTo;

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

void ContinueNode::generateQuadruples(Scope* scope) {
    int to = continueJumpTo.back();
    continueJumpTo.pop_back();
    CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(to));
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

void BreakNode::generateQuadruples(Scope* scope) {
    int to = breakJumpTo.back();
    breakJumpTo.pop_back();
    CompilerOrganizer::addQuadruple(QUAD_GOTO, "", "", "L" + std::to_string(to));
}

