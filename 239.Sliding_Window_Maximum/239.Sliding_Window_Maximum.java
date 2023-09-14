class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(k > nums.length)
            return new int[0];

        int[] result = new int[nums.length - k + 1];
        Deque<Integer> max_deque = new ArrayDeque<>();
        //1.create sliding window
        for(int i = 0; i < k; i++){
            //pop the smaller element in front of new element to maintain the decreasing sequence.
            while(!max_deque.isEmpty() && nums[i] > nums[max_deque.getLast()]){
                max_deque.removeLast();
            }
            max_deque.addLast(i);
        }
        result[0] = nums[max_deque.getFirst()];
        //move sliding window
        for(int i = k; i < nums.length; i++){
            //the front element out of the window should be popped.
            if(!max_deque.isEmpty() && max_deque.getFirst() < i - k + 1)
                max_deque.removeFirst();
            while(!max_deque.isEmpty() && nums[i] >= nums[max_deque.getLast()]){
                max_deque.removeLast();
            }
            max_deque.addLast(i);
            result[i - k + 1] = nums[max_deque.getFirst()];
        }
        return result;
    }
}
