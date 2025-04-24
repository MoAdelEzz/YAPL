#pragma once
#include "organizer.hpp"
#include "common.hpp"
#include "program.hpp"
#include "expression.hpp"

class DefineNode : public ProgramNode {
    DataType* type;
    Expression* value;
    std::string name;
    DefineNode* nextDefine = nullptr;


    public:
        std::string nodeName() override {
            return "DefineNode";
        }

        DefineNode( int line, DataType* type, std::string name, Expression* value) 
        : ProgramNode(line),
          name(name),
          value(value),
          type(type)
        {            
            this->logLineInfo();
        }

        DefineNode( int line, std::string name, Expression* value ) 
        : ProgramNode(line),
          name(name),
          value(value),
          type(DataType::Undefined())
        {            
            this->logLineInfo();
        }

        
        ~DefineNode() {
            if (nextDefine) delete nextDefine;
            if (value) delete value;
            if (type) delete type;
        }

        void setType(DataType* t) { type = t; }

        ProgramNode* setNextDefine(DefineNode* next) { 
            next->setType(type);

            if (this->nextDefine) {
                this->nextDefine->setNextDefine(next);
            } else {
                this->nextDefine = next;
            } 

            return this;
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            try {
                Operand op = value ? value->getValue(scope) : Operand::undefined();
                scope->defineVariable(name, type,  op);
            } 
            catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (nextDefine) { nextDefine->run(scope); }
        }

        void run(Scope* scope = nullptr) override {
            try {
                Operand op = value ? value->getValue(scope) : Operand::undefined();
                scope->defineVariable(name, type, op);
            } 
            catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (nextDefine) { nextDefine->run(scope); }
        }
};

class AssignNode: public ProgramNode {
    Expression* value;
    std::string name;

    ProgramNode* nextAssign;
    
    public:
        std::string nodeName() override { return "AssignNode"; }

        AssignNode( int line, std::string name, Expression* value ) 
        : ProgramNode(line),
          name(name),
          value(value)
        {            
            this->setNext(nullptr);
            this->logLineInfo();
        }

        ~AssignNode() {
            if (nextAssign) delete nextAssign;
            if (value) delete value;
        }
        
        ProgramNode* setNextAssignment(ProgramNode* nextAssign) { 
            if (this->nextAssign) {
                this->nextAssign->setNext(nextAssign);
            } else {
                this->nextAssign = nextAssign;
            } 
            return this;
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            const bool validLHS = name.size() == 0 || scope->typeOf(name) != TUNDEFINED;
            if ( ! validLHS ) {
                ErrorDetail error(Severity::ERROR, "Variable " + name + " is not defined");
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            OperandType nodeType = TUNDEFINED;
            try {
                nodeType = value->getExpectedType(scope);
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
            
            if ( validLHS && name.size() > 0 && !Utils::isValidAssignment(scope->typeOf(name), nodeType) ) { 
                ErrorDetail error(Severity::ERROR, "Type Mismatch For The Variable " + name);
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (name != "")
                CompilerOrganizer::markSymbolAsInitialized(name);

            if (nextAssign) { nextAssign->run(scope); }
        }

        void run(Scope* scope = nullptr) override {
            Operand nodeValue;
            try {
                nodeValue = value->getValue(scope);
            }
            catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            try {            
                if (name.size() > 0) {
                    scope->assignVariable(name,  nodeValue);
                }
            }
            catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (nextAssign) { nextAssign->run(scope); }
        }
};
