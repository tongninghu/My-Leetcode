Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

class Solution {
public:
    bool isPalindrome(string temp) {
        int start = 0, end = temp.length() - 1;
        while (end > start) {
            if(temp[start++] != temp[end--]) return false;   
        }
        return true;
    }
    
    void helper(vector<string>& cur, vector<vector<string>>& res, int start, string s) {
        if (start == s.length()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = start; i < s.length(); i++) {
            if (isPalindrome(s.substr(start, i - start + 1))) {
                cur.push_back(s.substr(start, i - start + 1));
                helper(cur, res, i + 1, s);
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> cur; 
        vector<vector<string>> res;
        helper(cur, res, 0, s);
        return res;
    }
};
