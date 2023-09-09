int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(!matrix){
        *returnSize = 0;
        return NULL;
    }
    if(matrixSize == 0 || matrixColSize[0] == 0){
        *returnSize = 0;
        return NULL;
    }

    int row = matrixSize, col = *matrixColSize;
    //记录元素已被访问标志
    int visited[row][col];
    memset(visited, 0, sizeof(visited));
    int total = row * col;
    int* retArray = malloc(total * sizeof(int));

    int row_index = 0, col_index = 0;
    char direct = 'r';
    for(int i = 0; i < total; i++){
        retArray[i] = matrix[row_index][col_index];
        visited[row_index][col_index] = 1;
    
        //判断下一个元素的位置
        if(direct == 'r'){
            //如果没数组越界并且下一个元素未被访问过
            if(col_index + 1 < col && visited[row_index][col_index + 1] != 1){
                col_index++;
                continue;
            //否则尝试向下走
            }else if(row_index + 1 < row && visited[row_index + 1][col_index] != 1){
                row_index++;
                direct = 'd';
                continue;
            //到达终点，结束递归
            }
        }

        if(direct == 'd'){
            if(row_index + 1 < row && visited[row_index + 1][col_index] != 1){
                row_index++;
                continue;
            //尝试改向左走
            }else if(col_index - 1 >= 0 && visited[row_index][col_index - 1] != 1){
                direct = 'l';
                col_index--;
                continue;
            }
        } 

        if(direct == 'l'){
            //如果没数组越界并且下一个元素未被访问过
            if(col_index - 1 >= 0 && visited[row_index][col_index - 1] != 1){
                col_index--;
                continue;
            //否则尝试向上走
            }else if(row_index - 1 >= 0 && visited[row_index - 1][col_index] != 1){
                direct = 'u';
                row_index--;
                continue;
            //到达终点，结束递归
            }
        }

        if(direct == 'u'){
            if(row_index - 1 >= 0 && visited[row_index - 1][col_index] != 1){
                row_index--;
                continue;
            //尝试改向右走
            }else if(col_index + 1 < row && visited[row_index][col_index + 1] != 1){
                col_index++;
                direct = 'r';
                continue;
            }
        }
    }
    
    *returnSize =  total;
    return retArray;
}
