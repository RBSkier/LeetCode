class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int sum = 0;
        while(left < right){
            //每次更新左右边界目前的最大值
            left_max = max(left_max, height[left]);
            right_max = max(right_max, height[right]);
            if(left_max < right_max){
                sum += left_max - height[left];
                left++;
            }else{
                sum += right_max - height[right];
                right--;
            }
        }
        return sum;
    }
};