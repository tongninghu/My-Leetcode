Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                major = nums[i];
                count++;
            }
            else if (major != nums[i]) count--;
            else count++;
        }
        return major;
    }
};
