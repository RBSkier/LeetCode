#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //robust
        if(s.empty()){
            return 0;
        }
        int start = 0;
        unordered_set<char> charSet;
        int size = (int)s.length();
        int max = 0;
        //右指针的遍历
        for(int end = 0; end < size; end++){
            if(charSet.count(s[end]) == 0){
                charSet.insert(s[end]);
                if(max < (end - start + 1))
                    max = (end - start + 1);
                continue;
            }else{  //出现重复字符
                while(true){
                    if(s[start] != s[end]) {  //直到把重复字符删掉
                        charSet.erase(s[start++]);  //逐个剔除子串中重复字符前的所有字符
                    }else{
                        start++;
                        break;
                    }
                }
            }
        }
        return max;
    }
};

int main(){
    string s = "abcabcbb";
    Solution solution;
    solution.lengthOfLongestSubstring(s);
}