#include "expression.hpp"

// =========================================================================================
// ==================================== Function Parameters ===================================
// =========================================================================================

FunctionParametersNode::FunctionParametersNode() {}

FunctionParametersNode::FunctionParametersNode( Expression* defaultValue, DataType* type, std::string name ) {            
    addParameter(defaultValue, type, name);
}

FunctionParametersNode* FunctionParametersNode::addParameter( Expression* defaultValue, DataType* type, std::string name ) {
    this->names.push_back(name);
    this->types.push_back(type);
    this->defaultValues.push_back(defaultValue);
    return this;
}


FunctionParametersNode::~FunctionParametersNode() {
    types.clear();
    names.clear();
    defaultValues.clear();
}

// =========================================================================================
// ==================================== Function Call Parameters ===================================
// =========================================================================================

FunctionCallParametersNode::FunctionCallParametersNode() {}
FunctionCallParametersNode::FunctionCallParametersNode( Expression* param ) { 
    params.push_back(param);
}   
FunctionCallParametersNode* FunctionCallParametersNode::addParameter( Expression* param ) {
    params.push_back(param);
    return this;
}
FunctionCallParametersNode::~FunctionCallParametersNode() {
    for (Expression*& param : params) {
        delete param;
        param = nullptr;
    }
    params.clear();
}