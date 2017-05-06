Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

class Solution {
public:
    void dfs(vector<string>& res, vector<string>& cur, int& count, int start, int n) {
        if (start == 2 * n && count == 0) {
            string t;
            for(int i = 0; i < cur.size(); i++) {
                t += cur[i];
            }
            res.push_back(t);
            return;
        }
        if (start == 2 * n && count != 0) return;

        cur.push_back("(");
        count++;
        dfs(res, cur, count, start + 1, n);
        cur.pop_back();
        count--;
        if (count > 0) {
            cur.push_back(")");
            count--;
            dfs(res, cur, count, start + 1, n);
            cur.pop_back();
            count++;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        vector<string> cur;
        if(n == 0) return res;
        int count = 1;
        cur.push_back("(");
        dfs(res, cur, count, 1, n);
        return res;
    }
};
