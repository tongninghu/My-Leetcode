The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]

class Solution {
public:
    bool sameDiagonal(vector<int>& cur, int j) {
        for(int i = 0; i < cur.size(); i++) 
            if(cur[i] + cur.size() - i == j || cur[i] - cur.size() + i == j) return false;
        return true;
    }
    void dfs(vector<int>& cur, vector<vector<int>>& res, int start, int n, vector<int>& used) {
        if(start == n) {
            res.push_back(cur);
            return;
        }
        for(int j = 0; j < n; j++) {
            if(used[j] == 0 && sameDiagonal(cur, j)) {
                cur.push_back(j);
                used[j] = 1;
                dfs(cur, res, start + 1, n, used);
                used[j] = 0;
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> used (n, 0);
        vector<int> cur;
        vector<vector<int>> res;
        dfs(cur, res, 0, n, used);
        vector<vector<string>> puzzle;
        for(int i = 0; i < res.size(); i++) {
            vector<string> temp (n, string(n, '.'));
            for(int j = 0; j < n; j++) 
                temp[j][res[i][j]] = 'Q';
            puzzle.push_back(temp);
        }
        return puzzle;
    }
};
