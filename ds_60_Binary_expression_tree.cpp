#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

class ExpressionTree {
private:
    TreeNode* root;

    bool isOperator(string& val) {
        return val == "+" || val == "-" || val == "*" || val == "/";
    }

    int evaluate(TreeNode* node) {
        if (!node) return 0;

        if (!isOperator(node->value)) {
            return stoi(node->value);
        }

        int leftVal = evaluate(node->left);
        int rightVal = evaluate(node->right);

        if (node->value == "+") return leftVal + rightVal;
        if (node->value == "-") return leftVal - rightVal;
        if (node->value == "*") return leftVal * rightVal;
        if (node->value == "/") return leftVal / rightVal;

        return 0; // Default case, should not reach here
    }

public:
    ExpressionTree() : root(nullptr) {}

    TreeNode* buildTree(string postfix) {
        for (char& c : postfix) {
            string s(1, c);
            TreeNode* node = new TreeNode(s);

            if (isOperator(s)) {
                node->right = root;
                node->left = root->right;
                root = node;
            } else {
                root = node;
            }
        }

        return root;
    }

    int evaluate() {
        return evaluate(root);
    }
};

int main() {
    ExpressionTree tree;
    cout<<"Himank Kumar C0/206"<<endl;

    string postfixExpression = "42*3+";
    tree.buildTree(postfixExpression);

    cout << "Postfix Expression: " << postfixExpression << endl;
    cout << "Result: " << tree.evaluate() << endl;

    return 0;
}