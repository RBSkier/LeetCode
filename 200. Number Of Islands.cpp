class Solution {
public:
    int count = 0;
    int rowSize = 0;
    int columSize = 0;

    void dfs(int i, int j, vector<vector<char>>& grid){
        grid[i][j] = '0';
        if(i-1 >= 0 && grid[i-1][j] == '1') dfs(i-1, j, grid);
        if(i+1 < rowSize && grid[i+1][j] == '1')   dfs(i+1, j, grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') dfs(i, j-1, grid);
        if(j+1 < columSize && grid[i][j+1] == '1') dfs(i, j+1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        rowSize = grid.size();
        columSize = grid[0].size();
        for(int i = 0; i < rowSize; i++){
            for(int j = 0; j < columSize; j++){
                if(grid[i][j] == '1'){
                    count++;
                    dfs(i, j, grid);
                }
            }
        }
        return count;
    }
};

//如果找到1号点，就按照上下左右的顺序递归迭代