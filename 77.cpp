Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& cur, int n, int k, int begin) {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        for(int i = begin; i <= n; i++) {
            cur.push_back(i);
            dfs(res, cur, n, k, i + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, n, k, 1);
        return res;
    }
};
