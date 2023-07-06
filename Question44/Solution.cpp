#include <cmath>

class Solution {
public:
    int findNthDigit(int n) {
        //鲁棒性
        if(n < 0){
            return -1;
        }
        if(n == 0){
            return 0;
        }
        int digit;
        double len = 0;
        int size = 1;
        while(true) {   //不断循环直到找到目标数字所在区间
            double part_len = 9 * pow(10, size - 1) * size;
            if (n < part_len + len)
                break;
            len += part_len;
            size++;
        }
        int rest_len = n - len; //找出目标数字在所在区间的偏移量
        int number = pow(10, size - 1) + ceil((double)rest_len / size) - 1;  //目标数字 = 区间头 + 偏移量
        int digit_idx = rest_len % size;
        //从目标number中提取目标digit
        if(digit_idx == 0){    //如果为0，表示刚好是某个数字的末尾
            digit = number % 10;
            return digit;
        }else{  //其余情况通过掐头去尾获得目标digit
            digit = number / pow(10, size - digit_idx); //去除数字中目标digit的右边部份
            digit = digit % 10; //去除数字中目标digit的左边部份
            return digit;
        }
    }
};
/* 规律
1-9: 9 * 10^0 * 1 = 9
10-99:9 * 10^1 * 2 = 180
100-999:9 * 10^2 * 3 = 2700
....

 要想知道单个digit是什么，首先要知道digit所属的整个number是什么，然后通过offset定位刀number中的特定某个digit。
 */