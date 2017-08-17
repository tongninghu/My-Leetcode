Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

class Solution {
public:
    int DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& cache, int pre) {   
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size()) return 0;
        if (matrix[i][j] <= pre) return 0;
        
        if (cache[i][j] > 0) return cache[i][j];
        int d1 = DFS(matrix, i, j + 1, cache, matrix[i][j]);
        int d2 = DFS(matrix, i + 1, j, cache, matrix[i][j]);
        int d3 = DFS(matrix, i, j - 1, cache, matrix[i][j]);
        int d4 = DFS(matrix, i - 1, j, cache, matrix[i][j]);
        cache[i][j] = 1 + max(max(d1, d2), max(d3, d4));
        return cache[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res = 0;
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<vector<int>>cache (matrix.size(), vector<int>(matrix[0].size(), 0)); 
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                int d = DFS(matrix, i, j, cache, INT_MIN);
                res = max(res, d);
            }
        }
        return res;        
    }
};
