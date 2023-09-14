class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> indices = new HashMap<>();
        int left = 0, max_len = 0;
        for(int right = 0; right < s.length(); right++){
            if(indices.containsKey(s.charAt(right)))
                //一边右移left指针，一边删除相应的哈希记录
                left = Math.max(left, indices.get(s.charAt(right)) + 1);
            indices.put(s.charAt(right), right);
            max_len = Math.max(max_len, right - left + 1);        
        }
        return max_len;
    }
}
