Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n + 1, 1);
        unordered_set<int> square;
        square.insert(1);
        for (int i = 2; i <= n; i++) {
            int a = sqrt(i), res = INT_MAX;
            if (a * a == i) square.insert(i);
            else if (dp[i - 1] == 1) dp[i] = 2;
            else {
                int temp = INT_MAX;
                for(int s : square) {
                        temp = min(temp, 1 + dp[i - s]);
                        if (temp == 2) break;
                }
                dp[i] = temp;
            }
        }
        return dp[n];
    }
};
