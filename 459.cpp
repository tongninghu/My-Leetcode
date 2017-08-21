Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int n = 2; n <= s.length(); n++) {
            if (s.length() % n != 0) continue;
            int begin = 0;
            string f = s.substr(begin, s.length() / n);
            int i = 1;
            for (; i < n; i++) {
                begin += s.length() / n;
                if (s.substr(begin, s.length() / n) != f) break;
            }
            if (i == n) return true;
        }
        return false;
    }
};
