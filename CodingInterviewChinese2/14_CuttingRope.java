class Solution {
    public int cuttingRope(int n) {
        int[] opt = new int[n + 1];
        opt[0] = 0; opt[1] = 0;
        for(int i = 2; i <= n; i++){
            int max = 0;
            for(int j = 1; j < i; j++){
                int product1= j * opt[i-j];
                int product2 = j * (i-j);
                int max_product = (product1 > product2) ? product1 : product2;
                max = (max_product > max) ? max_product:max;
            }
            opt[i] = max;
        }
        return opt[n];
    }
}