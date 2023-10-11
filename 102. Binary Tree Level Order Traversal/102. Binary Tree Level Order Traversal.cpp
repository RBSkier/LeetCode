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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        std::vector<vector<int>> res;
        std::queue<TreeNode*> q;
        q.push(root);
        for(int N = q.size(); N != 0; N = q.size()){
            res.push_back(vector<int>());   //directly place the val in res can reduce the time of copy vector.
            for(int i = 0; i < N; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                res.back().push_back(node->val);
            }
        }
        return res;
    }
};
/*
1. create a deque
2. push the root to initialize the deuqe
loop
3. get the size n of deque.
4. iterate the node to push its child, and then pop the noden which is pushed to result array n times.
*/