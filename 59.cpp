Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

class Solution {
public:
    void circle(vector<vector<int>>& matrix, int start, int end, int& num) {
        if (start > end) return;
        else if (start == end) {
            matrix[start][start] = num;
            return;
        }
        else {
            for(int i = start; i <= end; i++)
                matrix[start][i] = num++;
            for(int i = start + 1; i <= end; i++) 
                matrix[i][end] = num++;
            for(int i = end - 1; i >= start; i--)
                matrix[end][i] = num++;
            for(int i = end - 1; i > start; i--)
                matrix[i][start] = num++;
            circle(matrix, start + 1, end - 1, num);
        }
    }
    
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        vector<vector<int>> matrix(n, vector<int> (n, 0));
        circle(matrix, 0, n - 1, num);
        return matrix;
    }
};
