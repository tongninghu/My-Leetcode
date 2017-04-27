Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

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
                int j = i + l - 1, sum = 0;
                for( int k = i; k <= j; k++) {
                    if (l != nums.size()) sum = max(sum, m[i][k - 1] + m[k + 1][j]);
                    else sum = max(m[2][nums.size()], m[1][nums.size() - 1]);
                }
                m[i][j] = sum;
            }
        }
        return m[1][nums.size()];
    }
};
