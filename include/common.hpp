#pragma once
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class ScopeNode;
class Expression;

enum OperandType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TVOID, TUNDEFINED };

class Operand {
    public:
        void* content;
        OperandType type;

        Operand() { content = nullptr; type = TUNDEFINED; }
        Operand(OperandType type, void* content) { this->type = type; this->content = content; }

        static Operand undefined() { return Operand(TUNDEFINED, nullptr); }
        static Operand voidValue() { return Operand(TVOID, nullptr); }

        void init(const char* value, OperandType type) {
            this->type = type;
            if (value == nullptr) { return; }

            if (type == TSTRING) { 
                type = TSTRING;
                content = (void*) new std::string(value); 
            } else if (type != TVOID && type != TUNDEFINED) {
                content = malloc(typeToSize(type));
            }

            switch (type) {
                case TINT:
                    *(int*)content = atoi(value); break;
                case TFLOAT:
                    *(float*)content = atof(value); break;
                case TCHAR:
                    *(char*)content = value[0]; break;
                case TBOOLEAN:
                    *(int*)content = strcmp(value, "true") ? 0 : 1; break;
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
                case TVOID:
                    return "void";
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

        Operand operator+(int that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return Operand(TINT, (void*) new int((int) *(int*)content + that));
                case TFLOAT:
                    return Operand(TFLOAT, (void*) new float((float) *(float*)content + (float)that));
                case TSTRING:
                    return Operand(TSTRING, (void*) new std::string(*(std::string*)content + std::to_string(that)));
                default:
                    return Operand(TVOID, nullptr);
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
                    return (int) *(int*)content == (int)that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == std::to_string(that);
                default:
                    return false;
            }
        }

        bool operator==(const Operand& that) const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content == (int)that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == that.toString();
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

class FunctionParametersNode {
    public:
        std::vector<OperandType> types;
        std::vector<std::string> names;

        FunctionParametersNode() {}

        FunctionParametersNode( std::string type, std::string name ) {            
            this->names.push_back(name);
            if (type == "int")          this->types.push_back(TINT);
            else if (type == "float")   this->types.push_back(TFLOAT);
            else if (type == "char")    this->types.push_back(TCHAR);
            else if (type == "bool") this->types.push_back(TBOOLEAN);
            else if (type == "string")  this->types.push_back(TSTRING);
            else if (type == "void")    this->types.push_back(TVOID);
            else                        this->types.push_back(TUNDEFINED);
        }

        FunctionParametersNode* addParameter( std::string type, std::string name ) {
            this->names.push_back(name);

            if (type == "int")          this->types.push_back(TINT);
            else if (type == "float")   this->types.push_back(TFLOAT);
            else if (type == "char")    this->types.push_back(TCHAR);
            else if (type == "bool") this->types.push_back(TBOOLEAN);
            else if (type == "string")  this->types.push_back(TSTRING);
            else if (type == "void")    this->types.push_back(TVOID);
            else                        this->types.push_back(TUNDEFINED);

            return this;
        }
};


class FunctionCallParametersNode {
    public:
        std::vector<Expression*> params;
        FunctionCallParametersNode() {}
        FunctionCallParametersNode( Expression* param ) { 
            params.push_back(param);
        }   
        FunctionCallParametersNode* addParameter( Expression* param ) {
            params.push_back(param);
            return this;
        }
};

class Scope {
    private:
        Scope* parent = nullptr;

        std::unordered_map<std::string, std::pair<OperandType, Operand>> variables;

        std::unordered_map<std::string, std::tuple<OperandType, FunctionParametersNode*, ScopeNode*>> functions;
    public:
        Scope() { 
            this->parent = nullptr; 
            this->defineVariable("return", TUNDEFINED, Operand::undefined());
        }

        Scope(Scope* parent) { 
            this->parent = parent; 
            this->defineVariable("return", TUNDEFINED, Operand::undefined());
        }

        Scope* getParent() { return parent; }
        void setParent(Scope* parent) { this->parent = parent; }

        void defineVariable(std::string varName, OperandType type, Operand value) { 
            if (variables.find(varName) == variables.end()) {
                variables[varName] = {type, value}; 
            } else {
                throw std::runtime_error("Variable " + varName + " has already been declared");
            }
        }    

        void defineFunction( OperandType returnType, std::string functionName, FunctionParametersNode* parameters, ScopeNode* scope) {
            if (functions.find(functionName) == functions.end()) {
                functions[functionName] = std::make_tuple(returnType, parameters, scope);
            } else {
                throw std::runtime_error("Function " + functionName + " has already been declared");
            }
        }

        void reset() {
            variables.clear();
            this->defineVariable("return", TUNDEFINED, Operand::undefined());
        }

        void assignReturn(Operand value) {
            variables["return"] = {value.type, value};
        }

        void breakScope() { variables["break"] = { TUNDEFINED, Operand::undefined() }; }

        void contScope() { variables["continue"] = { TUNDEFINED, Operand::undefined() }; }

        bool returned() { return variables["return"].first != TUNDEFINED; }

        bool isBroke() { return variables.find("break") != variables.end(); }

        bool isContinued() { return variables.find("continue") != variables.end(); }

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

        ScopeNode* scopeOf(std::string functionName) {
            if (functions.find(functionName) != functions.end()) {
                ScopeNode* body = std::get<2>(functions[functionName]);
                return body;
            } else if (parent != nullptr) {
                return parent->scopeOf(functionName);
            } else {
                throw std::runtime_error("Function " + functionName + " not found");
                return nullptr;
            }
        }

        FunctionParametersNode* getFunctionParameters(std::string functionName) {
            if (functions.find(functionName) != functions.end()) {
                return std::get<1>(functions[functionName]);
            } else if (parent != nullptr) {
                return parent->getFunctionParameters(functionName);
            } else {
                throw std::runtime_error("Function " + functionName + " not found");
                return new FunctionParametersNode();
            }
        }

        OperandType getFunctionReturnType(std::string functionName) {
            if (functions.find(functionName) != functions.end()) {
                return std::get<0>(functions[functionName]);
            } else {
                return TUNDEFINED;
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