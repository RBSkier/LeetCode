class Solution {
    public int maxProfit(int[] prices) {
        int min = Integer.MAX_VALUE;
        int maxEarn = 0;

        for(int i = 0; i < prices.length; i++){
            if(prices[i] < min)
                min = prices[i];
            else if(prices[i] - min > maxEarn)
                maxEarn = prices[i] - min;
        }

        return maxEarn;
    }
}