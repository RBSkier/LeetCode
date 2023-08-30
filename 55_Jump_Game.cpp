class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
	//遍历中更新在目前已知的可到达最远距离
        for (int i = 0; i < n; i++) {
            if (i > k) return false;	//如果如果遍历到了可达到的最大距离就说明无法到达终点。
            k = max(k, i + nums[i]);
            if (k >= n - 1) return true;	//如果最远距离已经超过数组大小，就说明可以到达终点。提前结束。
        }
        return true;
    }
};