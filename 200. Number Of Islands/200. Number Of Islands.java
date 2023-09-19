class Solution {
    private int count = 0;
    private int rowSize = 0;
    private int columSize = 0;

    private void dfs(int i, int j, char[][] grid){
        grid[i][j] = '0';
        if(i-1 >= 0 && grid[i-1][j] == '1') dfs(i-1, j, grid);
        if(i+1 < rowSize && grid[i+1][j] == '1')   dfs(i+1, j, grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') dfs(i, j-1, grid);
        if(j+1 < columSize && grid[i][j+1] == '1') dfs(i, j+1, grid);
    }
    public int numIslands(char[][] grid) {
        if(grid.length == 0)
            return 0;
        
        rowSize = grid.length;
        columSize = grid[0].length;
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
}


