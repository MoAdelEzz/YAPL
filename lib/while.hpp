#include "node.hpp"

class WhileNode {
    ExpressionNode* condition;
    public:
        WhileNode(ExpressionNode* cond) { 
            condition = cond; 
        }

        void run() { 
        }
};