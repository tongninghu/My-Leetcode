Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:    
    int minCut(string s) {
        vector<vector<bool>> isPal (s.size(), vector<bool> (s.size(), false));
        for (int i = 0; i < s.size(); i++)
            isPal[i][i] = true;
        
        if (s.size() == 0) return 0;
        vector<int> dp(s.size() + 1, 0);
        
        for (int i = 0; i < s.size(); i++) {
            dp[i + 1] = dp[i] + 1;
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j] && (i - j == 1 || i - j >= 2 && isPal[j + 1][i - 1])) {
                    dp[i + 1] = min(dp[i + 1], dp[j] + 1);
                    isPal[j][i] = true;
                }
            }
        }
        return dp[s.size()] - 1;
    }
};
