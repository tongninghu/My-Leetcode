Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) return vector<int> ();
        vector<int> dp(nums.size(), 1);
        vector<int> track(nums.size(), -1);
        vector<int> res;
        sort(nums.begin(), nums.end());
        int cur_num = 1, end = -1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    track[i] = j;
                }
            }
            if (dp[i] > cur_num) {
                cur_num = dp[i];
                end = i;
            }
        }
        if (end == -1) return vector<int> {nums[0]};
        
        while (end != -1) {
            res.push_back(nums[end]);
            end = track[end];
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
