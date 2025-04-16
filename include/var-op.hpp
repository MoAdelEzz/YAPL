#pragma once
#include "common.hpp"
#include "program.hpp"
#include "expression.hpp"

class DefineNode : public ProgramNode {
    DataType* type;
    Expression* value;
    std::string name;
    DefineNode* nextDefine = nullptr;


    public:
        DefineNode( DataType* type, std::string name, Expression* value) {            
            this->name = name;
            this->value = value;
            this->type = type;
        }

        DefineNode( std::string name, Expression* value) {
            this->name = name;
            this->value = value;
            this->type = DataType::Undefined();
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


        void run(Scope* scope = nullptr) override {
            scope->defineVariable(name, type, value->getValue(scope));
            if (nextDefine) { nextDefine->run(scope); }
        }

        std::string nodeName() override {
            return "DefineNode";
        }
};

class AssignNode: public ProgramNode {
    Expression* value;
    std::string name;

    ProgramNode* nextAssign;
    
    public:
        AssignNode( std::string name, Expression* value) {   
            this->name = name;
            this->value = value;
            this->setNext(nullptr);
        }

        ProgramNode* setNextAssignment(ProgramNode* nextAssign) { 
            if (this->nextAssign) {
                this->nextAssign->setNext(nextAssign);
            } else {
                this->nextAssign = nextAssign;
            } 
            return this;
        }

        void run(Scope* scope = nullptr) {
            if (name.size() == 0) {
                value->getValue(scope);
            } else {
                scope->assignVariable(name,  value->getValue(scope));
            }

            if (nextAssign) { nextAssign->run(scope); }
            // std::cout << "Assigning " << name << " = " << scope->valueOf(name) << std::endl;
        }
};
