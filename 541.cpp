Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"
Restrictions:
The string consists of lower English letters only.
Length of the given string and k will in the range [1, 10000]

class Solution {
public:
     void reverseString(int start, int end, string& s) {
        char tmp;
        for (int i = 0; i < (end - start + 1) / 2; i++) {
            tmp = s[start + i];
            s[start + i] = s[end - i];
            s[end - i] = tmp;
        }
    }
    
    string reverseStr(string s, int k) {
        if (s.length() <= k) reverseString(0, s.length() - 1, s);
        else {
            int i;
            for (i = k - 1; i < s.length(); i += 2 * k) 
                reverseString(i - k + 1, i, s);
            if (i - k + 1 < s.length()) reverseString(i - k + 1, s.length() - 1, s);
        }
        return s;
    }
};
