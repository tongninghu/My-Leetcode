Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

class Solution {
public:
    void DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& visited, int prev) {
        if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size()) return;
        if (matrix[i][j] < prev || visited[i][j]) return;
        
        visited[i][j] = true;
        
        DFS(matrix, i - 1, j, visited, matrix[i][j]);
        DFS(matrix, i, j - 1, visited, matrix[i][j]);
        DFS(matrix, i + 1, j, visited, matrix[i][j]);
        DFS(matrix, i, j + 1, visited, matrix[i][j]);   
    }
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if (matrix.size() == 0) return res;
        vector<vector<bool>> Pacific(matrix.size(), vector<bool>(matrix[0].size(), false));  
        vector<vector<bool>> Atlantic(matrix.size(), vector<bool>(matrix[0].size(), false));  
        for (int i = 0; i < matrix[0].size(); i++) {
            DFS(matrix, 0, i, Pacific, INT_MIN);
            DFS(matrix, matrix.size() - 1, i, Atlantic, INT_MIN);
        }
        for (int i = 0; i < matrix.size(); i++) {
            DFS(matrix, i, 0, Pacific, INT_MIN);
            DFS(matrix, i, matrix[0].size() - 1, Atlantic, INT_MIN);
        }
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++) 
                if (Pacific[i][j] && Atlantic[i][j]) res.push_back(pair<int, int>(i, j));
        return res;
    }
};
