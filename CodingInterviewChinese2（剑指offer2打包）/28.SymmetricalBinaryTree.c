/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool twoSubTreeIsSymmetric(struct TreeNode* A, struct TreeNode* B){
    if((A && !B) || (!A && B))
        return false;
    if(!A && !B){
        return true;
    }

    return A->val == B->val && twoSubTreeIsSymmetric(A->left, B->right) && twoSubTreeIsSymmetric(A->right, B->left);
}

bool isSymmetric(struct TreeNode* root){
    if(!root)
        return true;

    return twoSubTreeIsSymmetric(root->left, root->right);
}

