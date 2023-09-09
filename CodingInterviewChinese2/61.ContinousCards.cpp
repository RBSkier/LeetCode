class Solution {
public:
    bool isStraight(vector<int>& nums) {
        if(nums.size() != 5)
            return false;
        sort(nums.begin(), nums.end());

        int zero_count = 0;
        int idx = 0;
        for(; nums[idx] != 0; idx++)
            zero_count++;
        
        int pre = nums[idx];
        while(++idx < nums.size()){
            if(nums[idx] == pre + 1){
                pre = nums[idx];
                continue;
            }
            else if(nums[idx] > pre + 1){
                int gap = nums[idx] - pre - 1;
                if(zero_count >= gap){
                    zero_count -= gap;
                    pre = nums[idx];
                    continue;
                }else
                    return false; 
            }else
                return false;
        }

        return true;    //if nums has been itertated completely
    }
};

// nlogn排序
// 如果遇到0，先记录0的次数
// 看看cur是否等于pre+1
//     大于pre+1的话，差值是多少，扣除相应的0次数
//         够扣的话就继续，不够扣就输出失败。
//     等于的话，继续

// 全部遍历结束就输出为顺子
