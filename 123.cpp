Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size(), maxprof = 0;
        if (m == 0) return 0;
        int knum = 2;
        vector<vector<int>> dp(knum + 1, vector<int>(m, 0));
        for(int k = 1; k <= knum; k++) {
            int maxtemp = -prices[0];
            for(int i = 1; i < m; i++) {
                dp[k][i] = max(dp[k][i - 1], prices[i] + maxtemp);
                maxtemp = max(maxtemp, dp[k - 1][i] - prices[i]);
                maxprof = max(maxprof, dp[k][i]);
            }
        }
        return maxprof;
    }
};
