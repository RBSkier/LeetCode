class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        //枚举k
        for(int k = 0; k < length - 2; k++){
            //跳过连续重复的nums[k]
            if(k > 0 && nums[k] == nums[k-1])   continue;
            int i = k + 1, j = length - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(sum < 0)
                    while(i < j && nums[i] == nums[++i]);
                else if(sum > 0)
                    while(i < j && nums[j] == nums[--j]);
                else{
                    result.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
            }
        }
        return result;
    }
};

/*
算法加速：
1. 避免重复：
第二重循环枚举到的元素不小于当前第一重循环枚举到的元素。
第三重循环枚举到的元素不小于当前第二重循环枚举到的元素。
也就是说，我们枚举的三元组 (a,b,c)(a, b, c)(a,b,c) 满足a≤b≤c，保证了只有 (a,b,c)这个顺序会被枚举到，而 (b,a,c)、(c,b,a）等等这些不会。但依然跳不出O(n^3)的量级。
2. 跳过必定无效的解
通过双指针使第二第三重循环变为并列关系。使第二第三重循环的O(n^2)变为O(n)。总的也就从O(n^3)降到了O(n^2)。
*/

