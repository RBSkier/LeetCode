class Solution {
    public double myPow(double x, int n) {
        double t = n > 0? x: 1.0/x, result = 1.0;
        if(n == Integer.MIN_VALUE){
            result = t;
            for(int i = 0; i < 31; ++i) result *= result;
        }else{
            n = Math.abs(n);
            while(n > 0){
                if(n % 2 != 0){
                    result *= t;
                }
                t *= t;
                n = (n >> 1);
            }
        }

        return result;
    }
}