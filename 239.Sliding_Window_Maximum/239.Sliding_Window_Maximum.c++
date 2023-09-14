class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k > nums.size())
            return {};

        vector<int> result;
        deque<int> max_deque;
        //1.create sliding window
        for(int i = 0; i < k; i++){
            //pop the smaller element in front of new element to maintain the decreasing sequence.
            while(!max_deque.empty() && nums[i] > nums[max_deque.back()]){
                max_deque.pop_back();
            }
            max_deque.push_back(i);
        }
        result.emplace_back(nums[max_deque.front()]);
        //move sliding window
        for(int i = k; i < nums.size(); i++){
            //the front element out of the window should be popped.
            if(!max_deque.empty() && max_deque.front() < i - k + 1)
                max_deque.pop_front();
            while(!max_deque.empty() && nums[i] >= nums[max_deque.back()]){
                max_deque.pop_back();
            }
            max_deque.push_back(i);
            result.emplace_back(nums[max_deque.front()]);
        }
        return result;
    }
};

//Compared to sorting the nums array, using a max deque allows for dropping elements in the window as soon as it is determined that they are not larger than the elements to the right. This reduces the number of comparisons needed during the sorting process.
