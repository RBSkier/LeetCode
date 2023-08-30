#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool match(char* s, char* p, int i, int j){
    if(i == 0){
        return false;
    }
    if(p[j-1] == '.'){
        return true;
    }
    
    return s[i-1] == p[j-1];
}

bool isMatch(char* s, char* p){
    int m = (int)strlen(s), n = (int)strlen(p);
    
    bool** f = (bool**)calloc(m+1, sizeof(bool*));
    for(int i = 0; i < m+1; i++){
        f[i] = (bool*)calloc(n+1, sizeof(bool));
    }
    f[0][0] = true;
    
    for(int i = 0; i <= m; i++){
        for(int j = 1; j <= n; j++){
            /* 如果p最后一个字符是字母或者'.' */
            if(p[j-1] != '*'){
                if(match(s, p, i, j)){
                    f[i][j] = f[i-1][j-1];
                }else{
                    /** 最后一个字符不匹配就不用看前面的了 */
                    f[i][j] = false;
                }
            }else{
                if(match(s, p, i, j - 1)){
                    f[i][j] = (f[i-1][j] | f[i][j-2]);
                }else{
                    f[i][j] = f[i][j-2];
                }
            }
        }
    }

    return f[m][n];
}
