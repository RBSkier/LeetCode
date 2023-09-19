class Solution {
    public int longestConsecutive(int[] nums) {
        //transfer vector to ordered set
        Set<Integer> nums_set = new HashSet<>();
        for(var num: nums){
            nums_set.add(num);
        }
        int max_length = 0;
        for(var num: nums){
            int length = 1;
            //make sure the num is the start of a consecutive sequence
            if(!nums_set.contains(num - 1)){   
                //if exist the next consecutive num
                while(nums_set.contains(num + 1)){
                    length++;
                    num++;
                }
                max_length = Math.max(max_length, length);
            }
        }
        return max_length;
    }
}
