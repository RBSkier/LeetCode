#include <vector>
using namespace std;

class Solution {
private:
    int mergeSort(vector<int> & src, vector<int> & tar, int start, int end){
        //递归结束条件
        if(start == end){
            tar[start] = src[start];
            return 0;
        }
        vector<int> a = vector<int>();
        //递归
        int mid = (start + end) / 2;
        int count = mergeSort(tar, src, start, mid) + mergeSort(tar, src, mid + 1, end);
        //merge操作
        int i = mid, j = end, idxCpy = end;
        while(i >= start && j >= mid + 1){
            if(src[i] > src[j]){
                tar[idxCpy--] = src[i--];
                count += j - mid;
            }else{
                tar[idxCpy--] = src[j--];
            }
        }

        while(i >= start)
            tar[idxCpy--] = src[i--];
        while(j >= mid + 1)
            tar[idxCpy--] = src[j--];

        return count;
    }
public:
    int reversePairs(vector<int> & nums) {
        //robust
        if(nums.empty())
            return -1;
        vector<int> copy(nums);
        return mergeSort(nums, copy, 0, nums.size() - 1);
    }
};

int main(){
    vector<int> nums = {7, 5, 6, 4};
    Solution solution;
    solution.reversePairs(nums);
}