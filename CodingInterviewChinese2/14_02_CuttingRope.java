class Solution {
    public static int cuttingRope(int n) {
        long a, b, x, mode, rem;

        if(n <=3) return n-1;

        mode = 1000000007;
        a = n / 3;
        b = n % 3;
        x = 3;
        rem = 1;
        //循环求余公式，b == 1代表余数为1的时候，需要单独取出一个3出来凑成2*2达到最大值效果
        for(int i = 0; i < ((b == 1)?a-1:a); i++){
            rem = (rem * x) % mode;
        }

        if(b == 0){
            return (int)rem;
        }else if(b == 1){
            return (int)((rem * 4) % mode);
        }else{
            return (int)((rem * 2) % mode);
        }
    }
}
