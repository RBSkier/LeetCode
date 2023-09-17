class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if(matrix.length == 0)  return ans;
        int top = 0, left = 0, bottom = matrix.length - 1, right = matrix[0].length - 1;
        while(top <= bottom && left <= right){
            //from top-left to top-right
            for(int i = left; i <= right; i++)
                ans.add(matrix[top][i]);
            if(++top > bottom)  break;

            //from top-right to bottom-right
            for(int i = top; i <= bottom; i++)
                ans.add(matrix[i][right]);
            if(--right < left)  break;

            //from bottom-right to bottom-left
            
            for(int i = right; i >= left; i--)
                ans.add(matrix[bottom][i]);
            if(--bottom < top)  break;

            //from bottom-left to top-left
            for(int i = bottom; i >= top; i--)
                ans.add(matrix[i][left]);
            if(++left > right)  break;
        }
        return ans;
    }
}