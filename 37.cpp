Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

class Solution {
    int usedr[9][9] = {0}, usedc[9][9] = {0}, useds[9][9] = {0};
public:
    void fillhash(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); ++ i)
            for(int j = 0; j < board[i].size(); ++ j)
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    usedr[i][num] = usedc[j][num] = useds[k][num] = 1;
                }
    }
    
    void dfs(int start, vector<char>& cur, vector<vector<char>>& board) {
        if (start == 81) {
            int count = 0;
            for(int i = 0; i < board.size(); ++ i)
                for(int j = 0; j < board[i].size(); ++ j)
                    if(board[i][j] == '.') board[i][j] = cur[count++];
            return;
        }
        int i = start / 9, j = start % 9, k = i / 3 * 3 + j / 3;
        if (board[i][j] != '.') dfs(start + 1, cur, board);
        else {
            for(int s = 1; s <= 9; s++) {
                if(usedr[i][s - 1] == 0 && usedc[j][s - 1] == 0 && useds[k][s - 1] == 0) {
                    usedr[i][s - 1] = usedc[j][s - 1] = useds[k][s - 1] = 1;
                    cur.push_back('0' + s);
                    dfs(start + 1, cur, board);
                    cur.pop_back();
                    usedr[i][s - 1] = usedc[j][s - 1] = useds[k][s - 1] = 0;
                } 
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<char> cur;
        fillhash(board);
        dfs(0, cur, board);
    }
};
