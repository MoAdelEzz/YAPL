#pragma once
#include "enums.hpp"
#include "organizer.hpp"
#include "expression.hpp"
#include <ostream>
#include <fstream>

class ProgramNode {
    protected:
        ProgramNode* next = nullptr;
        int line = -1;

    public:
        void setLine(int lineNum) { 
            if (line == -1)
                line = lineNum;
        }

        void logLineInfo() {
            return;
            std::ofstream logFile("log/line.txt", std::ios_base::app);
            this->print(logFile);
            logFile.close();
        }

        ProgramNode( int line ) { setLine(line); }
        ProgramNode(int line, ProgramNode* next) : next(next) { setLine(line); }
        virtual ProgramNode* setNext(ProgramNode* next) { 
            this->next = next; 
            return this; 
        }
        ProgramNode* getNext() { return next; }
        ~ProgramNode() { 
            if (next) delete next; 
        }

        virtual void generateQuadruples(Scope* scope) {
            
        }


        virtual void runSemanticChecker(Scope* scope = nullptr) {
            
        }

        virtual void run(Scope* scope = nullptr) {
            
        }

        virtual std::string nodeName() {
            return "ProgramNode";
        }

        virtual void print(std::ostream& out) { out << line << ": " << nodeName() <<  std::endl; }
};


class PrintNode : public ProgramNode {
    Expression* body = nullptr;
    public:
        std::string nodeName() override {
            return "PrintNode";
        }

        PrintNode( int line, Expression* body ) : ProgramNode(line) 
        {
            this->body = body;
            this->logLineInfo();
        }   
        
        void generateQuadruples(Scope* scope) override {
            CompilerOrganizer::addQuadruple(QUAD_PRINT, body->generateQuadruples(), "", " ");
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            OperandType type = TUNDEFINED;
            bool errornous = false;

            try {
                type = body->getExpectedType(scope);
            } catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                errornous = true;
            }

            if (!errornous && type >= TVOID) {
                ErrorDetail error(Severity::ERROR, "Invalid Expression Inside Print");
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
        }

        void run(Scope* scope = nullptr) override {
            std::cout << body->getValue(scope) << std::endl;
        }
};