/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* levelOrder(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if(!root){
        return NULL;
    }

    struct TreeNode** queue = malloc(sizeof(struct TreeNode) * 1000);
    int front = 0, rear = 0;
    int* ret = calloc(1000, sizeof(int));

    queue[rear++] = root;
    while(front < rear){
        ret[front] = queue[front]->val;
        (*returnSize)++;
        if(queue[front]->left){
            queue[rear++] = queue[front]->left;
        }
        if(queue[front]->right){
            queue[rear++] = queue[front]->right;
        }
        front++;
    }

    return ret;
}