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
    int depth;
    void dfs(TreeNode* node, int curDepth){
        if(!node)
            return;
        if(++curDepth > depth)
            depth = curDepth;
        dfs(node->left, curDepth);
        dfs(node->right, curDepth);
    }
public:
    int maxDepth(TreeNode* root) {
        //robust
        if(!root)
            return 0;
        depth = 0;
        dfs(root, 0);
        return depth;
    }
};

