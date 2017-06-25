Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int begin) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        
        for(int i = begin; i <= candidates.size() - 1 && candidates[i] <= target; i++) {
            cur.push_back(candidates[i]);
            dfs(res, cur, candidates, target - candidates[i], i);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, candidates, target, 0);
        return res;
    }
};
