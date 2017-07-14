Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1, count = 0, zero = 0;
        vector<int> res (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) product *= nums[i];
            else {
                count++;
                zero = i;
            }
        }
        if (count == 0) {
            for (int i = 0; i < nums.size(); i++)
                res[i] = product / nums[i];
        }
        else if (count == 1) res[zero] = product;
       
        return res;
    }
};
