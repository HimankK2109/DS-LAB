#include <iostream>
#include <map>
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

    void bottomView() {
        map<int, int> bottomViewMap;
        bottomViewUtil(root, 0, 0, bottomViewMap);
        cout << "\nBottom View of Binary Tree:" << endl;
        for (auto it = bottomViewMap.begin(); it != bottomViewMap.end(); ++it) {
            cout << it->second << " ";
        }
        cout << endl;
    }

    void bottomViewUtil(TreeNode* node, int horizontalDist, int level, map<int, int>& bottomViewMap) {
        if (node == nullptr) return;

        bottomViewMap[horizontalDist] = node->val;

        bottomViewUtil(node->left, horizontalDist - 1, level + 1, bottomViewMap);
        bottomViewUtil(node->right, horizontalDist + 1, level + 1, bottomViewMap);
    }
};

int main() {
    BinaryTree tree;
    cout<<"Himank Kumar C0/206"<<endl;
    
    tree.insert(20);
    tree.insert(8);
    tree.insert(22);
    tree.insert(5);
    tree.insert(3);
    tree.insert(25);
    tree.insert(10);
    tree.insert(14);

    cout << "Binary Tree Structure:" << endl;
    tree.printTree();
    cout << endl;

    tree.bottomView();

    return 0;
}