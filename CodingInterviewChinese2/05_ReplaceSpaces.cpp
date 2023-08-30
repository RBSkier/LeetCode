class Solution {
public:
    string replaceSpace(string s) {
        string str;
        for(int i = 0;i<s.size();i++){
            s[i]==' '?str+="%20":str+=s[i];

    }
    return str;
    }
};