#pragma once
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class ScopeNode;
class Expression;

enum OperandType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TVOID, TUNDEFINED };

class DataType {
    public:
        OperandType type;
        bool isConst;
        DataType(std::string type, bool isConst = false) 
        { 
            if (type == "int") { this->type = TINT; }
            else if (type == "float") { this->type = TFLOAT; }
            else if (type == "char") { this->type = TCHAR; }
            else if (type == "string") { this->type = TSTRING; }
            else if (type == "bool") { this->type = TBOOLEAN; }
            else if (type == "void") { this->type = TVOID; }
            else this->type = TUNDEFINED;
            this->isConst = isConst;
        }

        DataType(OperandType type) {
            this->type = type;
            isConst = false;
        }

        static DataType* Undefined()    { return new DataType("undef", false); }
        static DataType* Void()         { return new DataType("void", false); }
        static DataType* Int()          { return new DataType("int", false); }
        static DataType* Float()        { return new DataType("float", false); }
        static DataType* Char()         { return new DataType("char", false); }
        static DataType* String()         { return new DataType("string", false); }
        static DataType* Bool()         { return new DataType("bool", false); }


};

class Operand {
    public:
        void* content;
        DataType* dataType;

        Operand() { content = nullptr; dataType = DataType::Undefined(); }
        Operand(DataType* type, void* content) { this->dataType = type; this->content = content; }

        static Operand undefined() { return Operand(); }
        static Operand voidValue() { return Operand(DataType::Void(), nullptr); }

        void init(const char* value, DataType* dataType) {
            this->dataType = dataType;
            if (value == nullptr) { return; }

            if (dataType->type == TSTRING) { 
                dataType->type = TSTRING;
                content = (void*) new std::string(value); 
            } else if (dataType->type != TVOID && dataType->type != TUNDEFINED) {
                content = malloc(typeToSize(dataType->type));
            }

            switch (dataType->type) {
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
            switch (dataType->type) {
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
            switch (dataType->type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content;
                case TFLOAT:
                    return (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator float() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (float) *(int*)content;
                case TFLOAT:
                    return (float) *(float*)content;
                default:
                    return 0;
            }
        }

        operator char() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (char) (int) *(int*)content;
                case TFLOAT:
                    return (char) (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator bool() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return *(int*)content != 0;
                case TFLOAT:
                    return *(float*)content != 0;
                default:
                    return 0;
            }
        }

        Operand operator+(int that) const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return Operand(DataType::Int(), (void*) new int((int) *(int*)content + that));
                case TFLOAT:
                    return Operand(DataType::Float(), (void*) new float((float) *(float*)content + (float)that));
                case TSTRING:
                    return Operand(DataType::String(), (void*) new std::string(*(std::string*)content + std::to_string(that)));
                default:
                    return Operand(DataType::Float(), nullptr);
            }
        }

        template<typename T>
        bool operator>(const T& that) const {
            switch (dataType->type) {
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
            switch (dataType->type) {
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
            switch (dataType->type) {
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
            switch (dataType->type) {
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
            switch (node.dataType->type) {
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
                    throw std::runtime_error("Unexpected Type Found While Printing");
            }
            return os;
        }
};

class FunctionParametersNode {
    public:
        std::vector<DataType*> types;
        std::vector<std::string> names;

        FunctionParametersNode() {}

        FunctionParametersNode( DataType* type, std::string name ) {            
            this->names.push_back(name);
            this->types.push_back(type);
        }

        FunctionParametersNode* addParameter( DataType* type, std::string name ) {
            this->names.push_back(name);
            this->types.push_back(type);
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

        std::unordered_map<std::string, std::pair<DataType*, Operand>> variables;

        std::unordered_map<std::string, std::tuple<DataType*, FunctionParametersNode*, ScopeNode*>> functions;
    public:
        Scope() { 
            this->parent = nullptr; 
            this->defineVariable("return", DataType::Undefined(), Operand::undefined());
        }

        Scope(Scope* parent) { 
            this->parent = parent; 
            this->defineVariable("return", DataType::Undefined(), Operand::undefined());
        }

        Scope* getParent() { return parent; }
        void setParent(Scope* parent) { this->parent = parent; }

        void defineVariable(std::string varName, DataType* type, Operand value) { 
            if (variables.find(varName) == variables.end()) {
                variables[varName] = {type, value}; 
            } else {
                throw std::runtime_error("Variable " + varName + " has already been declared");
            }
        }    

        void defineFunction( DataType* returnType, std::string functionName, FunctionParametersNode* parameters, ScopeNode* scope) {
            if (functions.find(functionName) == functions.end()) {
                functions[functionName] = std::make_tuple(returnType, parameters, scope);
            } else {
                throw std::runtime_error("Function " + functionName + " has already been declared");
            }
        }

        void reset() {
            variables.clear();
            this->defineVariable("return", DataType::Undefined(), Operand::undefined());
        }

        void assignReturn(Operand value) {
            variables["return"] = {value.dataType, value};
        }

        void breakScope() { variables["break"] = { DataType::Undefined(), Operand::undefined() }; }

        void contScope() { variables["continue"] = { DataType::Undefined(), Operand::undefined() }; }

        bool returned() { return variables["return"].first->type != TUNDEFINED; }

        bool isBroke() { return variables.find("break") != variables.end(); }

        bool isContinued() { return variables.find("continue") != variables.end(); }

        void assignVariable(std::string varName, Operand value) {
            const auto& it = variables.find(varName);
            if (it != variables.end()) {
                //TODO: change this later
                if (variables[varName].first->type != value.dataType->type) throw std::runtime_error("Variable " + varName + " type mismatch");
                else if (variables[varName].first->isConst) throw std::runtime_error("Variable " + varName + " is constant and cannot be assigned");
                else variables[varName].second = value;
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
                return std::get<0>(functions[functionName])->type;
            } else {
                return TUNDEFINED;
            }
        }

        OperandType typeOf(std::string varName) {
            if (variables.find(varName) != variables.end()) {
                return variables[varName].first->type;
            } else if (parent != nullptr) {
                return parent->typeOf(varName);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
                return TINT;
            }
        }
};