Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> positive (n, 0);
        vector<int> negative (n, 0);
        if (nums[0] > 0) positive[0] = nums[0];
        else negative[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                positive[i] = max(nums[i], nums[i] * positive[i - 1]);              
                negative[i] = nums[i] * negative[i - 1];
            }
            else {
                positive[i] = nums[i] * negative[i - 1];
                negative[i] = min(nums[i], nums[i] * positive[i - 1]);
            }
            res = max(res, positive[i]);
        }
        return max(nums[0], res);
    }
};
