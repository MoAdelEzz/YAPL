#pragma once
#include "common.hpp"
#include "program.hpp"
#include "expression.hpp"

class DefineNode : public ProgramNode {
    Expression* value;
    std::string name;
    OperandType type;
    
    public:
        DefineNode( std::string type, std::string name, Expression* value) {            
            this->name = name;
            this->value = value;
            if (type == "int") { this->type = TINT; }
            else if (type == "float") { this->type = TFLOAT; }
            else if (type == "char") { this->type = TCHAR; }
            else if (type == "string") { this->type = TSTRING; }
            else if (type == "bool") { this->type = TBOOLEAN; }
            else if (type == "void") { this->type = TVOID; }
        }

        void run(Scope* scope = nullptr) {
            scope->defineVariable(name, type, value->getValue(scope));
        }
};

class AssignNode: public ProgramNode {
    Expression* value;
    std::string name;
    
    public:
        AssignNode( std::string name, Expression* value ) {            
            this->name = name;
            this->value = value;
            this->setNext(nullptr);
        }

        void run(Scope* scope = nullptr) {
            scope->assignVariable(name,  value->getValue(scope));
            // std::cout << "Assigning " << name << " = " << scope->valueOf(name) << std::endl;
        }
};
