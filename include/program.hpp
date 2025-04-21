#pragma once
#include "expression.hpp"
#include <ostream>
#include <fstream>

class ProgramNode {
    protected:
    ProgramNode* next = nullptr;
    int line = -1;
    public:
        static int lineNumber;

        void setLine(int lineNum) { 
            if (line == -1)
                line = lineNum;
            
            std::ofstream logFile("log/line.txt", std::ios_base::app);
            this->print(logFile);
            logFile.close();
        }

        ProgramNode(bool setLineNumber = true) { if (setLineNumber) setLine(lineNumber); }
        ProgramNode(ProgramNode* next) : next(next) { setLine(lineNumber); }
        virtual ProgramNode* setNext(ProgramNode* next) { 
            this->next = next; 
            return this; 
        }
        ProgramNode* getNext() { return next; }

        virtual void run(Scope* scope = nullptr) {
            ProgramNode* it = next;
            while (it) {
                it->run(scope);
                it = next->next;
            }
        }

        virtual std::string nodeName() {
            return "ProgramNode";
        }

        virtual void print(std::ostream& out) { out << line << ": " << nodeName() <<  std::endl; }

        static void newLine() { lineNumber++; }
};


class PrintNode : public ProgramNode {
    Expression* body;
    public:
        std::string nodeName() override {
            return "PrintNode";
        }

        PrintNode( int line, Expression* body ) : ProgramNode(false) {
            this->body = body;
            this->setLine(line);
        }   

        void run(Scope* scope = nullptr) override {
            std::cout << body->getValue(scope) << std::endl;
        }
};