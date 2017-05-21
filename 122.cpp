Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size();
        if(m == 0) return 0;
        vector<int> dp(m, 0);
        for (int i = 1; i < m; i++) {
            if (prices[i] > prices[i - 1]) dp[i] = dp[i - 1] + prices[i] - prices[i - 1];
            else dp[i] = dp[i - 1];
        }
        return dp[m - 1];
    }
};
