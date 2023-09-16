class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length];
        int largest_sum = 0;
        for(int i = 0; i < nums.length; i++){
            if(i == 0){
                dp[i] = nums[i];
                largest_sum = nums[i];
                continue;
            }else{
                if(dp[i-1] <= 0){
                    dp[i] = nums[i];
                }else{
                    dp[i] = dp[i-1] + nums[i];
                }
                largest_sum = Math.max(largest_sum, dp[i]);
            }
        }
        return largest_sum;
    }
}
