#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        //robust
        if(n <= 0)
            return -1;
        int dp[n+1];
        int a = 1, b = 1, c = 1;    //a,b,c记录三个下标，分别对应质因子2，3，5相乘后刚好大于dp中最大值的下标。
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int n1 = dp[a] * 2, n2 = dp[b] * 3, n3 = dp[c] * 5;
            dp[i] = min(min(n1, n2), n3);
            if(n1 == dp[i])  a++;
            if(n2 == dp[i])  b++;
            if(n3 == dp[i])  c++;
        }
        return dp[n];
    }
};

int main(){
    Solution solution;
    solution.nthUglyNumber(100);
}