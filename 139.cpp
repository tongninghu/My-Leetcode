Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        unordered_set<string> wordlist;
        for (int i = 0; i < wordDict.size(); i++) 
            wordlist.insert(wordDict[i]);
        
        vector<vector<bool>> dp (m, vector<bool>(m, false));
        for(int l = 1; l <= m; l++) {
            for(int i = 0; i <= m - l; i++) {
                int j = i + l - 1;
                if(wordlist.find(s.substr(i, l)) != wordlist.end()) dp[i][j] = true;
                else {
                    for (int k = i; k < j; k++) {
                        if (dp[i][k] == true && dp[k + 1][j] == true) {
                            dp[i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[0][m - 1];
    }
};
