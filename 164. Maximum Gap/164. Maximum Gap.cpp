class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int R = 10;
        int N = nums.size();
        int max_val = *std::max_element(nums.begin(), nums.end());

        std::vector<int> aux(N, 0);
        for(int Y = 1; max_val >= Y; Y *= 10){
            std::vector<int> count(R + 1, 0);   //Compute frequency counts.
            for(int i = 0; i < N; i++){
                int digit = (nums[i] / Y) % 10;
                count[digit+1]++;
            }
            for(int r = 0; r < R; r++){     //Transform counts to indices.
                count[r+1] += count[r];
            }
            for(int i = 0; i < N; i++){     //Distribute the data.
                int digit = (nums[i] / Y) % 10;
                aux[count[digit]++] = nums[i];     
            }
            nums = aux;  //copy back
        }

        int ret = 0;
        for (int i = 1; i < N; i++){
            ret = std::max(ret, nums[i] - nums[i-1]);
        }
        
        return ret;
    }
};


