Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for (int s : nums)
            diff ^= s;
        
        diff &= -diff;
        
        vector<int> res = {0, 0};
        
        for (int n : nums) {
            if ((n & diff) == 0) res[0] ^= n;
            else res[1] ^= n;
        }
        return res;
    }
};
