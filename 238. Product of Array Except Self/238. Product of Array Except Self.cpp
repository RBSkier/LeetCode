class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        long prefix[n], suffix[n];
        vector<int> ans(n);
        //make the prefix and suffix array.
        prefix[0] = nums[0], suffix[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] * nums[i];
        }
        for(int i = n - 2; i >= 0; i--){
            suffix[i] = suffix[i + 1] * nums[i];
        }
        //make the ans array
        for(int i = 0; i < n; i++){
            if(i == 0)  ans[i] = suffix[1];
            else if(i == n-1)  ans[i] = prefix[n - 2];
            else{
                ans[i] = prefix[i - 1] * suffix[i + 1];
            }
        }
        return ans;
    }
};
/*
array
1 2 3 4
prefix mutiply
1 2 6 24
suffix mutiply
24 24 12 4
*/
