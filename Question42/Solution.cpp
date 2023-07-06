/* 创建两个变量，一个保存目前得到的可能最大值max，一个保存目前的累加值acc
 *
 *
 * 初始化max = 0；acc = 0；搞一个cur指针；
 * while(cur < r.size)
 *      acc += r[cur]
 *      acc > max?
 *          是：max = acc
 *          否：acc > 0?
 *              是：a
 *              否：舍弃全部，acc = 0
 *      cur++;
 * return max;
 *
 * 第一个正数作为max值，acc值。cur指针在头。cur++;
 * 继续遍历，
 *      下一遇到是正数？：
 *          是：max = acc += 该正数。end = cur;cur++
 *          否：if(acc + 负数 > 0)
 *              是：保留前面的连续值，acc += 负数。max不变。cur++。(后续可能会反超)
 *              否：清空前面累加值，归档前一个max，start，end。然后acc = 0。start = end = ++cur（暂时重置为下一个点）
 *      下一个遇到是正数？
 *          是：acc += 正数。
 *              if acc > max
 *                  max = acc;end = cur
 *              cur++
 *          否：if(acc + 负数>0)
 *              是：保留前面的连续值，acc += 负数。max不变。end++。
 *              否：清空前面累加值，acc = 0。end。cur + 2。start = cur
 *
 * */
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //鲁棒性
        if(nums.empty())
            return 0;

        int max = 0, acc = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            acc += nums[i];
            if(acc > max){
                max = acc;
            }else if(acc < 0){
                acc = 0;    //清空子数组
            }
        }

        return max;
    }
};


