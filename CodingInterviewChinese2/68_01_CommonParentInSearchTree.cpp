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
    TreeNode* getNextNode(TreeNode* root, TreeNode* target){
        if (target -> val < root -> val)
            return root -> left;
        else if(target -> val > root -> val)
            return root -> right;
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr)
            return nullptr;
        TreeNode* result = root;
        TreeNode* cur1 = root;
        TreeNode* cur2 = root;
        while(true){
            cur1 = getNextNode(cur1, p);
            cur2 = getNextNode(cur2, q);
            if(cur1 == cur2)
                result = cur1;
            //如果已经遍历到p或q，结束循环
            if(cur1 == p && cur2 == q)
                break;
        }
        return result;
    }
};
/*
robust
O(n)寻找路径，最后一个相同的就是
空间也是O(logn)
*/
