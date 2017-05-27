Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

class Solution {
public:
    vector<int> nextPermutation(vector<int>& nums) {
        int flag = 0;
        vector<int> res = nums;
        for (int i = res.size() - 2; i >= 0 && flag == 0; i--) {
            if(res[i + 1] > res[i]) {
                for (int j = res.size() - 1; j >= i + 1; j--) {
                    if(res[i] < res[j]) {
                        swap(res[i], res[j]);
                        reverse(res.begin() + i + 1, res.end());
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 0) reverse(res.begin(), res.end());
        return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp = nums;
        res.push_back(temp);
        while(nums != (temp = nextPermutation(temp))) {
            res.push_back(temp);
        }
        return res;
    }
};
