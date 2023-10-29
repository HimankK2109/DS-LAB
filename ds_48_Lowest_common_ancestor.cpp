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

    TreeNode* findLCA(TreeNode* node, int p, int q) {
        if (node == nullptr)
            return nullptr;

        if (node->val == p || node->val == q)
            return node;

        TreeNode* leftLCA = findLCA(node->left, p, q);
        TreeNode* rightLCA = findLCA(node->right, p, q);

        if (leftLCA != nullptr && rightLCA != nullptr)
            return node;

        return (leftLCA != nullptr) ? leftLCA : rightLCA;
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

    int p = 3, q = 7;
    TreeNode* lca = tree.findLCA(tree.root, p, q);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->val << endl;
    } else {
        cout << "One or both of the nodes not found in the tree." << endl;
    }

    return 0;
}