class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        //flip verical
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
        //flip diagonally
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][n - 1 - i];
                matrix[n - 1 - j][n - 1 - i] = temp;
            }
        }
    }
}
