class Solution {
private:
    typedef int (Solution::*func)(int);
    const func Array[2];
public:
    //构造前初始化Array函数指针数组
    Solution() : Array{&Solution::sumNums, &Solution::sumNumsEnd} {}

    int sumNumsEnd(int n){
        return 0;
    }
    int sumNums(int n) {
        return n + (this->*Array[!n])(n-1);
    }
};
