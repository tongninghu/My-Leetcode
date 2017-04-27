You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        int m[nums.size() + 2][nums.size() + 2] = {0};
        for (int i = 0; i < nums.size(); i++) {
            m[i + 1][i + 1] = nums[i];
        }
        for (int l = 2; l <= nums.size(); l++) {
            for (int i = 1; i <= nums.size() - l + 1; i++) {
                int j = i + l - 1;
                int sum = 0;
                for (int k = i; k <= j; k++) {
                    sum = max(sum, m[i][k - 1] + m[k + 1][j]);
                }
                m[i][j] = sum;
            }
        }
        return m[1][nums.size()];
    }
};
