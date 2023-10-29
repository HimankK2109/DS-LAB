#include <iostream>
#include <vector>
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

    void postToPre(vector<int>& postorder) {
        root = buildTreeFromPostOrder(postorder);
    }

    TreeNode* buildTreeFromPostOrder(vector<int>& postorder) {
        int n = postorder.size();
        if (n == 0) return nullptr;

        TreeNode* root = new TreeNode(postorder[n - 1]);

        int i;
        for (i = n - 1; i >= 0; i--) {
            if (postorder[i] < root->val) break;
        }

        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + i + 1);
        vector<int> rightPostOrder(postorder.begin() + i + 1, postorder.end() - 1);

        root->left = buildTreeFromPostOrder(leftPostOrder);
        root->right = buildTreeFromPostOrder(rightPostOrder);

        return root;
    }
};

int main() {
    BinarySearchTree bst;
    cout<<"Himank Kumar C0/206"<<endl;
    vector<int> postorder = {7, 3, 9, 5, 15, 12, 10};

    cout << "Postorder Traversal: ";
    for (int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    bst.postToPre(postorder);

    cout << "\nBinary Search Tree Structure:" << endl;
    bst.printBST();
    cout << endl;

    return 0;
}