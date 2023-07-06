#include <cmath>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        //鲁棒性
        if(n <= 0){
            return 0;
        }

        int factor = 0, sum = 0;
        for(int index = 0; n > 0; index++){
            int idx_val = n % 10;
            n = n / 10;
            int count = factor * idx_val +  + (int)pow(10,index);
            sum += count;   //累加0到该位出现的1的次数
            factor += factor * 9 + (int)pow(10,index);; // 更新下次循环的因子
        }

        return sum;
    }
};

// 0-9: 1

// 10-99: 1(因子)*9(本位) + 10 = 19
// 0-99: 1 + 19 = 20

// 100-999: 20*9 + 100 = 280
// 0-999: 20 + 280 = 300

// 1000-9999: (300)*9 + 1000 = 3700
// 0-9999: 300 + 3700 = 4000

// 10000-99999: (20 + 300 + 4200)*10 + 10000 =

// 下一位的因子 = 本位因子 * 9 + 10 *（本位位数-1） + 因子

// 变量：因子、当前位key（0开始）、当前位值value、sum、
