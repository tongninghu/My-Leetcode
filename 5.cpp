Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return string ();
        int low = 0, high = 0, mid = 0, length = 0, L, H;
        while(mid < s.size()) {
            if (s.size() - mid < length / 2) break;
            low = mid;
            high = mid;
            while (high < s.size() - 1 && s[high] == s[high + 1]) high++;
            mid = high + 1;
            while (low > 0 && high < s.size() - 1 && s[low - 1] == s[high + 1]) {
                low--;
                high++;
            }
            if((high - low + 1) > length) {
                L = low;
                H = high;
                length = high - low + 1;
            }
        }
        return s.substr(L, H - L + 1);
    }
};
