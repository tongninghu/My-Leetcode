Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while(j < s.length()) {
            while(j < s.length() && s[j] == ' ') s.erase(s.begin() + j);
            i = j;
            while(j < s.length() && s[j] != ' ') j++;
            reverse(s.begin() + i, s.begin() + j);
            j++;
        }
        return s;
    }
};
