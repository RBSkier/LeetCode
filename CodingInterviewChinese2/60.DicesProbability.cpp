class Solution {
public:
    vector<double> dicesProbability(int n) {
        if(n <= 0)
            return vector<double>();

        vector<double> dp(6, 1.0/6.0);    //base case
        for(int i = 2; i <= n; i++){
            //创建dp二维数组的下一行
            vector<double> tmp(5 * i + 1, 0);
            //正向递推
            for(int j = 0; j < dp.size(); j++){
                for(int k = 0; k < 6; k++)
                    tmp[k + j] += dp[j] / 6.0;  
            }
            dp = tmp;   //更新dp旧行为当前行，为下一次迭代使用
        }
        
        return dp;
    }
};

//dp(n, y)表示n个骰子中总和为x的组合概率
//状态转移方程：dp(n, x) = 1/6 * (dp(n - 1, x -1) + dp(n - 1,  x - 2) +…+ dp(n - 1, x - 6))
//
//If n > x - i , return 0 或者 正向迭代
//
//Basd:
//dp(1, 1) = 1/6
//dp(1, 2) = 1/6
//dp(1, 3) = 1/6
//…
//由于每次迭代都只需要用到旧一行dp的数据，所以不需要创建一个完整的n*n的二维数组，因此空间只需要O(n)

