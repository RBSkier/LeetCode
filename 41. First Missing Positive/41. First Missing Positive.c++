class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            //if the num is within [1, n] and has not been place at the correct position yet.
            while(1 <= nums[i] && nums[i] <= n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i] - 1]);
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
};