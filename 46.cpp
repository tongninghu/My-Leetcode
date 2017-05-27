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
    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>>& result) {
        if (begin > nums.size() - 1) result.push_back(nums);
        else {
            for(int i = begin; i < nums.size(); i++) {
                swap(nums[begin], nums[i]);
                permuteRecursive(nums, begin + 1, result);
                swap(nums[begin], nums[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecursive(nums, 0, result);
        return result;
    }
};
