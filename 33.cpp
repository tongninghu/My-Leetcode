Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (high - low) / 2 + low;
            if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid]) high = mid;
                else low = mid + 1;
            }
            else  {
                if (target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid;
            }
        }
        return (nums[low] == target)? low : -1;
    }
};
