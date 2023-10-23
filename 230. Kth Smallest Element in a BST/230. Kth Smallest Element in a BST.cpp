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
    int ret = -1;
    int count = 0;
    void inOrderTraversal(TreeNode* root, int k){
        if(!root) return;   //递归结束条件
        inOrderTraversal(root->left, k);    //遍历左子树
        if(++count == k) ret = root->val;   //判断是否为当前节点
        inOrderTraversal(root->right, k);   //遍历右子树
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return ret;
    }
};

//所有节点都访问一遍，所以时间复杂度是O(N)。
//最好情况二叉查找树只有logN层，空间复杂度为O(logN)。最坏情况二叉树退化成链表，递归需要N层，需要O(N)空间复杂度。