class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i++){
            //if the num is within [1, n] and has not been place at the correct position yet.
            while(1 <= nums[i] && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                //note: please make sure that change the nums[nums[i] - 1] first, because it relies on the origin nums[i] value.
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        //find out the first missing positive integer within [1, n]
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        //if the missing positive integer is not within [1, n], means the answer is n+1.
        return n + 1;
    }
}
