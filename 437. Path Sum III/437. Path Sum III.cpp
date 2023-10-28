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
    int pathSum(TreeNode* root, int targetSum) {
        preSumMap[0] = 1;
        DFS(root, 0, targetSum);
        return res;
    }

private:
    void DFS(TreeNode* root, long preSum, int targetSum) {
        if(!root) return;
        
        // accumulate new solutions.
        long curr = preSum + root->val;
        res += preSumMap[curr - targetSum];
        // update the preSumMap after.
        preSumMap[curr]++;
        // recursive call DFS.
        DFS(root->left, curr, targetSum);
        DFS(root->right, curr, targetSum);
        preSumMap[curr]--;
    }

private:
    unordered_map<long, int> preSumMap;
    int res = 0;
};
