class Solution {
public:
    string minWindow(string s, string t) {
        //1. create freq_array of t, count the frequency of letters in t.
        int freq_array_t[128] = {0};
        for(auto ch: t){
            freq_array_t[ch]++;
        }
        //2. initialize window left and right border to 0.
        int left = 0, right = 0;
        int distance = t.length();
        int ans_length = s.length() + 1;
        int begin = 0;
        //3. move right boundary.
        while(right < s.length()){
            char right_char = s[right];
            //if the letter match t, the window array get closer to t.
            if(freq_array_t[right_char] > 0){//bigger than 0 means t contains the letter
                distance--;
            }
            freq_array_t[right_char]--;

            //4. while window contains all the t letters, shorten the left boundary
            while(distance == 0){
                //maintain the best answer
                if(right - left + 1 < ans_length){
                    ans_length = right - left + 1;
                    begin = left;
                }
                //maintain the freq_array_t and distance variables.
                char left_char = s[left];
                //if left_char is the letter of t
                if(freq_array_t[left_char] == 0){   
                    distance++;
                }
                freq_array_t[left_char]++;
                left++;
            }
            right++;
        }

        if(ans_length == s.length() + 1) //the initialized value wasn't change.
            return "";
        else
            return s.substr(begin, ans_length);
    }
};
