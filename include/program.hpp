#pragma once
#include "errorHandler.hpp"
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

        virtual void runSemanticChecker(Scope* scope = nullptr) {
            ProgramNode* it = next;
            while (it) {
                it->runSemanticChecker();
                it = next->next;
            }
        }

        virtual void run(Scope* scope = nullptr) {
            ProgramNode* it = next;
            while (it) {
                try {
                    it->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                }
                it = next->next;
            }
        }

        virtual std::string nodeName() {
            return "ProgramNode";
        }

        virtual void print(std::ostream& out) { out << line << ": " << nodeName() <<  std::endl; }
};


class PrintNode : public ProgramNode {
    Expression* body;
    public:
        std::string nodeName() override {
            return "PrintNode";
        }

        PrintNode( int line, Expression* body ) : ProgramNode(line) 
        {
            this->body = body;
            this->logLineInfo();
        }   

        void run(Scope* scope = nullptr) override {
            try {
                std::cout << body->getValue(scope) << std::endl;
            } catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
        }
};