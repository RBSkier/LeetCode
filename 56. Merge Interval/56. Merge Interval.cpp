class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto a, auto b)->bool{ 
                return a[0] < b[0]; 
            });
        vector<vector<int>> output;
        output.push_back(intervals[0]);    //初始化输出列表
        for(int i = 1; i < intervals.size(); i++){
            //如果左值在上一个区间范围内
            if(intervals[i][0] >= output.back()[0] 
                    && intervals[i][0] <= output.back()[1]) {
                if(intervals[i][1] > output.back()[1])
                    output.back()[1] = intervals[i][1];
            }else{
                output.push_back(intervals[i]);
            }
        }

        return output;
    }
};

