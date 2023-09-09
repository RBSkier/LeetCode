class Solution {
private:
    int findFirstIdx(vector<int>& nums, int target, int start, int end){
        if(start > end)
            return -1;
        int mid = (start + end) / 2;
        if(nums[mid] == target){
            if(mid == start || nums[mid - 1] < target)
                return mid;
            else
                return findFirstIdx(nums, target, start, mid - 1);
        }
        else if(nums[mid] < target)
            return findFirstIdx(nums, target, mid + 1, end);
        else
            return findFirstIdx(nums, target, start, mid - 1);
    }
    int findLastIdx(vector<int>& nums, int target, int start, int end){
        int mid = (start + end) / 2;
        if(nums[mid] == target){
            if(mid == end || nums[mid + 1] > target)
                return mid;
            else
                return findLastIdx(nums, target, mid + 1, end);
        }
        else if(nums[mid] < target)
            return findLastIdx(nums, target, mid + 1, end);
        else
            return findLastIdx(nums, target, start, mid - 1);
    }
public:
    int search(vector<int>& nums, int target) {
        //robust
        if(nums.empty())
            return 0;
        int size = nums.size();
        //找第一个k的下标
        int firstIdx = findFirstIdx(nums, target, 0, size - 1);
        if(firstIdx == -1)  //找不到该元素
            return 0;
        //找最后一个k的下标
        int lastIdx = findLastIdx(nums, target, 0, size - 1);
        return lastIdx - firstIdx + 1;
    }
};
