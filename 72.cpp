Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp (n + 1, vector<int> (m + 1, 0));
        dp[0][0] = 0;
        for (int j = 0; j < m; j++) dp[0][j + 1] = j + 1;
        for (int i = 0; i < n; i++) dp[i + 1][0] = i + 1;
        
        for (int i  = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word1[j] == word2[i]) dp[i + 1][j + 1] = dp[i][j];
                else if (dp[i + 1][j] == dp[i][j + 1] && dp[i][j] < dp[i + 1][j]) dp[i + 1][j + 1] = dp[i][j + 1];
                else dp[i + 1][j + 1] = min(dp[i + 1][j] + 1, dp[i][j + 1] + 1);
            }
        }
        return dp[n][m];
    }
};
