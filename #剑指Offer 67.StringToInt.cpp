class Solution {
public:
    int strToInt(string str) {
        if(str.length() == 0)
            return 0;

        long int result = 0;
        int cur = 0;
        char symbol = 0;
        //跳过空格
        while(str[cur] != '\0' && str[cur] == ' ')
            cur++;
        //提取符号
        if(str[cur] != '\0' && (str[cur] == '+' || str[cur] == '-')){
            symbol = str[cur];
            cur++;
        }
        //如果开头不是有效数字，结束
        if(str[cur] != '\0' && (str[cur] < '0' || str[cur] > '9'))
            return 0;
        while(str[cur] != '\0' && ('0' <= str[cur] && str[cur] <= '9')){
            int digit = str[cur] - '0';
            result = result * 10 + digit;
            if(symbol != '-' && result > INT32_MAX)
                return INT32_MAX;
            if(symbol == '-' && result > -(long int)INT32_MIN)
                return INT32_MIN;
            cur++;
        }

        if(symbol == '-')   
            return -result;
        else
            return result;
    }
};

/*
把字符串转换成整数
1.丢弃无用的开头空格字符
2.将该符号与之后面尽可能多的连续数字组合起来，作为该整数的正负号
3.假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成整数

假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换

默认返回0
*/
