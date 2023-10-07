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
    int res = -1;
    int dfs(TreeNode* root){
        if(!root) return 0; // if null, end traversal.
        int L = dfs(root->left);
        int R = dfs(root->right);
        res = std::max(L + R, res); // maintain the max path while traversal.
        return std::max(L, Rc) + 1; // return the depth of this tree.
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return res;
    }
};
