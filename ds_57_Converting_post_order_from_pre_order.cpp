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

    void printPreorder(TreeNode* node) {
        if (node != nullptr) {
            cout << node->val << " ";
            printPreorder(node->left);
            printPreorder(node->right);
        }
    }

    void convertPreToPost(vector<int>& preorder) {
        vector<int> postorder;
        convertRecursive(preorder, 0, preorder.size() - 1, postorder);
        cout << "Converted Postorder Traversal: ";
        for (int val : postorder) {
            cout << val << " ";
        }
        cout << endl;
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

    void convertRecursive(vector<int>& preorder, int start, int end, vector<int>& postorder) {
        if (start > end) return;

        int pivot = preorder[start];
        int rightIdx = start + 1;
        while (rightIdx <= end && preorder[rightIdx] < pivot) {
            rightIdx++;
        }

        convertRecursive(preorder, start + 1, rightIdx - 1, postorder);
        convertRecursive(preorder, rightIdx, end, postorder);
        postorder.push_back(pivot);
    }
};

int main() {
    BinarySearchTree bst;
    cout<<"Himank Kumar C0/206"<<endl;

    vector<int> preorder = {10, 5, 3, 7, 15, 12, 18};
    
    cout << "Original Preorder Traversal: ";
    for (int val : preorder) {
        cout << val << " ";
    }
    cout << endl;

    for (int val : preorder) {
        bst.insert(val);
    }

    cout << "Original BST Preorder Traversal: ";
    bst.printPreorder(bst.root);
    cout << endl;

    bst.convertPreToPost(preorder);

    cout << "\nBinary Search Tree Structure:" << endl;
    bst.printBST();
    cout << endl;

    return 0;
}