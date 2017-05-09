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
        if (s.size() == 0 && (p.size() == 0 || p.size() == 1 && p[0] == '*')) return true;
        else if (s.size() == 0 || p.size() == 0) return false;
        
        vector<vector<bool>> m (p.size(), vector<bool>(s.size(), false));
        int count = 0;
        
        if (p[0] == '*') {
            for (int j = 0; j < s.size(); j++)
                m[0][j] = true;
        }
        else if (p[0] == '?' || p[0] == s[0]) {
            m[0][0] = true;
            count = 1;
        }
        
        for (int i = 1; i < p.size(); i++) 
            if (m[i - 1][0] == true && (p[i] == '*' || p[i] == '?' && count == 0 || p[i] == s[0] && count == 0)) {
                m[i][0] = true;
                if (p[i] == '?' || p[i] == s[0] ) count = 1;
            }
            
        for (int i = 1; i < p.size(); i++) {
            for (int j = 1; j < s.size(); j++) {
                if (p[i] == s[j] || p[i] == '?') m[i][j] = m[i - 1][j - 1];
                else if (p[i] == '*' && (m[i - 1][j - 1] == true || m[i - 1][j] == true || m[i][j - 1] == true)) m[i][j] = true;
            }
        }
        return m[p.size() - 1][s.size() - 1];
    }
};
