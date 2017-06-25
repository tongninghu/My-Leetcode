Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
A solution set is: 
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& cur, vector<int>& candidates, int target, int begin, int& pop) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        
        for(int i = begin; i < candidates.size() && candidates[i] <= target; i++) {
            if(i > 0 && pop == candidates[i]) continue;
            cur.push_back(candidates[i]);
            dfs(res, cur, candidates, target - candidates[i], i + 1, pop);
            pop = cur[cur.size() - 1];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> cur;
        int pop = INT_MAX;
        dfs(res, cur, candidates, target, 0, pop);
        return res;
    }
};
