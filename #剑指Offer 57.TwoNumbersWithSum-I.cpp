class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //robust
        if(nums.size() < 2)
            return vector<int>();
        int size = nums.size();
        int i = 0, j = size - 1;   //i, j分别表示需要找出的的两个数的遍历下标
        while(i != j){
            if(nums[i] + nums[j] == target)
                return vector{nums[i], nums[j]};
            if(nums[i] + nums[j] < target)
                i++;
            if(nums[i] + nums[j] > target)
                j--;
        }
        return vector<int>();
    }
};
