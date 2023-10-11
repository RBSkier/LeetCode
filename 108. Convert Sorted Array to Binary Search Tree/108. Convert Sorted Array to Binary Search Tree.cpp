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
    TreeNode* core(int l, int r, std::vector<int>& nums){
        if(l > r) return nullptr;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]); //use the middle num as the root value.
        root->left = core(l, mid-1, nums); // create left subtree and append the root node.
        root->right = core(mid+1, r, nums); // create right subtree and append the root node.
        return root;
    }
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return core(0, nums.size()-1, nums);
    }
};
