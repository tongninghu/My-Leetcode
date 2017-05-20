Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

class Solution {
public:
    int longestValidParentheses(string s) {
        int m = s.length(), count = 0;
        vector<int> dp (m + 1, 0);
        for (int i = 0; i < m; i++) {
            int j = i - dp[i] - 1;
            if (i > 0 && s[i] == ')' && j >= 0 && s[j] == '(') dp[i + 1] = dp[i] + 2 + dp[j];
            count = max(count, dp[i + 1]);
        }
        return count;
    }
};
