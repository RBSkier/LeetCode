class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(times.size() == 0 || k > n)
            return -1;
        const int INF = std::numeric_limits<int>::max() / 2;
        /* 转换有向图表示形式 */
        vector<vector<int>> arc(n, vector<int>(n, INF));
        for(auto time: times)
        {
            int x = time[0] - 1;
            int y = time[1] - 1;
            arc[x][y] = time[2];
        }

        vector<int> distances(n, INF);
        vector<bool> visit(n, false);
        distances[k - 1] = 0;
        /* 主循环 */
        for(int i = 0; i < n; i++)
        {
            int min = INF;
            int w = -1;
            for(int v = 0; v < n; v++)   /* 遍历还没访问过的节点 */
                if(!visit[v] && (w == -1 || distances[v] < distances[w]))
                    w = v;
            visit[w] = true;
            for(int v = 0; v < n; v++)
                distances[v] = std::min(distances[v], distances[w] + arc[w][v]);
        }
        /* 从dist数组中找出最大值就是答案 */
        auto ans = std::max_element(distances.begin(), distances.end());
        return *ans == INF ? -1 : *ans;  
    }
};

