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
public:
    int maxPathSum(TreeNode* root) {
        maxPathSumCore(root);
        return max_value;
    }

private:
    int maxPathSumCore(TreeNode* root) {
        if(!root) return 0;  //递归终止条件

        int left = std::max(0, maxPathSumCore(root->left));
        int right = std::max(0, maxPathSumCore(root->right));
        int case1 = root->val + left + right;    // 路径经过当前节点的左右节点的情况下的最优解。
        max_value = std::max(max_value, case1);  // 维护目前为止遇到的最大值解。
        return root->val + std::max(left, right); // 路径不经过当前节点的左右节点的情况下，将最优解作为子问题的解返回给父节点。
    }

private:
    int max_value = std::numeric_limits<int>::min();
};
