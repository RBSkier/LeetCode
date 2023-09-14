class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //transfer vector to ordered set
        unordered_set<int> nums_set;
        for(auto num: nums){
            nums_set.insert(num);
        }
        int max_length = 0;
        for(auto num: nums){
            int length = 1;
            //make sure the num is the start of a consecutive sequence
            if(nums_set.count(num - 1) == 0){
                //if exist the next consecutive num
                while(nums_set.count(num + 1) == 1){
                    length++;
                    num++;
                }
                max_length = max(max_length, length);
            }
        }
        return max_length;
    }
};
