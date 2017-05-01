Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int j = 0, i;
        while (j < s.length()) {
            while (j < s.length() && s[j] == ' ') 
                s.erase (s.begin() + j);
            i = j;
            while (j < s.length() && s[j] != ' ') 
                j++;
            reverse(s.begin() + i, s.begin() + j);
            if (j < s.length()) j++;
        }
        if(s.length() > 0 && s[s.length() - 1] == ' ') s.resize(s.length() - 1);
    }
};
