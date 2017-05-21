Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

class Solution {
public:
    void dfs(int start, vector<vector<int>>& dp, vector<int>& cur, vector<string>& res, string &s) {
        if(start == 0) {
            int begin = 0;
            string ss;
            for(int k = cur.size() - 2; k >= 0; k--) {
                ss += s.substr(begin, cur[k] - begin) + " ";
                begin = cur[k];
            }
            ss += s.substr(cur[0]);
            res.push_back(ss);
            return;
        }
        for (int k = dp[start].size() - 1; k >= 0; k--) {
            int i = dp[start][k];
            cur.push_back(i);
            dfs(i, dp, cur, res, s);
            cur.pop_back();
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int m = s.size();
        vector<int> cur;
        vector<string> res;
        unordered_set<string> wordlist;
        for (int i = 0; i < wordDict.size(); i++) 
            wordlist.insert(wordDict[i]);
        vector<vector<int>> dp(m + 1, vector<int>());
        dp[0].push_back(0);
        for (int i = 1; i <= m; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (!dp[j].empty()) {
                    string word = s.substr(j,i-j);
                    if (wordlist.find(word)!= wordlist.end())  dp[i].push_back(j);
                }
            }
        }
        for (int k = dp[m].size() - 1; k >= 0; k--) {
            int i = dp[m][k];
            cur.push_back(i);
            dfs(i, dp, cur, res, s);
            cur.pop_back();
        }
        return res;
    }
};
