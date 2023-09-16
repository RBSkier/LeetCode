class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int pre = 0;    //记录当前遍历时前缀和的大小
        unordered_map<int, int> sum_map;
        sum_map[0] = 1; //使子序列以0下标开始时，能找到一个解
        for(auto num: nums){
            pre += num;
            count += sum_map[pre - k];
            //当前遍历结束以后当新前缀和插入hash table
            sum_map[pre]++;
        }
        return count;
    }
};
