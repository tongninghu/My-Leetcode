Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

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
    
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(j < s.length()) {
            if (s[j] == ' ') {
                reverseString(i, j - 1, s);
                j++;
                i = j;
            }
            else j++;
        }
        if (i < j) reverseString(i, j - 1, s);
        return s;
    }
};
