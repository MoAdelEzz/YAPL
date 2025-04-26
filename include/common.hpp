#pragma once
#include "organizer.hpp"
#include "enums.hpp"
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
extern int scopeDepth;


class ScopeNode;
class Expression;

class DataType {
    public:
        OperandType type;
        bool isConst;
        DataType(std::string type, bool isConst = false) 
        { 
            if      (type == "int")     { this->type = TINT;        }
            else if (type == "float")   { this->type = TFLOAT;      }
            else if (type == "char")    { this->type = TCHAR;       }
            else if (type == "string")  { this->type = TSTRING;     }
            else if (type == "bool")    { this->type = TBOOLEAN;    }
            else if (type == "void")    { this->type = TVOID;       }
            else                        { this->type = TUNDEFINED;  }
            this->isConst = isConst;
        }

        DataType(OperandType type, bool isConst = false)      { this->type = type, this->isConst = isConst; }
        ~DataType()                     { }
        static DataType* Undefined()    { return new DataType("undef", false); }
        static DataType* Void()         { return new DataType("void", false); }
        static DataType* Int()          { return new DataType("int", false); }
        static DataType* Float()        { return new DataType("float", false); }
        static DataType* Char()         { return new DataType("char", false); }
        static DataType* String()       { return new DataType("string", false); }
        static DataType* Bool()         { return new DataType("bool", false); }
};

class Operand {
    public:
        void* content;
        DataType* dataType;

        Operand() { content = nullptr; dataType = DataType::Undefined(); }
        Operand(const Operand& other) { 
            this->dataType = new DataType(*other.dataType);
            switch (other.dataType->type) {
                case TINT: case TBOOLEAN:
                    this->content = malloc(sizeof(int));
                    *(int*)this->content = *(int*)other.content;
                    break;
                case TFLOAT:
                    this->content = malloc(sizeof(float));
                    *(float*)this->content = *(float*)other.content;
                    break;

                case TCHAR:
                    this->content = malloc(sizeof(char));
                    *(char*)this->content = *(char*)other.content;
                    break;
                
                case TSTRING:
                    this->content = new std::string(*(std::string*)other.content);
                    break;
                default:
                    break;
            }

        }
        Operand(DataType* type, void* content) { this->dataType = type; this->content = content; }

        Operand(DataType* convertedType, Operand& other) {
            switch(convertedType->type) {
                case TBOOLEAN:
                    this->init( std::to_string((bool)other).c_str(), convertedType ); break;
                case TINT:
                    this->init( std::to_string((int)other).c_str(), convertedType ); break;
                case TFLOAT:
                    this->init( std::to_string((float)other).c_str(), convertedType ); break;
                case TSTRING:
                    this->init( other.toString().c_str(), convertedType ); break;
                case TCHAR:
                    this->init( std::to_string((int)other).c_str(), convertedType); break;
                case TVOID:
                    this->init(nullptr, DataType::Void()); break;
                case TUNDEFINED:
                    break;
            }
        }

        ~Operand() {
            if (content && dataType) {
                switch(dataType->type) {
                    case TINT: case TBOOLEAN:
                        delete (int*)content;
                        break;
                    case TFLOAT:
                        delete (float*)content;
                        break;
                    case TCHAR:
                        delete (char*)content;
                        break;
                    default:
                        break;
                }
                delete dataType;
                content = nullptr;
                dataType = nullptr;
            }
        }

        static Operand undefined() { return Operand(); }
        static Operand voidValue() { return Operand(DataType::Void(), nullptr); }
        static Operand intValue() { 
            int* x = new int;
            *x = 0;
            return Operand( DataType::Int(), x); 
        }

        static Operand floatValue() {            
            float* x = new float;
            *x = 0.0;
            return Operand( DataType::Float(), x); 
        }

        static Operand boolValue() {
            int* x = new int;
            x = 0;
            return Operand( DataType::Bool(), x); 
        }

        static Operand stringValue() {
            char* x = new char[1];
            x[0] = '1';
            return Operand( DataType::String(), x); 
        }

        static Operand charValue() {
            char* x = new char[1];
            x[0] = '1';
            return Operand( DataType::Char(), x); 
        }

