class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  //robust
            return 0;

        int step = 0;
        int end = 0;
        int next_end = 0;
        for(int i = 0; i < n - 1; i++){     //只需要到n-1是因为如果在n-1的时候还需要跳，步数会+1，并且一定能达到n。到n点以后就不需要跳了，排除掉。
            next_end = max(next_end, i + nums[i]);
            if(i == end){
                end = next_end;
                step++;
            }
        }
        return step;
    }
};

/* 维护一个相同大小的数组，记录并持续更新每个位置可以到达的最短步数，初始化无穷大，step[0] = 0
//第一种思路
遍历nums，设置step数组专门记录到达某个点最少需要跳几次，每次都更新。每遍历一个num[i]更新step组的k ~ i + num[i]:如果i+num[i]小于k就直接跳过更新，i+num[i]大于n的话取n。

nums：[2,3,3,1,4,3]
step:[0,infinite,infinite,infinite,infinite,infinite]

第1轮循环：[0,1,1,-1,-1,-1]
第2轮循环：[0,1,1,2,2,-1,-1]
第3轮循环：[0,1,1,2,2,2,-1]

//改良，不需要为每一个台阶都更新记录，因为他们都是同值。只需要记录每增加一跳，可以到达的最远距离。
*/
