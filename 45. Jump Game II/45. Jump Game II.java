class Solution {
    public int jump(int[] nums) {
        if(nums.length == 1)  //robust
            return 0;
        int step = 0, end = 0, next_end = 0;
        for(int i = 0; i < nums.length - 1; i++){     //只需要到n-1是因为如果在n-1的时候还需要跳，步数会+1，并且一定能达到n。到n点以后就不需要跳了，排除掉。
            next_end = Math.max(next_end, i + nums[i]);
            if(i == end){
                end = next_end;
                step++;
            }
        }
        return step;
    }
}
