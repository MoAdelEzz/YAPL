#include "node.hpp"
#include <string>

class Identifier {
    std::string name;
};


class AssignmentNode {
    protected:
        Identifier* variable;
        ExpressionNode* eqn;
    public:
        AssignmentNode(Identifier* left, ExpressionNode* right) {
            this->variable = left;
            this->eqn = right;
        }

        void run() {
            
        }
};