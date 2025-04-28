#pragma once
#include "enums.hpp"
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

extern int scopeDepth;
extern int lineNumber;

enum Severity { ERROR, WARNING };

class ErrorDetail {
    int line;
    Severity severity;
    std::string message;
    std::string suggestion;

    public:
        ErrorDetail(Severity severity, std::string message, std::string suggestion = "", int line = -1 ) 
        : line(line), 
          severity(severity), 
          message(message), 
          suggestion(suggestion) {}

        const int getLine() const { return line; }
        const Severity getSeverity() const { return severity; }
        const std::string getMessage() const { return message; }
        const std::string getSuggestion() const { return suggestion; }

        void setLine(int line) { this->line = line; }
        void setSeverity(Severity severity) { this->severity = severity; }
        void setMessage(std::string message) { this->message = message; }
        void setSuggestion(std::string suggestion) { this->suggestion = suggestion; }
};

enum EntryType      { VARIABLE, FUNCTION, SCOPE_ENTRY, SCOPE_EXIT, NONE };

class SymbolTableEntry {
    std::string name;
    EntryType entryType = NONE;
    OperandType dataType = TUNDEFINED;
    int line = -1;
    std::vector<OperandType> argumentTypes;
    bool isConst = false;
    bool isInitialized = false;
    bool isUsed = false;
    int  scopeLayer = -1;

    public:
        SymbolTableEntry(std::string name, EntryType entryType, OperandType dataType, int scopeLayer, int line = -1, bool isConst = false, bool isInitialized = false, bool isUsed = false) 
        : name(name), entryType(entryType), dataType(dataType), isConst(isConst), isInitialized(isInitialized), isUsed(isUsed), scopeLayer(scopeLayer) {
            line = lineNumber;
        }

        SymbolTableEntry() {}

        void setName(std::string name) { this->name = name; }
        void setLine(int lineNum) { this->line = lineNum; }
        void setEntryType(EntryType entryType) { this->entryType = entryType; }
        void setDataType(OperandType dataType) { this->dataType = dataType; }
        void setScopeLayer(int scopeLayer) { this->scopeLayer = scopeLayer; }
        void markAsConst(bool isConst) { this->isConst = isConst; }
        void markAsInitialized() { this->isInitialized = true; }
        void markAsUsed() { this->isUsed = true; }


        void addArgument(OperandType type) { if ( entryType == FUNCTION ) argumentTypes.push_back(type); }

        std::string getName() { return name; }
        int getScopeLayer() { return scopeLayer; }
        EntryType getEntryType() { return entryType; }
        int getLine() { return line; }

        static SymbolTableEntry scopeEntry() {
            return SymbolTableEntry("", SCOPE_ENTRY, TUNDEFINED, scopeDepth);
        }

        static SymbolTableEntry scopeExit() {
            return SymbolTableEntry("", SCOPE_EXIT, TUNDEFINED, scopeDepth);
        }

        void dump(std::ofstream& out) const {
            std::string dataType = "";
            if (entryType == FUNCTION) {
                dataType += "( ";
                for (int i = argumentTypes.size() - 1; i >= 0; i--) {
                    OperandType type = argumentTypes[i];
                    dataType +=  Utils::typeToString(type) + (i > 0 ? " - " : "");
                }
                dataType += " ) -> " + Utils::typeToString(this->dataType);
            } else {
                dataType = Utils::typeToString(this->dataType); 
            }

            if (entryType != SCOPE_ENTRY && entryType != SCOPE_EXIT) {
                out << name << "," << (entryType == VARIABLE ? "Variable" : "Function") << "," << dataType << "," << 
                line << "," << scopeLayer << "," << (isConst ? "Yes" : "No") << "," << 
                (isInitialized || entryType == FUNCTION ? "Yes" : "No") << "," << (isUsed ? "Yes" : "No") 
                << std::endl;
            }
        }
};


class QuadrupleEntry {
    static int index;

    public:
        OperationType operation;
        std::string arg1;
        std::string arg2;
        std::string res;

        QuadrupleEntry(OperationType operation, std::string arg1, std::string arg2, std::string result = "") 
        : operation(operation), arg1(arg1), arg2(arg2) {
            if (result != " ") {
                res =  result.size() > 0 ? result : "t" + std::to_string(index++);
            }
        }

