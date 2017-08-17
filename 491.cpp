Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& cur, vector<vector<int>>& res, int begin) {
        if (cur.size() >= 2) res.push_back(cur);
        if (begin == nums.size()) return;
        
        unordered_set<int> hash;
        
        for (int i = begin; i < nums.size()  ; i++) {
            if ((cur.size() == 0 || nums[i] >= cur.back()) && hash.find(nums[i]) == hash.end()) {
                cur.push_back(nums[i]);
                helper(nums, cur, res, i + 1);
                cur.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        if (nums.size() == 0) return res;
        helper(nums, cur, res, 0);
        return res;
    }
};
