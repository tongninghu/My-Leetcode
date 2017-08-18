Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1: 
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2: 
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1

class Solution {
public:   
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> distance(matrix.size(), vector<int>(matrix[0].size(), INT_MAX));
        queue<vector<int>> q;
        for (int i = 0; i < matrix.size(); i++) 
            for (int j = 0; j < matrix[0].size(); j++)
                if (matrix[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push(vector<int> {i, j});
                }
        
        while (!q.empty()) {
            vector<int> t = q.front();
            q.pop();
            
            vector<vector<int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (vector<int> d : dirs) {
                int i = t[0] + d[0];
                int j = t[1] + d[1];
                if (i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size()) continue;
                if (distance[i][j] > distance[t[0]][t[1]] + 1) {
                    distance[i][j] = distance[t[0]][t[1]] + 1;
                    q.push(vector<int>{i, j});
                }
            }
        }
        return distance;
    }
};
