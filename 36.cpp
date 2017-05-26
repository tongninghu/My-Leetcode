Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> hashr;
        unordered_map<int, unordered_set<int>> hashc;
        unordered_map<int, unordered_set<int>> hashs;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(isdigit(board[i][j])) {
                    int k = board[i][j] - '0';
                    unordered_map<int, unordered_set<int>>::iterator itrr = hashr.find(k);
                    if(itrr == hashr.end()) {
                        unordered_set<int> temp;
                        temp.insert(i);
                        hashr[k] = temp;
                    }
                    else if (itrr->second.find(i) == itrr->second.end())  itrr->second.insert(i);
                    else return false;

                    unordered_map<int, unordered_set<int>>::iterator itrc = hashc.find(k);
                    if(itrc == hashc.end()) {
                        unordered_set<int> temp;
                        temp.insert(j);
                        hashc[k] = temp;
                    }
                    else if (itrc->second.find(j) == itrc->second.end()) itrc->second.insert(j);
                    else return false;

                    unordered_map<int, unordered_set<int>>::iterator itrs = hashs.find(k);
                    if(itrs == hashs.end()) {
                        unordered_set<int> temp;
                        temp.insert(i / 3 * 3 + j / 3);
                        hashs[k] = temp;
                    }
                    else if (itrs->second.find(i / 3 * 3 + j / 3) == itrs->second.end()) itrs->second.insert(i / 3 * 3 + j / 3);
                    else return false;
                }
            }
        }
        return true;
    }
};
