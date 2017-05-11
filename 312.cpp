Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> dp (nums.size() + 5, vector<int> (nums.size() + 5, 0));
        nums.insert(nums.begin(), 1);
        nums[size + 1] = 1;

        for (int l = 1; l <= size; l++) {
            for (int i = 1; i <= size - l + 1; i++) {
                int m = 0, j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    m = max(m, nums[k] * nums[i - 1] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
                }
                dp[i][j] = m;
            }
        }
        return dp[1][size];
    }
};
