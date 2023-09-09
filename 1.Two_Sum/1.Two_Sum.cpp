class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_nums;
        for(int i = 0; i < nums.size(); i++){
            int reminder = target - nums[i];
            auto it = hash_nums.find(reminder);
            if(it != hash_nums.end()){
                return {it->second, i};
            }
            hash_nums[nums[i]] = i;
        }
        
        return {};
    }
};

//该题因为nums中有重复的num，所以如果用unordered_map，不能全部放进去以后再做遍历，两个重复的num组成的答案没办法检索出来。所以要一边插入一边判断，而且这样效率也更高。