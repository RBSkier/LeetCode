class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> indices;
        int left = 0, max_len = 0;
        for(int right = 0; right < s.size(); right++){
            if(indices.count(s[right]))
                //一边右移left指针，一边删除相应的哈希记录
                left = max(left, indices[s[right]] + 1);	//哈希表中有残留的一批字母没清理，残留的部份通过max就不会更新到left。也可以循环erase掉哈希表项，但效率慢一点。
            indices[s[right]] = right;
            max_len = max(max_len, right - left + 1);        
        }
        return max_len;
    }
};
