class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto head_ptr = nums.begin();
        for(auto itor = nums.begin(); itor != nums.end(); itor++){
            if(*itor != 0){
                *head_ptr = *itor;
                head_ptr++;
            }
        }
        while(head_ptr != nums.end()){
            *head_ptr = 0;
            head_ptr++;
        }        
    }
};