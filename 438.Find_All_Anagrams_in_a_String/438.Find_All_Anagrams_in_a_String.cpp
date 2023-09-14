class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length())
            return vector<int>();
        int unmatch_count = p.length();
        int p_array[26] = {0};
        vector<int> result;
        //initialize two array for comparison
        for(int i = 0; i < p.length(); i++){
            p_array[p[i] - 'a']--;  //--表示缺什么字母1次
            p_array[s[i] - 'a']++;
        }]
        //examine the first window
        int different = 0;
        for(int i = 0; i < 26; i++){
            if(p_array[i] != 0)    different++;
        }
        if(different == 0)  result.emplace_back(0);
        //sliding window
        for(int i = 0; i < s.length() - p.length(); i++){
            //窗口左边弹出一个元素
            if(p_array[s[i] - 'a'] == 0)    different++;
            else if(p_array[s[i] - 'a'] == 1)   different--;
            p_array[s[i] - 'a']--;
            //窗口右边插入一个新元素
            int index = s[i + p.length()] - 'a';
            if(p_array[index] == -1){
                different--;
            }else if(p_array[index] == 0){
                different++;
            }
            p_array[index]++;
            //检查新子串是否匹配
            if(different == 0)
                result.emplace_back(i + 1);
        }
        return result;
    }
};
