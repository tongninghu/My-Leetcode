You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> WO (nums.size() + 2, 0);
        vector<int> WI (nums.size() + 2, 0);

        for (int i = 0; i < nums.size(); i++) {
            WO[i + 1] = max(WO[i], WI[i]);
            WI[i + 1] = WO[i] + nums[i];
        }
        return max(WO[nums.size()], WI[nums.size()]);
    }
};
