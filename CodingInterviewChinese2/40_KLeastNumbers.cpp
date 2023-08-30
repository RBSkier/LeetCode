#include <vector>

using namespace std;

class Solution {
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l - 1;
        for (int j = l; j <= r - 1; ++j) {
            if (nums[j] <= pivot) {
                i = i + 1;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[r]);
        return i + 1;
    }

    // 基于随机的划分
    int randomized_partition(vector<int>& nums, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(nums[r], nums[i]);
        return partition(nums, l, r);
    }

    void randomized_selected(vector<int>& arr, int l, int r, int k) {
        if (l >= r) {
            return;
        }
        int pos = randomized_partition(arr, l, r);
        if (k == pos) {
            return;
        } else if (k < pos) {
            randomized_selected(arr, l, pos - 1, k);
        } else {
            randomized_selected(arr, pos + 1, r, k);
        }
    }    
    
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        srand((unsigned)time(NULL));
        randomized_selected(arr, 0, (int)arr.size() - 1, k);
        vector<int> vec;
        for (int i = 0; i < k; ++i) {
            vec.push_back(arr[i]);
        }
        return vec;
    }
};

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