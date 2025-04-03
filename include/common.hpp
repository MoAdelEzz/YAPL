#pragma once
#include <iostream>
#include <string>
#include <unordered_map>

enum OperandType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TUNDEFINED };

class Operand {
    public:
        void* content;
        OperandType type;

        void init(const char* value, OperandType type) {
            this->type = type;
            if (value == nullptr) { return; }

            if (type == TSTRING) { 
                type = TSTRING;
                content = (void*) new std::string(value); 
                return;
            }

            content = malloc(typeToSize(type));
            switch (type) {
                case TINT:
                    *(int*)content = atoi(value); break;
                case TFLOAT:
                    *(float*)content = atof(value); break;
                case TCHAR:
                    *(char*)content = value[0]; break;
                default: break;
            }
        }
        
        static std::string typeToString(OperandType type) {
            switch (type) {
                case TINT:
                    return "int";
                case TFLOAT:
                    return "float";
                case TCHAR:
                    return "char";
                case TBOOLEAN:
                    return "boolean";
                case TSTRING:
                    return "string";
                default:
                    return "undefined";
            }
        }
        
        static int typeToSize(OperandType type) {
            switch (type) {
                case TINT:
                    return sizeof(int);
                case TFLOAT:
                    return sizeof(float);
                case TCHAR:
                    return sizeof(int);
                case TBOOLEAN:
                    return sizeof(int);
                default:
                    return 0;
            }
        }

        std::string toString() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return std::to_string((int) *(int*)content);
                case TFLOAT:
                    return std::to_string((float) *(float*)content);
                case TSTRING:
                    return *(std::string*)content;
                default:
                    return "undefined";
            }
        }

        operator int() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content;
                case TFLOAT:
                    return (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator float() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (float) *(int*)content;
                case TFLOAT:
                    return (float) *(float*)content;
                default:
                    return 0;
            }
        }

        operator char() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (char) (int) *(int*)content;
                case TFLOAT:
                    return (char) (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator bool() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return *(int*)content != 0;
                case TFLOAT:
                    return *(float*)content != 0;
                default:
                    return 0;
            }
        }

        template<typename T>
        bool operator>(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content > that;
                case TFLOAT:
                    return (float) *(float*)content > (float)that;
                case TSTRING:
                    return *(std::string*)content > std::to_string(that);
                default:
                    return 0;
            }
        }

        template<typename T>
        bool operator==(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content == that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == std::to_string(that);
                default:
                    return false;
            }
        }

        template<typename T>
        bool operator!=(const T& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content != that;
                case TFLOAT:
                    return (float) *(float*)content != (float)that;
                case TSTRING:
                    return *(std::string*)content != std::to_string(that);
                default:
                    return true;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Operand& node) {
            switch (node.type) {
                case TINT:
                    os << (int)node;
                    break;
                case TFLOAT:
                    os << (float)node;
                    break;
                case TCHAR:
                    os << (char)node;
                    break;
                case TBOOLEAN:
                    os << (bool)node;
                    break;
                case TSTRING:
                    os << *(std::string*)node.content;
                    break;
                default:
                    throw("WTF Bro");
            }
            return os;
        }
};

class Scope {
    private:
        Scope* parent = nullptr;
        std::unordered_map<std::string, std::pair<OperandType, Operand>> variables;
    public:
        Scope() { this->parent = nullptr; }
        Scope(Scope* parent) { this->parent = parent; }
        Scope* getParent() { return parent; }
        void setParent(Scope* parent) { this->parent = parent; }

        void defineVariable(std::string varName, OperandType type, Operand value) { 
            if (variables.find(varName) == variables.end()) {
                variables[varName] = {type, value}; 
            } else {
                throw std::runtime_error("Variable " + varName + " has already been declared");
            }
        }    

        void reset() {
            variables.clear();
        }

        void assignVariable(std::string varName, Operand value) {
            const auto& it = variables.find(varName);
            if (it != variables.end()) {
                //TODO: change this later
                if (variables[varName].first == value.type) {
                    variables[varName].second = value;
                } else {
                    throw std::runtime_error("Variable " + varName + " type mismatch");
                }
                
            } else if (parent != nullptr) {
                parent->assignVariable(varName, value);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
            }
        }
        
        Operand valueOf(std::string varName) { 
            if (variables.find(varName) != variables.end()) {
                return variables[varName].second;
            }  else if (parent != nullptr) {
                return parent->valueOf(varName);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
                return Operand();
            }
        }

        OperandType typeOf(std::string varName) {
            if (variables.find(varName) != variables.end()) {
                return variables[varName].first;
            } else if (parent != nullptr) {
                return parent->typeOf(varName);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
                return TINT;
            }
        }
};