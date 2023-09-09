/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool flag = true;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l_depth = dfs(root->left);
        int r_depth = dfs(root->right);
        if(abs(l_depth - r_depth) > 1)
            flag = false;
        return max(l_depth, r_depth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        dfs(root);
        return flag;
    }
};



