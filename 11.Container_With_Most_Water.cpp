class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0, right = size -1;
        int maxArea = 0;
        while(left != right){
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if(height[left] <= height[right])
                left++;
            else
                right--;
        }
        return maxArea;
    }
};

//反思，没能想起来可以通过变量记录可能的最大值。没想起来受限于较短边