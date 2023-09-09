lass Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length -1;
        int maxArea = 0;
        while(left != right){
            if(height[left] < height[right])
                maxArea = Math.max(maxArea, (right - left) * height[left++]);
            else
                maxArea = Math.max(maxArea, (right - left) * height[right--]);
        }
        return maxArea;
    }
}
