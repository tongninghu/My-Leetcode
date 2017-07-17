You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for (int s : nums)
            sum += s;
        
        if (S > sum || S < -sum) return 0;
        
        vector<vector<int>> dp (nums.size() , vector<int> (2 * sum + 1, 0));
        dp[0][nums[0] + sum]++;
        dp[0][-nums[0] + sum]++;
     
        for (int i = 1; i < nums.size(); i++) {
            for (int j = -sum; j <= sum; j++) {
                if ((j - nums[i] + sum) >= 0 && (j + nums[i] + sum) <= 2 * sum) dp[i][j + sum] = dp[i - 1][j - nums[i] + sum] + dp[i - 1][j + nums[i] + sum];
                else if (j - nums[i] + sum < 0) dp[i][j + sum] = dp[i - 1][j + nums[i] + sum];
                else if (j + nums[i] + sum > 2 * sum) dp[i][j + sum] = dp[i - 1][j - nums[i] + sum];
            }
        }
        return dp[nums.size() - 1][S + sum];
    }
};
