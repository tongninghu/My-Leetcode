Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.

class Solution {
public:
    int nthUglyNumber(int n) {
        int k2 = 1, k3 = 1, k5 = 1;
        vector<int> dp (n + 1, 1);
        for(int i = 2; i <= n; i++) {
            dp[i] = min(dp[k2] * 2, min(dp[k3] * 3, dp[k5] * 5));
            if (dp[i] == dp[k2] * 2) k2++;
            if (dp[i] == dp[k3] * 3) k3++;
            if (dp[i] == dp[k5] * 5) k5++;
        }
        return dp[n];
    }
};
