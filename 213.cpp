Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> WO (nums.size() + 2, 0);
        vector<int> WI (nums.size() + 2, 0);
        vector<int> WOR (nums.size() + 2, 0);
        vector<int> WIR (nums.size() + 2, 0);
        for (int i = 0; i < nums.size(); i++) {
            WO[i + 1] = max(WO[i], WI[i]);
            WI[i + 1] = WO[i] + nums[i];
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            WOR[nums.size() - i] = max(WOR[nums.size() - i - 1], WIR[nums.size() - i - 1]);
            WIR[nums.size() - i] = WOR[nums.size() - i - 1] + nums[i];
        }
        return max(WO[nums.size()], WOR[nums.size()]);
    }
};
