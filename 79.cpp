Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

class Solution {
public:
    bool dfs(vector<vector<int>>& map, vector<vector<char>>& board, string word, int x, int y, int m, int n, int& counter) {
        if (x < 0 || x >= m || y < 0 || y >= n || map[x][y] == 1 || board[x][y] != word[counter]) return false;
        else if (board[x][y] == word[counter] && counter == word.size() - 1) return true;
        else {
            counter++;
            map[x][y] = 1;
            if (dfs(map, board, word, x - 1, y, m, n, counter) || dfs(map, board, word, x + 1, y, m, n, counter) || dfs(map, board, word, x, y - 1, m, n, counter) || dfs(map, board, word, x, y + 1, m, n, counter)) return true;
            counter--;
            map[x][y] = 0;
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), counter = 0;
        vector<vector<int>> map(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(map, board, word, i, j, m, n, counter)) return true;
            }
        }
        return false;
    }
};
