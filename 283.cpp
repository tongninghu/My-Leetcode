Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int position = 0;
        for(int s : nums)
            if (s != 0) nums[position++] = s;
       
        while (position < nums.size())
            nums[position++] = 0;
    }
};
