class Solution {
    public int findRepeatNumber(int[] nums) {
        int n = nums.length;
        int i = 0;
        while (i != n) {
            // 向后的条件 数组下标=数组下标对应的值
            if (i == nums[i]) {
                ++i;
                continue;
            }
            // 说明有重复的，如nums[i] 和 i 都是同一个值 比方说nums[6] = nums[5] = 5
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            } else {
                // 交换数组下标值它对应的下标值 如nums[0] = 1, 则将nums[0] 与 nums[1]交换
                int temp = nums[nums[i]];
                nums[nums[i]] = nums[i];
                nums[i] = temp;
            }
        }
        return -1;

    }
}

