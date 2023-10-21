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

#include <limits>

class Solution {
private:
    bool DFS(TreeNode* root, long lower, long upper){
        if(!root) 
            return true;
        if(root->val <= lower || root->val >= upper)
            return false;
        return DFS(root->left, lower, root->val) && DFS(root->right, root->val, upper);
    }
public:
    bool isValidBST(TreeNode* root) {
        return DFS(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }
};
