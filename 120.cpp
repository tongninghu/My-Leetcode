Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), res = triangle[0][0];
        vector<int> dp (n, 0);
        dp[0] = triangle[0][0];
        int prev = 0;
        for(int i = 1; i < triangle.size(); i++) {
            res = INT_MAX;
            for(int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    prev = dp[0];
                    dp[0] = triangle[i][j] + dp[0];
                }
                else if (j == triangle[i].size() - 1) 
                    dp[j] = prev + triangle[i][j];
                else {
                    int temp = dp[j];
                    dp[j] = min(prev, dp[j]) + triangle[i][j];    
                    prev = temp;
                }
                res = min(res, dp[j]);
            }
        }
        return res;
    }
};
