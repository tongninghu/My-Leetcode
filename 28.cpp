Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        for (int i = 0; i <= (int) haystack.length() - (int) needle.length(); i++) {
            int count = 0;
            for (int j = i; j <= i + needle.length() - 1; j++) {
                if (haystack[j] == needle[j - i]) count++;
                else break;
            }
            if (count == needle.length()) return i;
        }
        return -1;
    }
};
