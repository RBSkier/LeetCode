class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.size() == 0)   //锻炼robust
            return vector<int>();

        unordered_map<char, int> farIndeces;
        for(int i = 0; i < s.size(); i++)
            farIndeces[s[i]] = i;

        int start = 0, end = 0;
        vector<int> ret;
        for(int i = 0; i < s.size(); i++){
            int farIndex = farIndeces[s[i]];
            end = max(end, farIndex);
            if(i == end){
                ret.push_back(end - start + 1);
                start = end + 1;
                end = start;
            }  
        }
        return ret;
    }
};

/*
遍历一次，通过哈希表记录每个字母的最远位置，key为字母，value为下标，如果遇到重复，就用重复的。

第二次遍历时，通过哈希map查找同字母最远距离，如果不为当前位置，则暂定目前片段的最短划分是到，如果走到了尽头，就割开作为最短片段。

创建变量hashmap，
遍历字母
    写入自身位置

设定当前片段起点，设定当前片段的最远距离为自身。
遍历字母
    从hashmap中查找自身的最远坐标
    将该坐标与片段终点做比较，取大者
    如果已经到达片段终点，将长度写入结果vector, 更新片段起点和终点为+1
*/