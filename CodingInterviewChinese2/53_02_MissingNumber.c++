class Solution {
private:
    int core(vector<int>& nums, int start, int end, int size){
        if(start > end)
            return start;

        int mid = (start + end) / 2;
        if(nums[mid] > mid)    //缺失数字在左边
            // if(mid == start)   //已经到达左边界
            //     return nums[mid] - 1;   //可以确认缺失数字
            // else
                return core(nums, start, mid - 1, size);
        else    //缺失数字在右边
            // if(mid == end)  
            //     return nums[mid] + 1;   //如果已经到达右边界，说明缺失数字为
            // else
                return core(nums, mid + 1, end, size);  //否则继续二分查找
    }
public:
    int missingNumber(vector<int>& nums) {
        //robust
        if(nums.empty())
            return -1;
        int size = nums.size();
        return core(nums, 0, size - 1, size);
    }
};

//边界条件，只有一个数字
