Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool>> dp (s1.size() + 1, vector<bool> (s2.size() + 1, false));
        dp[0][0] = true;
        if (s3.size() != s1.size() + s2.size()) return false;
        
        for (int i = 1; i <= s2.size(); i++) 
            if (s2[i - 1] == s3[i - 1] && dp[0][i - 1]) dp[0][i] = true;
            else break;
        
        for (int i = 1; i <= s1.size(); i++)
            if (s1[i - 1] == s3[i - 1] && dp[i - 1][0]) dp[i][0] = true;
            else break;
        
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j] || s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]) dp[i][j] = true;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
