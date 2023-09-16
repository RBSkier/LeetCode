class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int length = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();
        //枚举k
        for(int k = 0; k < length - 2; k++){
            //跳过连续重复的nums[k]
            if(k > 0 && nums[k] == nums[k-1])   continue;
            int i = k + 1, j = length - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                if(sum < 0)  
                    while(i < j && nums[i] == nums[++i]);
                else if(sum > 0)    
                    while(i < j && nums[j] == nums[--j]);
                else{
                    result.add(new ArrayList<Integer>(Arrays.asList(nums[k], nums[i], nums[j])));
                    while(i < j && nums[i] == nums[++i]);
                    while(i < j && nums[j] == nums[--j]);
                }
            }
        }
        return result;
    }
}
