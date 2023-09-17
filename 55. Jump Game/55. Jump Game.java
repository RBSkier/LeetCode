class Solution {
    public boolean canJump(int[] nums) {
        int k = 0;
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            if (i > k) return false;
            k = Math.max(k, i + nums[i]);
            if (k >= n - 1) return true;
        }
        return true;
    }
}

//每次获得下次可跳跃的最远跳跃距离
// 第一次是2
// 在3，1之间找到下次最远跳跃（index+value），分别是4，2，所以选4。如果4已经达到数组最大长度，返回true，否则如果最远距离有更新，进入下一次迭代。寻找2-4之间。
// 然后放宽检索范围到[0,4],已检索范围定为[0,2],3+1=4

// 初始检索范围0-3
// 3，2，1，0对应最远范围3，3，3，3。没达到数组长度，可到达最远距离也没变，返回false

//考虑初始条件是否判断充分
//考虑边缘输入，空数组，一个元素