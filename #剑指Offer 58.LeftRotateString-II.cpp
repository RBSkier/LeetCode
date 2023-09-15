class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if(n == 0)  return s;

        //先将字符串全部翻转
        reverse(s.begin(), s.end());
        //分别反转两个部分的字符串，其中后面部份字符串为需要左旋的字符串
        reverse(s.begin(), s.end() - n);
        reverse(s.end() - n, s.end());
        return s;
    }
};
