Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        vector<vector<int>> dp (m + 1, vector<int> (n + 1, 0));
        for (int j = 0; j < n; j++) 
            dp[0][j + 1] = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (t[i] != s[j]) dp[i + 1][j + 1] = dp[i + 1][j];
                else if (i > 0 && t[i] == t[i - 1])  dp[i + 1][j + 1] = dp[i][j] + dp[i + 1][j];
                else  dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[m][n];
    }
};
