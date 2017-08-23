Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res = {1};
        while (rowIndex > 0) {
            int tempp = 1, temp = 1;
            for (int i = 1; i < res.size(); i++) {
                temp = res[i];
                res[i] = tempp + res[i];
                tempp = temp;
            }
            res.push_back(1);
            rowIndex--;
        }
        return res;
    }
};
