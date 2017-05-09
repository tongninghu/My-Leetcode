Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        
        for(int j = 1; j <= n - 1; j = j + 2) {
            if (p[j] == '*')   dp[0][j + 1] = true;
            else break;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (p[j] == '*') dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j + 1] && (p[j - 1] == s[i] || p[j - 1] == '.');
                else if (p[j] == '.' || p[j] == s[i]) dp[i + 1][j + 1] = dp[i][j];
            }
        }
        return dp[m][n];
    }
};