        bool hasDestination() const {
            return operation != QUAD_PRINT;
        }
};


enum CompilerState { VALIDATING, RUNNING, FAILED, FINISHED };

class CompilerOrganizer {
    private:    
        static CompilerState state;
        static std::vector<ErrorDetail> errors;
        static std::vector<SymbolTableEntry> symbolTable;
        static std::vector<QuadrupleEntry> quadruples;

    public:
        static std::string createQuadEntry(OperationType operation, std::string arg1, std::string arg2) {
            quadruples.push_back(QuadrupleEntry(operation, arg1, arg2));
            return quadruples.back().res;
        }

        static void addQuadruple(OperationType operation, std::string arg1, std::string arg2, std::string label) {
            quadruples.push_back(QuadrupleEntry(operation, arg1, arg2, label));
        }

        static void addLabel(int label) {
            quadruples.push_back(QuadrupleEntry(QUAD_LABEL, "", "", "L" + std::to_string(label)));
        }

        static void addFunctionStartLabel(std::string funcName) {
            quadruples.push_back(QuadrupleEntry(QUAD_FUNCTION_START, funcName, "", " "));
        }

        static void addFunctionArgument(std::string argName) {
            quadruples.push_back(QuadrupleEntry(QUAD_FUNCTION_ARGUMENT, argName, "", " "));
        }

        static void addFunctionReturn(std::string argName) {
            quadruples.push_back(QuadrupleEntry(QUAD_FUNCTION_RETURN, argName, "", " "));
        }

        static void addFunctionEndLabel(std::string funcName) {
            quadruples.push_back(QuadrupleEntry(QUAD_FUNCTION_END, funcName, "", " "));
        }

        static void addError(ErrorDetail error) {
            errors.push_back(error);
        }

        static void addSymbolTableEntry(SymbolTableEntry entry) {
            if (state != VALIDATING) {
                return;
            }

            symbolTable.push_back(entry);
        }

        static int findSymbolIndex(std::string name, EntryType type = VARIABLE) {
            int targetScope = scopeDepth;

            for (int i = symbolTable.size() - 1; i >= 0; i--) {
                if ( symbolTable[i].getEntryType() == SCOPE_ENTRY && symbolTable[i].getScopeLayer() == targetScope )
                {
                    targetScope--;
                    if (targetScope < 1) break;
                }

                if ( symbolTable[i].getScopeLayer() > targetScope ) continue;

                if ( symbolTable[i].getName() == name && symbolTable[i].getEntryType() == type ) {
                    return i;
                }
            }

            return -1;
        }

        static void markSymbolAsInitialized(std::string name) {
            int index = findSymbolIndex(name);
            if (index != -1) {
                symbolTable[index].markAsInitialized();
            }
        }

        static void markSymbolAsUsed( std::string name, EntryType type = VARIABLE ) {
            int index = findSymbolIndex(name, type);
            if (index != -1) {
                symbolTable[index].markAsUsed();
            }
        }

        static void startRunning() { state = RUNNING; }
        
        static void exitWithFailure() { state = FAILED; }

        static void exitWithSuccess() { state = FINISHED; }

        static CompilerState getState() { return state; }

        static int getErrorCount() { 
            int count = 0;
            for (int i = 0; i < errors.size(); i++) {
                count += errors[i].getSeverity() == ERROR;
            } 
            return count; 
        }

        static void dumpErrors() {
            std::sort(errors.begin(), errors.end(), [](const ErrorDetail& a, const ErrorDetail& b) { 
                return a.getLine() < b.getLine();
            });

            std::ofstream logFile("log/errors.txt");
            logFile.clear();

            for (const ErrorDetail& error : errors) {
                logFile << error.getLine() << "," << (error.getSeverity() == ERROR ? "Error" : "Warning") << "," << error.getMessage() << std::endl;
            }
            logFile.close();
        }

