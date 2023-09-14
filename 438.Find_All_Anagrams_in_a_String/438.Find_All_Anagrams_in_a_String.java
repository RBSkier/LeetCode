class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if(s.length() < p.length())
            return new ArrayList<Integer>();
        int unmatch_count = p.length();
        int[] p_array = new int[26];
        List<Integer> result = new ArrayList<>();
        //initialize two array for comparison
        for(int i = 0; i < p.length(); i++){
            p_array[p.charAt(i) - 'a']--;  //--表示缺什么字母1次
            p_array[s.charAt(i) - 'a']++;
        }
        //examine the first window
        int different = 0;
        for(int i = 0; i < 26; i++){
            if(p_array[i] != 0)    different++;
        }
        if(different == 0)  result.add(0);
        //sliding window
        for(int i = 0; i < s.length() - p.length(); i++){
            //窗口左边弹出一个元素
            if(p_array[s.charAt(i) - 'a'] == 0)    different++;
            else if(p_array[s.charAt(i) - 'a'] == 1)   different--;
            p_array[s.charAt(i) - 'a']--;
            //窗口右边插入一个新元素
            int index = s.charAt(i + p.length()) - 'a';
            if(p_array[index] == -1){
                different--;
            }else if(p_array[index] == 0){
                different++;
            }
            p_array[index]++;
            //检查新子串是否匹配
            if(different == 0)
                result.add(i + 1);
        }
        return result;
    }
}
