class Solution {
    public int maximumGap(int[] nums) {
        int R = 10;
        int N = nums.length;
        int max_val = Arrays.stream(nums).max().getAsInt();

        int[] aux = new int[N];
        for(int Y = 1; max_val >= Y; Y *= 10){
            int[] count = new int[R + 1];   //Compute frequency counts.
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
            nums = Arrays.copyOf(aux, aux.length);  //copy back
        }

        int ret = 0;
        for (int i = 1; i < N; i++){
            ret = Math.max(ret, nums[i] - nums[i-1]);
        }
        
        return ret;
    }
}


