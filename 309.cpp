Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxprof = INT_MIN;
        vector<int> buy (n + 1, 0);
        vector<int> sell (n + 1, 0);
        vector<int> reset (n + 1, 0);
        for (int i = 1; i < n; i++) {
            buy[i + 1] = prices[i] - prices[i - 1] + max(buy[i], reset[i]);
            sell[i + 1] = max(max(buy[i], sell[i]), reset[i]);
            reset[i + 1] = max(max(buy[i - 1], sell[i - 1]), reset[i - 1]);
        }
        return max(buy[n], max(sell[n], reset[n]));
    }
};
