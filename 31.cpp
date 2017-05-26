Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        int flag = 0;
        for (int i = nums.size() - 2; i >= 0 && flag == 0; i--) {
            if(nums[i + 1] > nums[i]) {
                for (int j = nums.size() - 1; j >= i + 1; j--) {
                    if(nums[i] < nums[j]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(flag == 0) reverse(nums.begin(), nums.end());
    }
};
