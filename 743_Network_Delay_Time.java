class Solution {
    public int networkDelayTime(int[][] times, int n, int k) 
    {
        if(times == null || k > n)
            return -1;
        final int INF = Integer.MAX_VALUE / 2;
        int[][] arc = new int[n][n];    /* 转换有向图表示形式 */
        for(int[] array: arc)
            Arrays.fill(array, INF);
        for(var time: times)
        {
            int x = time[0] - 1;
            int y = time[1] - 1;
            arc[x][y] = time[2];
        }

        int[] distances = new int[n];
        Arrays.fill(distances, INF);
        boolean[] visit = new boolean[n];
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
                distances[v] = Math.min(distances[v], distances[w] + arc[w][v]);
        }
        /* 从dist数组中找出最大值就是答案 */
        int ans = Arrays.stream(distances).max().getAsInt();
        return ans == INF ? -1 : ans;
    }
}