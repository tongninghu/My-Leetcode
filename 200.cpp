Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

class Solution {
private:
    int num = 0;
public:
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& res) {
        res[i][j] = 1;
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1' && res[i][j + 1] == 0) DFS(i, j + 1, grid, res);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1' && res[i + 1][j] == 0) DFS(i + 1, j, grid, res);
        if (j - 1 >= 0 && grid[i][j - 1] == '1' && res[i][j - 1] == 0) DFS(i, j - 1, grid, res);
        if (i - 1 >= 0 && grid[i - 1][j] == '1' && res[i - 1][j] == 0) DFS(i - 1, j, grid, res);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        vector<vector<int>> res (grid.size(), vector<int>(grid[0].size(), 0));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && res[i][j] == 0) {
                    DFS(i, j, grid, res);
                    num++;
                }
            }
        }
        return num;
    }
};
