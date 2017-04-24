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
    void DFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visit) {
        if (i < 0 || j < 0 || i == grid.size() || j == grid[0].size()) return;
        if (grid[i][j] == '0' || visit[i][j] == true) return;
        visit[i][j] = true;
        DFS(i, j + 1, grid, visit);
        DFS(i + 1, j, grid, visit);
        DFS(i, j - 1, grid, visit);
        DFS(i - 1, j, grid, visit);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<bool>>visit (grid.size(), vector<bool>(grid[0].size(),false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visit[i][j] == false) {
                    DFS(i, j, grid, visit);
                    num++;
                }
            }
        }
        return num;
    }
};
