class Solution {
    public int count = 0;
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        reach(visited, m, n, k, 0, 0);
        return count;
    }

    public void reach(boolean[][] visited, int m, int n, int k, int i, int j){
        count++;
        visited[i][j] = true;
        int[][] directions = {{-1, 0},{1,0},{0,-1},{0,1}};
        for (int[] direction : directions){
            int newi = i + direction[0], newj = j + direction[1];

            if(newi >= 0 && newi < m && newj >= 0 && newj < n){
                int sum = 0;
                StringBuilder numlist = new StringBuilder();
                numlist = numlist.append(newi).append(newj);
                int quotient =  Integer.parseInt(numlist.toString()), residue;
                do{
                    residue = quotient % 10;
                    quotient = quotient / 10;
                    sum += residue;
                }while(quotient != 0);
                if(sum <= k && visited[newi][newj] == false){
                    reach(visited, m, n, k, newi, newj);
                }
            }
        }
    }
}