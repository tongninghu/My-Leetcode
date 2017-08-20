Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.push_back(vector<int>(1, 1));
        if (numRows == 1) return res; 
        while (numRows > 1) {
            vector<int> temp;
            temp.push_back(1);
            for (int i = 0; i < res[res.size() - 1].size() - 1; i++) 
                temp.push_back(res[res.size() - 1][i] + res[res.size() - 1][i + 1]);
            temp.push_back(1);
            res.push_back(temp);
            numRows--;
        }
        return res;
    }
};
