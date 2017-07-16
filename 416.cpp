Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int s : nums)
            sum += s;
        if (sum % 2 == 0) sum = sum / 2;
        else return false;
        
        vector<int> dp (sum + 1, INT_MIN);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = sum; j > 0; j--)
                if (nums[i] <= j) dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);   
            if (dp[sum] == sum) return true;
        }        
        return false;
    }
};
