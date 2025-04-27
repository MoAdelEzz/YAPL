#pragma once
#include "enums.hpp"
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>

extern int scopeDepth;

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

enum EntryType      { VARIABLE, FUNCTION, SCOPE_ENTRY, SCOPE_EXIT };

class SymbolTableEntry {
    std::string name;
    EntryType entryType;
    OperandType dataType;
    std::vector<OperandType> argumentTypes;
    bool isConst;
    bool isInitialized;
    bool isUsed;
    int  scopeLayer;

    public:
        SymbolTableEntry(std::string name, EntryType entryType, OperandType dataType, int scopeLayer, bool isConst = false, bool isInitialized = false, bool isUsed = false) 
        : name(name), entryType(entryType), dataType(dataType), isConst(isConst), isInitialized(isInitialized), isUsed(isUsed), scopeLayer(scopeLayer) {}

        void setName(std::string name) { this->name = name; }
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

        static SymbolTableEntry scopeEntry() {
            return SymbolTableEntry("", SCOPE_ENTRY, TUNDEFINED, scopeDepth);
        }

        static SymbolTableEntry scopeExit() {
            return SymbolTableEntry("", SCOPE_EXIT, TUNDEFINED, scopeDepth);
        }

        void dump(std::ofstream& out) const {
            std::string dataType = "";
            if (entryType == FUNCTION) {
                dataType += " (";
                for (int i = 0; i < argumentTypes.size(); i++) {
                    OperandType type = argumentTypes[i];
                    dataType +=  Utils::typeToString(type) + (i == argumentTypes.size() - 1 ? ") -> " : ",");
                }
                dataType += Utils::typeToString(this->dataType);
            }

            if (entryType != SCOPE_ENTRY && entryType != SCOPE_EXIT) {
                out << std::setw(20) << std::left << name
                << std::setw(20) << std::left << (entryType == VARIABLE ? "Variable" : "Function")
                << std::setw(20) << std::left << dataType
                << std::setw(20) << std::left << scopeLayer
                << std::setw(20) << std::left << (isConst ? "Yes" : "No")
                << std::setw(20) << std::left << (isInitialized ? "Yes" : "No")
                << std::setw(20) << std::left << (isUsed ? "Yes" : "No")
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
            res =  result.size() > 0 ? result : "t" + std::to_string(index++);
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
            int index = findSymbolIndex(name);
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
                logFile << error.getLine() << ": " << (error.getSeverity() == ERROR ? "Error" : "Warning") << " - " << error.getMessage() << std::endl;
                if (!error.getSuggestion().empty()) {
                    logFile << "  Suggested fix: " << error.getSuggestion() << std::endl;
                }
            }
            logFile.close();
        }

        static void dumpSymbolTable() {
            if (state != FINISHED) {
                return;
            }

            std::ofstream symbolTableFile("log/symbol_table.txt");
            symbolTableFile.clear();
            symbolTableFile << std::setw(20) << std::left << "Name"
                            << std::setw(20) << std::left << "Node Type"
                            << std::setw(20) << std::left << "Type"
                            << std::setw(20) << std::left << "Scope"
                            << std::setw(20) << std::left << "IsConst"
                            << std::setw(20) << std::left << "IsInitialized"
                            << std::setw(20) << std::left << "IsUsed"
                            << std::endl;

            symbolTableFile << std::string(100, '-') << std::endl;
            for (const SymbolTableEntry& entry : symbolTable) {
                entry.dump(symbolTableFile);
            }
            symbolTableFile.close();
        }

        static void dumpQuadruples() {
            std::ofstream quadruplesFile("log/quadruples.txt");
            quadruplesFile.clear();

            for (const QuadrupleEntry& entry : quadruples) {
                quadruplesFile 
                << std::setw(12) << std::left  << opToString(entry.operation)
                << std::setw(8) << std::left  << entry.arg1
                << std::setw(8) << std::left  << entry.arg2
                << std::setw(8) << std::left  << (entry.hasDestination() ? entry.res : "") 
                << std::endl;
            }
            quadruplesFile.close();
        }
};