class Solution {

    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> hashmap = new HashMap();
        for(int i=0;i<=nums.length-1;i++){
            if(hashmap.containsKey(target - nums[i])){
                return new int[]{hashmap.get(target - nums[i]),i};
            }
            hashmap.put(nums[i],i);
        }
        return new int[0];
    }
}