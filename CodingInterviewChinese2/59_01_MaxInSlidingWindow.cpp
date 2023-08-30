class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //robust
        if(nums.empty())
            return vector<int>();

        vector<int> ret;
        deque<int> orderQue;
        for(int i = 0; i < nums.size(); ++i){
            //如果该数比队列末尾的大，就一直弹出队列中比自己小的标记数，再插入自己的下标
            while(!orderQue.empty() && nums[i] > nums[orderQue.back()])
                orderQue.pop_back();
            orderQue.push_back(i);
            //如果队列头的标记数已经离开窗口，将其弹出
            if(orderQue.front() < i - k + 1)
                orderQue.pop_front();
            //如果循环下标+1大于等于窗口大小，将队列头的数作为当前窗口的最大值。
            if(i + 1 >= k)
                ret.push_back(nums[orderQue.front()]);    
        }

        return ret;
    }
};

/*
如果循环下标 + k 大于数组大小，结束
遍历过程：
    如果队列为空或者当前数比队列末尾标记的数小，入列
    如果该数比队列末尾的大，就一直将之前队列中的标记数弹出，直到自己比较小，插入自己的下标
    如果队列头的标记数已经离开窗口，将其弹出
    如果循环下标+1不够k，不输出窗口最大值。否则将队列头的数作为当前窗口的最大值。
*/

