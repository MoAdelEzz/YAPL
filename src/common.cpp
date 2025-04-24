#include "expression.hpp"

// =========================================================================================
// ==================================== Function Parameters ===================================
// =========================================================================================

FunctionParametersNode::FunctionParametersNode() {}

FunctionParametersNode::FunctionParametersNode( DataType* type, std::string name ) {            
    this->names.push_back(name);
    this->types.push_back(type);
}

FunctionParametersNode* FunctionParametersNode::addParameter( DataType* type, std::string name ) {
    this->names.push_back(name);
    this->types.push_back(type);
    return this;
}


FunctionParametersNode::~FunctionParametersNode() {
    for (DataType*& type : types) {
        delete type;
        type = nullptr;
    }
    types.clear();
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