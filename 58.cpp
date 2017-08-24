Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        while (s[i] == ' ' && i >= 0) i--;
        if (i == -1) return 0;
        int j = i;
        while (s[j] != ' ' && j >= 0) j--;
        return i - j;
    }
};
