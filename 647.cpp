Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 0) return 0;
        vector<vector<bool>> isPal(s.size(), vector<bool>(s.size(), false));
        for (int i = 0; i < s.size(); i++)
            isPal[i][i] = true;
        
        int num = 1;
        
        for (int i = 1; i < s.size(); i++) {
            num++;
            for (int j = 0; j < i; j++) {
                if (s[i] == s[j] && (i == j + 1 || i > (j + 1) && isPal[j + 1][i - 1])) {
                    num++;
                    isPal[j][i] = true;
                }
            }
        }
        return num;
    }
};
