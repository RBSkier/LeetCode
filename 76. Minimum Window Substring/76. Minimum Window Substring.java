class Solution {
    public String minWindow(String s, String t) {
        //1. create freq_array of t, count the frequency of letters in t.
        int[] freqT = new int[128];
        for(int i = 0; i < t.length(); i++) freqT[t.charAt(i)]++;
        //2. initialize window left and right border to 0.
        int left = 0, right = 0;
        int distance = t.length();
        int begin = 0, ans_length = s.length() + 1;
        //3. move right boundary.
        while(right < s.length()){
            char right_char = s.charAt(right);
            //if the letter match t, the window array get closer to t.
            if(freqT[right_char] > 0)    distance--;
            freqT[right_char]--;
            //4. while window contains all the t letters, shorten the left boundary
            while(distance == 0){
                //maintain the best answer
                if(right - left + 1 < ans_length){
                    ans_length = right - left + 1;
                    begin = left;
                }
                //maintain the freqT and distance variables.
                char left_char = s.charAt(left);
                //if left_char is the letter of t
                if(freqT[left_char] == 0) distance++;
                freqT[left_char]++;
                left++;
            }
            right++;
        }

        //if equal to the initialized value.
        if(ans_length == s.length() + 1)
            return "";
        else
            return s.substring(begin, begin + ans_length);
    }
}