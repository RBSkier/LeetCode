class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set(nums.begin(), nums.end());
        int max_length = 0;
        for(auto num: nums){
            if(nums_set.count(num - 1) == 0){
                int length = 1;
                while(nums_set.count(++num))
                    length++;
                max_length = max(max_length, length);
            }
        }
        return max_length;
    }
};