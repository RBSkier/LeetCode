class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
        for(var str: strs){
            char[] charArrayKey = str.toCharArray();
            Arrays.sort(charArrayKey);
            String key = new String(charArrayKey);
            //取出key对应的stringList，如果没有则创建一个新的
            List<String> stringList = map.getOrDefault(key, new ArrayList<String>());
            //在stringList中添加新的string以后重新放回哈希表中
            stringList.add(str);
            map.put(key, stringList);
        }
        
        return new ArrayList<List<String>>(map.values());
    }
}