        void init(const char* value, DataType* dataType) {
            this->dataType = dataType;
            if (value == nullptr) { return; }

            if (dataType->type == TSTRING) { 
                dataType->type = TSTRING;
                content = (void*) new std::string(value); 
            } else if (dataType->type != TVOID && dataType->type != TUNDEFINED) {
                content = malloc(Utils::typeToSize(dataType->type));
            }

            switch (dataType->type) {
                case TINT:
                    *(int*)content   = atoi(value); break;
                case TFLOAT:
                    *(float*)content = atof(value); break;
                case TCHAR:
                    *(char*)content  = (char)atoi(value); break;
                case TBOOLEAN:
                    *(int*)content   = strcmp(value, "true") && strcmp(value, "1") ? 0 : 1; break;
                default: break;
            }
        }
    
        std::string toString() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return std::to_string((int) *(int*)content);
                case TFLOAT:
                    return std::to_string((float) *(float*)content);
                case TCHAR:
                    return std::string(1, (char) *(char*)content);
                case TSTRING:
                    return *(std::string*)content;
                default:
                    return "undefined";
            }
        }

        operator int() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (int) *(int*)content;
                case TCHAR:
                    return (int) *(char*)content;
                case TFLOAT:
                    return (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator float() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (float) *(int*)content;
                case TFLOAT:
                    return (float) *(float*)content;
                case TCHAR:
                    return (float) *(char*)content;
                default:
                    return 0;
            }
        }

        operator char() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (char) (int) *(int*)content;
                case TCHAR:
                    return (char) *(char*)content;
                case TFLOAT:
                    return (char) (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator bool() const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return *(int*)content != 0;
                case TFLOAT:
                    return *(float*)content != 0;
                case TCHAR:
                    return *(char*)content != 0;
                default:
                    return 0;
            }
        }

        Operand operator+(int that) const {
            switch (dataType->type) {
                case TINT:
                    return Operand(DataType::Int(), (void*) new int((int) *(int*)content + that));
                case TBOOLEAN:
                    return Operand(DataType::Int(), (void*) new int((int) *(int*)content + that));
                case TFLOAT:
                    return Operand(DataType::Float(), (void*) new float((float) *(float*)content + (float)that));
                case TSTRING:
                    return Operand(DataType::String(), (void*) new std::string(*(std::string*)content + std::to_string(that)));
                case TCHAR:
                    return Operand(DataType::Char(), (void*) new char((char) *(char*)content + (char)that));
                default:
                    return Operand(DataType::Float(), nullptr);
            }
        }

        template<typename T>
        bool operator>(const T& that) const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (int) *(int*)content > that;
                case TFLOAT:
                    return (float) *(float*)content > (float)that;
                case TSTRING:
                    return *(std::string*)content > std::to_string(that);
                case TCHAR:
                    return (char) *(char*)content > (char)that;
                default:
                    return 0;
            }
        }

        template<typename T>
        bool operator==(const T& that) const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (int) *(int*)content == (int)that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == std::to_string(that);
                case TCHAR:
                    return (char) *(char*)content == (char)that;
                default:
                    return false;
            }
        }

        bool operator==(const Operand& that) const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (int) *(int*)content == (int)that;
                case TFLOAT:
                    return (float) *(float*)content == (float)that;
                case TSTRING:
                    return *(std::string*)content == that.toString();
                case TCHAR:
                    return (char) *(char*)content == (char)that;
                default:
                    return false;
            }
        }

        template<typename T>
        bool operator!=(const T& that) const {
            switch (dataType->type) {
                case TINT: case TBOOLEAN:
                    return (int) *(int*)content != that;
                case TFLOAT:
                    return (float) *(float*)content != (float)that;
                case TSTRING:
                    return *(std::string*)content != std::to_string(that);
                case TCHAR:
                    return (char) *(char*)content != (char)that;
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

        Operand operator=(const Operand& that) {
            if (this != &that) {
                Operand temp(that);

                std::swap(this->content, temp.content);
                std::swap(this->dataType, temp.dataType);
            }
            return *this;
        }
};

class FunctionParametersNode {
    public:
        std::vector<DataType*>   types;
        std::vector<Expression*>    defaultValues;
        std::vector<std::string> names;

        FunctionParametersNode();
        FunctionParametersNode( Expression* defaultValue, DataType* type, std::string name );

        FunctionParametersNode* addParameter( Expression* defaultValue, DataType* type, std::string name );
        
        ~FunctionParametersNode();
};

class FunctionCallParametersNode {
    public:
        std::vector<Expression*> params;
        FunctionCallParametersNode();
        FunctionCallParametersNode( Expression* param );
        FunctionCallParametersNode* addParameter( Expression* param );
        ~FunctionCallParametersNode();
};

class Scope {
    private:
        Scope* parent = nullptr;

        std::unordered_map<std::string, std::pair<DataType*, Operand>> variables;

        std::unordered_map<std::string, std::tuple<DataType*, FunctionParametersNode*, ScopeNode*>> functions;
    public:
        Scope() { this->parent = nullptr; }
        Scope(Scope* parent) { this->parent = parent; }

        Scope* getParent() { return parent; }
        void setParent(Scope* parent) { this->parent = parent; }

        void defineVariable(std::string varName, DataType* type, Operand value, bool writeSymbol) { 
            if (variables.find(varName) == variables.end()) {
                variables[varName] = { type, Operand::undefined() }; 

                if (value.dataType->type != TUNDEFINED)
                    assignVariable(varName, value, true);
                
                if (writeSymbol) {
                    SymbolTableEntry stEntry(
                        varName, EntryType::
                        VARIABLE, 
                        type->type, 
                        scopeDepth, 
                        type->isConst, 
                        value.dataType->type != TUNDEFINED,
                        false                
                    );
    
                    CompilerOrganizer::addSymbolTableEntry(stEntry);
                }

            } else {
                throw ErrorDetail(Severity::ERROR, "Variable " + varName + " has already been declared");
            }
        }    

        void defineFunction( DataType* returnType, std::string functionName, FunctionParametersNode* parameters, ScopeNode* scope) {
            if (functions.find(functionName) == functions.end()) {
                functions[functionName] = std::make_tuple(returnType, parameters, scope);

                SymbolTableEntry stEntry(
                    functionName, 
                    EntryType::FUNCTION, 
                    returnType->type, 
                    scopeDepth, 
                    returnType->isConst, 
                    scope != nullptr,
                    false                
                );

                for (int i = 0; i < parameters->names.size(); i++) {
                    stEntry.addArgument(parameters->types[i]->type);
                }

                CompilerOrganizer::addSymbolTableEntry(stEntry);

            } else {
                throw ErrorDetail(Severity::ERROR, "Function " + functionName + " has already been declared");
            }
        }

        // ================================================================================================================================================================

        void defineReturn( DataType* returnType ) { variables["return"] = { returnType, Operand::undefined() }; }
        
        bool canReturn()  { return variables.find("return") != variables.end() || ( parent != nullptr && parent->canReturn() ); }

        bool hasReturned() { return 
            ( variables.find("return") != variables.end() && variables["return"].second.dataType->type != TUNDEFINED ) 
            ||
            ( parent != nullptr && parent->hasReturned() );  
        }
        
        void assignReturn(Operand value) { 
            if (canReturn()) {
                if (variables.find("return") == variables.end()) 
                    parent->assignReturn(value);
                else if (variables["return"].first->type == value.dataType->type) {
                    variables["return"].second = value;
                } else {
                    throw ErrorDetail(Severity::ERROR, "Invalid Return Type");
                }
        
            } else {
               throw ErrorDetail(Severity::ERROR, "Invalid Return"); 
            }
        }
        
        bool validReturn(OperandType type) {
            if (canReturn()) {
                if (variables.find("return") == variables.end()) 
                    parent->validReturn(type);
                else if (!Utils::isValidAssignment(variables["return"].first->type, type)) {
                    throw ErrorDetail(Severity::ERROR, "Invalid Return Type");
                }
            }

            return true;
        }
        
        // ================================================================================================================================================================

        void defineBreak()  { variables["break"] = { DataType::Bool(), Operand::undefined() }; }

        bool canBreak()   { return variables.find("break") != variables.end() || ( parent != nullptr && parent->canBreak() ); }

        bool hasBreak() { 
            return 
            ( variables.find("break") != variables.end() && variables["break"].second.dataType->type == TVOID ) 
            ||
            ( parent != nullptr && parent->hasBreak() ); 
        }

        void assignBreak()  { 
            if (canBreak()) {
                if (variables.find("break") == variables.end()) 
                    parent->assignBreak();
                else variables["break"].second = Operand::voidValue();
            } else {
                throw ErrorDetail(Severity::ERROR, "Invalid Break"); 
            }
        }

        // ================================================================================================================================================================

        void defineContinue() { variables["continue"] = { DataType::Bool(), Operand::undefined() }; }
        
        bool canContinue() { return variables.find("continue") != variables.end() || ( parent != nullptr && parent->canContinue() ); }
        
        bool hasContinued()  { 
            return 
            ( variables.find("continue") != variables.end() && variables["continue"].second.dataType->type == TVOID ) 
            ||
            ( parent != nullptr && parent->hasContinued() ); 
        }
        
        void assignContinue()  { 
            if (canContinue()) {
                if (variables.find("continue") == variables.end()) parent->assignContinue();
                else variables["continue"].second = Operand::voidValue();
                variables["continue"].second = Operand::voidValue();
            } else {
                throw ErrorDetail(Severity::ERROR, "Invalid Continue"); 
            }
        }

        void reset() {
            DataType* returnable = variables.find("return") != variables.end() ? new DataType(variables["return"].first->type, variables["return"].first->isConst) : nullptr;
            bool breakable = variables.find("break") != variables.end();
            bool continuable = variables.find("continue") != variables.end();

            variables.clear();
            functions.clear();

            if (returnable) { defineReturn(returnable); }
            if (breakable) { defineBreak(); }
            if (continuable) { defineContinue(); }
        }

        void assignVariable(std::string varName, Operand value, bool initializing = false) {
            const auto& it = variables.find(varName);
            if (it != variables.end()) {
                if ( !initializing && variables[varName].first->isConst) throw ErrorDetail(Severity::ERROR, "Variable " + varName + " is constant and cannot be assigned");

                bool isValidAssignment = Utils::isValidAssignment(variables[varName].first->type, value.dataType->type);
                if (!isValidAssignment) throw ErrorDetail(Severity::ERROR, "The right handside type doesn't match the expected type for the variable");

                DataType* convertedType = new DataType(variables[varName].first->type);
                variables[varName].second = Operand(convertedType, value);
            } else if (parent != nullptr) {
                parent->assignVariable(varName, value);
            } else {
                throw ErrorDetail(Severity::ERROR, "Variable " + varName + " not found");
            }
        }
        
        Operand valueOf(std::string varName) { 
            if (variables.find(varName) != variables.end()) {
                return variables[varName].second;
            }  else if (parent != nullptr) {
                return parent->valueOf(varName);
            } else {
                throw ErrorDetail(Severity::ERROR, "Variable " + varName + " not found");
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
                throw ErrorDetail(Severity::ERROR, "Function " + functionName + " not found");
                return nullptr;
            }
        }

        int getFunctionRequiredParamsCount(std::string functionName) {
            FunctionParametersNode* params = getFunctionParameters(functionName);
            std::vector<Expression*>& defaultValues = params->defaultValues;
            int count = 0;
            for (int i = defaultValues.size() - 1; i >= 0; i--) {
                if (defaultValues[i] == nullptr) count++; 
            }
            return count;
        }


        FunctionParametersNode* getFunctionParameters(std::string functionName) {
            if (functions.find(functionName) != functions.end()) {
                return std::get<1>(functions[functionName]);
            } else if (parent != nullptr) {
                return parent->getFunctionParameters(functionName);
            } else {
                throw ErrorDetail(Severity::ERROR, "Function " + functionName + " not found");
                return new FunctionParametersNode();
            }
        }

        OperandType getFunctionReturnType(std::string functionName) {
            if (functions.find(functionName) != functions.end()) {
                return std::get<0>(functions[functionName])->type;
            } else if (parent != nullptr) {
                return parent->getFunctionReturnType(functionName);
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
                return TUNDEFINED;
            }
        }
};