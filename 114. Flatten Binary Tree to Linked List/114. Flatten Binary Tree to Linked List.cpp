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

//方法一：寻找右子树的前驱节点
class Solution {
public:
    void flatten(TreeNode* root) {
        for(auto cur = root; cur; cur = cur->right){
            if(!cur->left) continue;
            auto pre = cur->left;
            while(pre->right)
                pre = pre->right;
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
    }
};


//方法二：变体后序遍历，递归遍历
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        //postorder traversal variant.
        flatten(root->right);
        flatten(root->left);
        root->right = pre;
        root->left = nullptr;
        pre = root;
    }
private:
    TreeNode* pre = nullptr;
};