        static void dumpSymbolTable() {
            if (state != FINISHED) {
                return;
            }

            std::ofstream symbolTableFile("log/symbol_table.txt");
            symbolTableFile.clear();
            symbolTableFile << "Name" << "," << "Node Type" << "," << "Type" << "," << "Line" << "," << "Scope" << "," << "IsConst" << "," << "IsInitialized" << "," << "IsUsed" << std::endl;

            // symbolTableFile << std::setw(30) << std::left << "Name"
            //                 << std::setw(30) << std::left << "Node Type"
            //                 << std::setw(30) << std::left << "Type"
            //                 << std::setw(30) << std::left << "Line"
            //                 << std::setw(30) << std::left << "Scope"
            //                 << std::setw(30) << std::left << "IsConst"
            //                 << std::setw(30) << std::left << "IsInitialized"
            //                 << std::setw(30) << std::left << "IsUsed"
            //                 << std::endl;

            for (const SymbolTableEntry& entry : symbolTable) {
                entry.dump(symbolTableFile);
            }
            symbolTableFile.close();
        }

        static void dumpQuadruples(bool isOptimized = false ) {
            std::string filename = isOptimized ? "log/optimized_quadruples.txt" : "log/quadruples.txt";
            std::ofstream quadruplesFile(filename);
            quadruplesFile.clear();

            for (const QuadrupleEntry& entry : quadruples) {
                quadruplesFile << opToString(entry.operation) << "," << entry.arg1 << "," 
                << entry.arg2 << "," << (entry.hasDestination() ? entry.res : "")  << std::endl;
            }
            quadruplesFile.close();
        }

        static void eraseUnusedVariables() {
            std::vector<QuadrupleEntry> optimizedQuadruples;
            std::unordered_map<std::string, int> varFrequency;

            for (QuadrupleEntry& entry : quadruples) {
                entry.arg1 != entry.res ? varFrequency[entry.arg1]++ : varFrequency[entry.arg1];
                entry.arg2 != entry.res ? varFrequency[entry.arg2]++ : varFrequency[entry.arg2];
            }

            for (int i = quadruples.size() - 1; i >= 0; i--) {
                QuadrupleEntry entry = quadruples[i];
                if (entry.operation != QUAD_ASSIGN) 
                    continue;
                if (varFrequency[entry.res] > 0) {
                    varFrequency[entry.arg1]++;
                    varFrequency[entry.arg2]++;
                }
            }

            for (int i = quadruples.size() - 1; i >= 0; i--) {
                std::string result = quadruples[i].res;

                if (result.size() == 0 || result[0] == 'L') {
                    optimizedQuadruples.push_back(quadruples[i]); 
                    continue;
                }

                if (varFrequency[result] > 0) {
                    optimizedQuadruples.push_back(quadruples[i]);
                } else {
                    varFrequency[quadruples[i].arg1]--;
                    varFrequency[quadruples[i].arg2]--;
                }
            }

            std::reverse(optimizedQuadruples.begin(), optimizedQuadruples.end());
            quadruples.clear();
            quadruples = optimizedQuadruples;
        }


        static void eraseUnreachableCode() {
            std::vector<QuadrupleEntry> optimizedQuadruples;

            for (int i = 0; i < quadruples.size();) {
                optimizedQuadruples.push_back(quadruples[i]);

                if (quadruples[i].operation == QUAD_GOTO) {
                    while(++i < quadruples.size() && quadruples[i].operation != QUAD_LABEL);
                } else {
                    i++;
                }
            }

            quadruples.clear();
            quadruples = optimizedQuadruples;
        }

        static void eraseUnusedLabels() { 
            std::vector<QuadrupleEntry> optimizedQuadruples;

            std::unordered_map<std::string, int> labelFrequency;
            for (int i = 0; i < quadruples.size(); i++) {
                if ( quadruples[i].operation == QUAD_GOTO || 
                     quadruples[i].operation == QUAD_GOTO_IF_FALSE ||
                     quadruples[i].operation == QUAD_GOTO_IF_TRUE
                ) {
                    labelFrequency[quadruples[i].res]++;
                }
            }

            for (int i = 0; i < quadruples.size(); i++) {
                if (quadruples[i].operation == QUAD_LABEL) {
                    if (labelFrequency[quadruples[i].res] > 0) {
                        optimizedQuadruples.push_back(quadruples[i]);
                    }
                } else {
                    optimizedQuadruples.push_back(quadruples[i]);
                }
            }

            quadruples.clear();
            quadruples = optimizedQuadruples;
        }

        static void optimizeQuadruples() {
            eraseUnusedVariables();
            eraseUnreachableCode();
            eraseUnusedLabels();
        }
};