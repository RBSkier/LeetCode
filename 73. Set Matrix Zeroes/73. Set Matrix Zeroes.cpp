class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool rowflag = false, columnflag = false;
        //set the first row and column zero flag.
        for(int i = 0; i < m; i++)
            if(matrix[i][0] == 0){
                columnflag = true;
                break;
            }

        for(int j = 0; j < n; j++)
            if(matrix[0][j] == 0){
                rowflag = true;
                break;
            } 

        //set the rest row and column zero flag in the first row and column.
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        //iterate over the row and modify elements.
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;


        if(columnflag)
            for(int i = 0; i < m; i++)
                matrix[i][0] = 0;

        if(rowflag)
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
    }
};
