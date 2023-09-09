#include <string>
using namespace std;
class Solution {
private:
    int count = 0;
    void core(const string& numStr, int index, int size){
        if(index == size){
            count++;
            return;
        }
        if(numStr[index] == '0' || size - index < 2)
            core(numStr, index + 1, size);
        else if(size - index >= 2){
            string subNumStr = numStr.substr(index,2);//截取头两个数字
            if(stoi(subNumStr) <= 25){
                core(numStr, index + 2, size);
                core(numStr, index + 1, size);
            }else{  //数字大于25无效，只能选择截取一位数字
                core(numStr, index + 1, size);
            }
        }
    }
public:
    int translateNum(int num) {
        if(num < 0){    //robust
            return 0;
        }
        string numStr = to_string(num);
        int size = (int)numStr.size();
        core(numStr, 0, size); //递归函数
        return count;
    }
};

int main(){
    Solution solution;
    solution.translateNum(506);
}
