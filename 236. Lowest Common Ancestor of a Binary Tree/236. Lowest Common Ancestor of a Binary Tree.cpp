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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;

        auto ret1 = lowestCommonAncestor(root->left, p, q);
        auto ret2 = lowestCommonAncestor(root->right, p, q);
        // 如果当前节点命中，返回当前节点
        if(root == p || root == q) return root;
        // 如果左右都命中，则当前节点是最近公共节点
        else if(ret1 && ret2) return root;
        // 否则如果是左有值，继续传递左值
        else if(ret1 && !ret2) return ret1;
        // 否则如果是右有值，继续传递右值
        else if(ret2 && !ret1) return ret2;
        // 剩余情况返回null即可
        else return nullptr;
    }
};
