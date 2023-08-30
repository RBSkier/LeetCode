/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct stack{
    int top;
    struct TreeNode* data[1000];
}Stack;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAXSIZE 2000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if(!root){
        return NULL;
    }
    
    int odd = 1;
    Stack odd_stack = {-1,{}}, even_stack= {-1,{}};
    *returnColumnSizes = calloc(MAXSIZE, sizeof(int));
    int** ret = calloc(MAXSIZE, sizeof(int*));

    //初始化第一个栈
    odd_stack.data[++(odd_stack.top)] = root;
    Stack* pStack1, *pStack2;
    while(odd_stack.top >= 0 || even_stack.top >= 0){
        if(odd == 1){
            pStack1 = &odd_stack, pStack2 = &even_stack;
        }else{
            pStack1 = &even_stack, pStack2 = &odd_stack;
        }

        int* level_arr = calloc(MAXSIZE, sizeof(int));
        int colSize = 0;
        while(pStack1->top >= 0){
            level_arr[colSize++] = pStack1->data[pStack1->top]->val;
            if(odd == 1){
                if(pStack1->data[pStack1->top]->left){
                    pStack2->data[++pStack2->top] = pStack1->data[pStack1->top]->left;
                }
                if(pStack1->data[pStack1->top]->right){
                    pStack2->data[++pStack2->top] = pStack1->data[pStack1->top]->right;
                }
            }else{
                if(pStack1->data[pStack1->top]->right){
                    pStack2->data[++pStack2->top] = pStack1->data[pStack1->top]->right;
                }
                if(pStack1->data[pStack1->top]->left){
                    pStack2->data[++pStack2->top] = pStack1->data[pStack1->top]->left;
                }
            }
            pStack1->top--;
        }

        odd = (odd + 1) % 2;
        ret[*returnSize] = level_arr;
        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize)++;
    }

    return ret;
}

























