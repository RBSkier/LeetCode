class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_table;
        for(auto str: strs){
            string key = str;
            sort(key.begin(), key.end());
            hash_table[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto element: hash_table){
            result.push_back(element.second);
        }
        return result;
    }
};


