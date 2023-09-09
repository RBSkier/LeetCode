public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int i, count;

        count = 0;
        for(i = 0; i < 32; i++){
            if((n & (1 << i)) != 0){
                count++;
            }
        }
        return count;
    }
}