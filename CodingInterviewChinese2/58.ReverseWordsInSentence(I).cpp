class Solution {
public:
    string reverseWords(string s) {
        //整体翻转字符串
        reverse(s.begin(), s.end());
        
        int idx = 0;    //填充原始字符串的下标
        int n = s.size();
        for(int start = 0; start < n; ++start){
            if(s[start] == ' ') continue;

            //找到新的非空格字符，添空格分隔
            if(idx != 0)    s[idx++] = ' '; 
            
            //填充单词
            int end = start;
            while(end < n && s[end] != ' ') 
                s[idx++] = s[end++];
            
            //反转填充后的单词
            reverse(s.begin() + idx - (end - start), s.begin() + idx); //注意是翻转填入新位置后的区间
            
            //更新start，找下一个单词
            start = end;
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};