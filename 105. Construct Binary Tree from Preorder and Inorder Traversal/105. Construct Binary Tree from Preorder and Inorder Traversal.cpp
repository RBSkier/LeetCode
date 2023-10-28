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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < inorder.size(); i++){
            inorderIndex[inorder[i]] = i;
        }
        return buildTreeCore(preorder, inorder, 0, n - 1, 0, n -1);
    }

private:
    TreeNode* buildTreeCore(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight){
        if(preLeft > preRight) 
            return nullptr;
        // get the index of root in inorder array.
        int inRoot = inorderIndex[preorder[preLeft]];
        // create root node.
        auto root = new TreeNode(preorder[preLeft]);
        // get the length of left subtree.
        int len = inRoot - inLeft;
        // build left and right subtree.
        root->left = buildTreeCore(preorder, inorder, 
            preLeft + 1, preLeft + len, 
            inLeft, inRoot - 1);
        root->right = buildTreeCore(preorder, inorder, 
            preLeft + len + 1, preRight, 
            inRoot + 1, inRight);
        return root;
    }

private:
    unordered_map<int, int> inorderIndex;
};
