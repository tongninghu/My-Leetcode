Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> combine(string w, vector<string> t) {
        vector<string> res;
        for(int i = 0; i < t.size(); i++) {
            res.push_back(w + " " + t[i]);
        }
        return res;
    }
    
    vector<string> dfs(string s, unordered_set<string>& word) {
        if (dp.count(s)) return dp[s];
        vector<string> result;
        if (word.find(s) != word.end()) result.push_back(s);
        for(int i = 1; i < s.size(); i++) {
            if (word.find(s.substr(0, i)) != word.end()) {
                vector<string> cur = combine(s.substr(0, i), dfs(s.substr(i), word));
                result.insert(result.end(), cur.begin(), cur.end());
            }
        }    
        dp[s] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& word) {
        unordered_set<string> my_set;
        for(int i = 0; i < word.size(); i++)
            my_set.insert(word[i]);
        return dfs (s, my_set);
    }
};
