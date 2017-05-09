Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        
        for (int j = 0; j <= n; j++) {
            if (p[j] == '*')
                dp[0][j + 1] = true;
            else
                break;
            }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (p[j] == '*') dp[i + 1][j + 1] = dp[i][j + 1] || dp[i + 1][j];
                else if (p[j] == '?' || p[j] == s[i]) dp[i + 1][j + 1] = dp[i][j];
            }
        }
        return dp[m][n];
    }
};
