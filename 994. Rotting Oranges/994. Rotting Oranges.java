class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        Deque<int[]> rotten = new ArrayDeque<>();
        int fresh = 0;
        // 1.遍历果盘，记录新鲜橘子的个数，将腐烂的橘子放入遍历队列。
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    rotten.addLast(new int[] {i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // 2.遍历掉当前队列有的腐烂橘子，作为第一分钟的蔓延。
        int minute = 0;
        while(fresh != 0 && !rotten.isEmpty()){
            int size = rotten.size();
            for(int i = 0; i < size; i++){
                int[] orange = rotten.getFirst(); rotten.removeFirst();
                int row = orange[0]; int column = orange[1];
                // 3.将腐烂橘子四周的橘子感染，需要为新鲜橘子且不能数组越界，将之改为2状态。将新增加的腐烂橘子放入队列。新鲜橘子数-1。
                if(row-1 >= 0 && grid[row-1][column] == 1){
                    grid[row-1][column] = 2;
                    fresh--;
                    rotten.addLast(new int[] {row-1, column});
                }
                if(row+1 < m && grid[row+1][column] == 1){
                    grid[row+1][column] = 2;
                    fresh--;
                    rotten.addLast(new int[] {row+1, column});
                }
                if(column-1 >= 0 && grid[row][column-1] == 1){
                    grid[row][column-1] = 2;
                    fresh--;
                    rotten.addLast(new int[] {row, column-1});
                }
                if(column+1 < n && grid[row][column+1] == 1){
                    grid[row][column+1] = 2;
                    fresh--;
                    rotten.addLast(new int[] {row, column+1});
                }
            }
            minute++;
        }

        // 5.是否能全部腐烂掉，是的话返回所需时间，否则返回失败。
        return fresh == 0 ? minute : -1;
    }
}
