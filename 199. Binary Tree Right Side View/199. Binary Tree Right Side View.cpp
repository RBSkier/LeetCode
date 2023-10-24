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

/**
递归实现
*/
class Solution {
private:
    vector<int> ret;
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ret;
    }
private:
    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(++depth > ret.size())
            ret.push_back(root->val);   //if the node is the iterated node of new level.
        dfs(root->right, depth);
        dfs(root->left, depth);
    }
};

//右子树优先的中序遍历，不断更新最深路径，如果比已知最深路径更深则放入结果列表，并使最大深度+1。

/**
迭代遍历
*/
class Solution {
private:
    vector<int> ret;
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        std::stack<TreeNode*> iter_queue;
        std::stack<int> depths;
        iter_queue.push(root);
        depths.push(0);

        while(iter_queue.size()){
            auto node = iter_queue.top(); iter_queue.pop();
            int depth = depths.top(); depths.pop();
            if(depth + 1 > ret.size())
                ret.push_back(node->val);
            if(node->left) {
                iter_queue.push(node->left);
                depths.push(depth + 1);
            }
            if(node->right) {
                iter_queue.push(node->right);
                depths.push(depth + 1);
            }  
        }
        return ret;
    }
};





