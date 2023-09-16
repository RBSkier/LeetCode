class Solution {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> hash_nums = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            int reminder = target - nums[i];
            if(hash_nums.containsKey(reminder)){
                return new int[]{hash_nums.get(reminder), i};
            }
            hash_nums.put(nums[i], i);
        }

        return new int[]{};
    }
}