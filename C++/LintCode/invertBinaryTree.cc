#include <iostream>
#include <queue>
using namespace std;

#define MAXSIZE 20
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        //do_recursion(root);
        
        without_recursion(root);
    }
    
    
    void do_recursion(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        
        do_recursion(root->right);
        do_recursion(root->left);
    }
    
    
    // can use stack or queue to traverse the binaryTree
    void without_recursion(TreeNode *root) {
        if(!root) {
            return;
        }
        queue<TreeNode *> Q;
        Q.push(root);
        TreeNode *tmp;
        while (!Q.empty()) {
            tmp = Q.front();
            Q.pop();
            swap(tmp->right, tmp->left);
            if (tmp->right != NULL) {
                Q.push(tmp->right);
            }
            if (tmp->left != NULL) {
                Q.push(tmp->left);
            }
        }
        
    }
};

int main() {
    Solution s;
    TreeNode *tree = new TreeNode(1);
    s.invertBinaryTree(tree);
    return 0;
}










