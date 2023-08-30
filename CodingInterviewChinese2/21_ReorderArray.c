

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    int a = 0;
    int b = numsSize - 1;
	while(a < b){
        while(a < b && nums[a] % 2 != 0){
            a++;
        }
        while(a < b && nums[b] % 2 == 0){
            b--;
        }
        
        if(a < b){
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
            a++;
            b--;
        }
    }
    *returnSize = numsSize;
    return  nums;
                
}
