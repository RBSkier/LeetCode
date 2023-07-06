//
// Created by Jimmy Liu on 4/7/2023.
//
#include "Solution.cpp"

int main(){
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);
    Solution solution;
    int ret = solution.maxSubArray(nums);
    return ret;
}
