class Solution {
    public List<Integer> partitionLabels(String s) {
        int[] last = new int[26];
        int length = s.length();
        HashMap<Character, Integer> farIndeces = new HashMap<>();
        for (int i = 0; i < length; i++) {
            last[s.charAt(i) - 'a'] = i;
        }

        int start = 0, end = 0;
        ArrayList<Integer> ret = new ArrayList<>();
        for(int i = 0; i < s.length(); i++){
            end = Math.max(end, last[s.charAt(i) - 'a']);
            if(i == end){
                ret.add(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
}
