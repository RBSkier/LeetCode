/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool core(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        else if(!left || !right) return false;

        return left->val == right->val  //two nodes' values are the same.
            && core(left->left, right->right) //if left node's left subtree is symmetric to right node's right subtree.
            && core(left->right, right->left); //if left node's right subtree is symmetric to right node's left subtree.
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        //recursive DFS.
        return core(root->left, root->right);
    }
};
