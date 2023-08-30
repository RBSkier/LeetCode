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
    vector<int> ordArray;
    void midOrder(TreeNode* node, int k){
        if(!node)
            return;
        midOrder(node->right, k);
        ordArray.push_back(node->val);
        midOrder(node->left, k);
    }
public:
    int kthLargest(TreeNode* root, int k) {
        //robust
        if(root == NULL || k <= 0)
            return -1;
        midOrder(root, k);
        return ordArray[k - 1];
    }
};