class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
            if(target == matrix[i][j]) return true; 
            else if(target < matrix[i][j])  j--;    //move left
            else i++;   //move down
        }
        return false;
    }
};
