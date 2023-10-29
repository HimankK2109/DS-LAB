#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() : root(nullptr) {}

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

    TreeNode* search(int val) {
        return searchRecursive(root, val);
    }

    TreeNode* searchRecursive(TreeNode* node, int val) {
        if (node == nullptr || node->val == val) {
            return node;
        }

        if (val < node->val) {
            return searchRecursive(node->left, val);
        }

        return searchRecursive(node->right, val);
    }

    void printBST() {
        printBSTRecursive(root, 0);
    }

    void printBSTRecursive(TreeNode* node, int level) {
        if (node != nullptr) {
            printBSTRecursive(node->right, level + 1);
            cout << endl;

            if (node == root)
                cout << "Root -> ";
            else {
                for (int i = 0; i < level; i++)
                    cout << "|\t";
            }

            cout << node->val;

            printBSTRecursive(node->left, level + 1);
        }
    }
};

int main() {
    BinarySearchTree bst;
    cout<<"Himank Kumar C0/206"<<endl;
    
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    cout << "Binary Search Tree Structure:" << endl;
    bst.printBST();
    cout << endl;

    int searchValue = 7;
    TreeNode* foundNode = bst.search(searchValue);

    if (foundNode != nullptr) {
        cout << "Node with value " << searchValue << " found!" << endl;
    } else {
        cout << "Node with value " << searchValue << " not found." << endl;
    }

    return 0;
}