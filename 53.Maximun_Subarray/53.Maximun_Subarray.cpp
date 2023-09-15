class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        int largest_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                dp[i] = nums[i];
                largest_sum = nums[i];
                continue;
            }else{
			//if the largest suffix sum of index i - 1 smaller than 0, means the largest sum of i must be itself.
                if(dp[i-1] <= 0){
                    dp[i] = nums[i];
                }else{
                    dp[i] = dp[i-1] + nums[i];
                }
                largest_sum = std::max(largest_sum, dp[i]);
            }
        }
        return largest_sum;
    }
};
