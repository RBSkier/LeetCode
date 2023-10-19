class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        int[][] dp = new int[m + 1][n + 1];
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1.charAt(i-1) == text2.charAt(j-1)){
                    dp[i][j] = dp[i-1][j-1] + 1;    //if x == y, subsequence length + 1;
                }else{
                    //if x != y, check the subsequence length of text[0:i-1] and text[0:j]. check the subsequence length of text[0:i] and text[0:j-1].
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]); 
                }
            }
        }

        return dp[m][n];
    }
}
