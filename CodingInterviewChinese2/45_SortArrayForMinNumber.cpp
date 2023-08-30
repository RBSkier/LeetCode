#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        //robust
        if(nums.empty())
            return "";
        vector<string> strs;
        string ret;
        for(int num: nums){
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), [](string& x, string& y){ return x + y < y + x; });
        for(string str: strs)
            ret.append(str);
        return ret;
    }
};

int main(){
    Solution solution;
    vector<int> nums;// = {2,3,4};
    nums.push_back(1);
    solution.minNumber(nums);
}