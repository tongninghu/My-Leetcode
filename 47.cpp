Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

class Solution {
public:
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, vector<int>& record) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(record[i] == 1 || record[i - 1] == 0 && nums[i] == nums[i - 1] && i > 0) continue;
            cur.push_back(nums[i]);
            record[i] = 1;
            dfs(nums, cur, res, record);
            cur.pop_back();
            record[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        vector<int> record (nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums, cur, res, record);
        return res;
    }
};
