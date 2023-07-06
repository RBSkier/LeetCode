#include <iostream>
#include <vector>
#include "Solution.cpp"

int main() {
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(1);
    Solution solution;
    srand((unsigned)time(nullptr));
    vector<int> ret = solution.getLeastNumbers(arr, 1);
    return 0;
}
