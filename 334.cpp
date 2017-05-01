Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".

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
    string reverseString(string s) {
        reverseString(0, s.length() - 1, s);
        return s;
    }
};
