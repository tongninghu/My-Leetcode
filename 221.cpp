Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0) return 0;
        int row = matrix.size(), col = matrix[0].size(), size = INT_MIN;
        vector<vector<int>> dp (row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            dp[i][0] = matrix[i][0] - '0';
            size = max(size, dp[i][0]);
        }
        
        for (int j = 1; j < col; j++) {
            dp[0][j] = matrix[0][j] - '0';
            size = max(size, dp[0][j]);
        }
        
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == '1') dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1; 
                size = max(size, dp[i][j]);
            }
        }
        return size * size;
    }
};
