#pragma once
#include "enums.hpp"
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
        
        void generateQuadruples(Scope* scope) override {
            CompilerOrganizer::addQuadruple(QUAD_DECLARE, Utils::typeToString(type->type), "", name);

            if (value != nullptr) {
                std::string result = value->generateQuadruples();
                CompilerOrganizer::addQuadruple(QUAD_ASSIGN, result, "", name);
            }
        }
        

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            try {
                OperandType rhsType = TUNDEFINED;
                bool errornousRHS = false;

                if (value) {
                    try {
                        rhsType = value->getExpectedType(scope);
                    } catch(ErrorDetail error) {
                        error.setLine(this->line);
                        CompilerOrganizer::addError(error);
                        errornousRHS = true;
                    }
                }

                if ( !errornousRHS && value != nullptr && !Utils::isValidAssignment(type->type, rhsType)) {
                    ErrorDetail error(Severity::ERROR, "Type Mismatch For The Variable " + name);
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                } 
                
                scope->defineVariable(name, type, Operand::undefined(), true);

                if ( !errornousRHS && value != nullptr && value->getExpectedType(scope) < TVOID) {
                    CompilerOrganizer::markSymbolAsInitialized(name);
                    scope->assignVariableValueType(name, type->type);
                }
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
                scope->defineVariable(name, type, op, false);
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
    Operand nodeValue;
    std::string quadResult = "";
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

        Operand getValue() { return nodeValue; }
        OperandType getType(Scope* scope) { return name.size() == 0 ? value->getExpectedType(scope) : scope->typeOf(name); }
        std::string varName() {return quadResult;}
        
        ProgramNode* setNextAssignment(ProgramNode* nextAssign) { 
            if (this->nextAssign) {
                this->nextAssign->setNext(nextAssign);
            } else {
                this->nextAssign = nextAssign;
            } 
            return this;
        }

        void generateQuadruples(Scope* scope) override {
            std::string result = value->generateQuadruples();
            quadResult = result;
            if (name.size() > 0) // not a hanging operation
            {
                CompilerOrganizer::addQuadruple(QUAD_ASSIGN, result, "", name);
                quadResult = name;
            }
        }
        
        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            const bool validLHS = name.size() == 0 || scope->typeOf(name) != TUNDEFINED;
            bool errornous = false;

            if ( ! validLHS ) {
                ErrorDetail error(Severity::ERROR, "Variable " + name + " is not defined");
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                errornous = true;
            }

            if ( !errornous && name.size() > 0 && scope->isConstVariable(name)) {
                ErrorDetail error(Severity::ERROR, "Variable " + name + " is constant and cannot be assigned");
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                errornous = true;
            }

            OperandType nodeType = TUNDEFINED;
            try {
                nodeType = value->getExpectedType(scope);
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
            
            if ( !errornous && validLHS && name.size() > 0 && !Utils::isValidAssignment(scope->typeOf(name), nodeType) ) { 
                ErrorDetail error(Severity::ERROR, "Type Mismatch For The Variable " + name);
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                errornous = true;
            }

            if (!errornous && name != "") {
                try {
                    scope->assignVariableValueType(name, nodeType);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    errornous = true;
                }
                CompilerOrganizer::markSymbolAsInitialized(name);
            }

            if (nextAssign) { nextAssign->run(scope); }
        }

        void run(Scope* scope = nullptr) override {
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
