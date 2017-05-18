Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
  [1,  0, 1],
  [0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(), col = matrix[0].size(), max_res = INT_MIN;
        for (int l = 0; l < col; l++) {
            int sums[row] = {0};
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; i++) {
                    sums[i] += matrix[i][r];
                }
                set<int> my_set;
                int max_cur = INT_MIN, sum = 0;
                my_set.insert(0);
                for(int s : sums) {
                    sum += s;
                    set<int>::iterator itr = my_set.lower_bound(sum - k);
                    if(itr != my_set.end()) max_cur = max(max_cur, sum - *itr);
                    my_set.insert(sum);
                }
                max_res = max(max_res, max_cur);
            }
        }
        return max_res;
    }
};
