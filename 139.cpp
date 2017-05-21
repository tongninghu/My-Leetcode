Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordlist;
        for (int i = 0; i < wordDict.size(); i++) 
            wordlist.insert(wordDict[i]);
        int m = s.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for(int i = 1; i <= m; i++) {
            for(int j = i - 1; j >= 0 ; j--) {
                if (dp[j] == true && wordlist.find(s.substr(j,i-j)) != wordlist.end()) dp[i] = true;
            }
        }
        return dp[m];
    }
};
