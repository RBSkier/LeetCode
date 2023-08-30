/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool PreOrderTraverse(struct TreeNode* A, struct TreeNode* B){
    if(!B)   return true;
    if(!A)   return false;

    return A->val == B->val && PreOrderTraverse(A->left, B->left) && PreOrderTraverse(A->right, B->right);
}

bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if(A == NULL || B == NULL)  return false;

    return PreOrderTraverse(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}
