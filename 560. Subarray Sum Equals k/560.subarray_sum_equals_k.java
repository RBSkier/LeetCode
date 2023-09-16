class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        int pre = 0;    //记录当前遍历时前缀和的大小
        Map<Integer, Integer> sum_map = new HashMap<>();
        sum_map.put(0, 1); //使子序列以0下标开始时，能找到一个解
        for(var num: nums){
            pre += num;
            count += sum_map.getOrDefault(pre - k, 0);
            //当前遍历结束以后当新前缀和插入hash table
            sum_map.put(pre, sum_map.getOrDefault(pre, 0) + 1);
        }
        return count;
    }
}