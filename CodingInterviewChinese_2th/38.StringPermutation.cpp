class Solution {
public:
    vector<string> rec;
    vector<int> vis;
    void backtrack(const string& s, int i, int n, string& str) {
        if (i == n) {
            rec.push_back(str);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (vis[j] || (j > 0 && !vis[j - 1] && s[j - 1] == s[j])) {
                continue;
            }
            vis[j] = true;
            str.push_back(s[j]);
            backtrack(s, i + 1, n, str); //在获取第二个空位的值，然后用vis标记已经被选过的原始串槽位
            str.pop_back();
            vis[j] = false; //回溯以后，下一次循环会在第一个空位用原始串第二个字符，而且后续递归过程中第一个字符是可选的
        }
    }

    vector<string> permutation(string s) {
        int n = s.size();
        vis.resize(n);
        sort(s.begin(), s.end());   //排序后方便跳过重复元素
        string str;
        backtrack(s, 0, n, str);
        return rec;
    }
};