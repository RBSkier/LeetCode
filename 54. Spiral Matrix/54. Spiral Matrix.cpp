class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.empty())  return ans;
        int top = 0, left = 0, bottom = matrix.size() - 1, right = matrix[0].size() - 1;
        while(top <= bottom && left <= right){
            //from top-left to top-right
            for(int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            if(++top > bottom)  break;

            //from top-right to bottom-right
            for(int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            if(--right < left)  break;

            //from bottom-right to bottom-left
            
            for(int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            if(--bottom < top)  break;

            //from bottom-left to top-left
            for(int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            if(++left > right)  break;
        }
        return ans;
    }
};
