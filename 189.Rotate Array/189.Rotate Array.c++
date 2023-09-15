class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 1 || k == 0){
            return;
        }
        int n = nums.size();
        //the count used to record the remaining number of swapping.
        int count = n;
        int origin = 0;
        int index = origin, temp1 = nums[origin], temp2;
        while(count != 0){
            temp2 = nums[(index+k)%n];
            nums[(index+k)%n] = temp1;
            count--;
            //if go back to the origin index, right move the origin index to make sure that all the element can be itored.
            if((index+k)%n == origin){
                origin = (origin+1)%n;
                index = origin;
                temp1 = nums[origin];
            }else{
                index = (index+k)%n;
                temp1 = temp2;
            }
        }
    }
};
