Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size(), maxprof = 0, knum;
        if (m == 0) return 0;
        if (k > (m + 1) / 2) knum = (m + 1) / 2;
        else knum = k;
        
        vector<int> dp(m, 0);
        for(int kk = 1; kk <= knum; kk++) {
            int maxtemp = -prices[0];
            for(int i = 1; i < m; i++) {
                int dptemp = dp[i];
                dp[i] = max(dp[i - 1], prices[i] + maxtemp);
                maxtemp = max(maxtemp, dptemp - prices[i]);
                maxprof = max(maxprof, dp[i]);
            }
        }
        return maxprof;        
    }
};
