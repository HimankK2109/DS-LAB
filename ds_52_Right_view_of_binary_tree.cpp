#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    TreeNode* insertRecursive(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }

        if (val < node->val) {
            node->left = insertRecursive(node->left, val);
        } else if (val > node->val) {
            node->right = insertRecursive(node->right, val);
        }

        return node;
    }

    void printTree() {
        printTreeRecursive(root, 0);
    }

    void printTreeRecursive(TreeNode* node, int level) {
        if (node != nullptr) {
            printTreeRecursive(node->right, level + 1);
            cout << endl;

            if (node == root)
                cout << "Root -> ";
            else {
                for (int i = 0; i < level; i++)
                    cout << "|\t";
            }

            cout << node->val;

            printTreeRecursive(node->left, level + 1);
        }
    }

    void rightView() {
        rightViewRecursive(root, 1);
    }

    void rightViewRecursive(TreeNode* node, int level) {
        static int maxLevel = 0;

        if (node == nullptr) return;

        if (maxLevel < level) {
            cout << node->val << " ";
            maxLevel = level;
        }

        rightViewRecursive(node->right, level + 1);
        rightViewRecursive(node->left, level + 1);
    }
};

int main() {
    BinaryTree tree;
    cout<<"Himank Kumar C0/206"<<endl;
    
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Binary Tree Structure:" << endl;
    tree.printTree();
    cout << endl;

    cout << "Right View:" << endl;
    tree.rightView();
    cout << endl;

    return 0;
}