class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //flip verical
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n/2; j++){
                std::swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        //flip diagonally
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n - i; j++){
                std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
    }
};

