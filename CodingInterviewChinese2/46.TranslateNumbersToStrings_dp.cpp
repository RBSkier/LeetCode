#include <string>
using namespace std;
/*
 * 动态规划迭代写法
 */
class Solution {
public:
    int translateNum(int num) {
        string numStr = to_string(num);
        int n = (int)numStr.size();
        int dp[n + 1];
        dp[0] = 1, dp[1] = 1;   //边界条件
        for(int i = 2; i <= n; i++){
            string subNumStr = numStr.substr(i - 2,2);
            if(stoi(subNumStr) >= 10 && stoi(subNumStr) <= 25)
                dp[i] = dp[i - 1] + dp[i - 2];
            else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};

int main(){
    Solution solution;
    solution.translateNum(12258);
}
