Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    void circle(vector<vector<int>>& matrix, int start, int e_row, int e_col, vector<int>& res) {
        if(e_row <= start || e_col <= start) {
            if(e_row == start) {
                for(int i = start; i <= e_col; i++)
                    res.push_back(matrix[start][i]);
            }
            else if (e_col == start){
                for(int i = start; i <= e_row; i++) 
                    res.push_back(matrix[i][start]);
            }
            return;
        }
        if(start != e_row && start != e_col) {
            res.insert(res.end(), matrix[start].begin() + start, matrix[start].end() - start);
            for(int i = start + 1; i <= e_row; i++) 
                res.push_back(matrix[i][e_col]);
            for(int i = e_col - 1; i >= start; i--)
                res.push_back(matrix[e_row][i]);
            for(int i = e_row - 1; i > start; i--)
                res.push_back(matrix[i][start]);
            circle(matrix, start + 1, e_row - 1, e_col - 1, res);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0) return res;
        circle(matrix, 0, matrix.size() - 1, matrix[0].size() - 1, res);
        return res;
    }
};
