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
    void dfs(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, unordered_set<int>& record) {
        if(cur.size() == nums.size()) {
            res.push_back(cur);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
                if(record.find(nums[i]) == record.end()) {
                cur.push_back(nums[i]);
                record.insert(nums[i]);
                dfs(nums, cur, res, record);
                cur.pop_back();
                record.erase(nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        unordered_set<int> record;
        dfs(nums, cur, res, record);
        return res;
    }
};
