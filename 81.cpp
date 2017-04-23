Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Write a function to determine if a given target is in the array.

The array may contain duplicates.

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (high - low) / 2 + low;
            if (nums[mid] == nums[high]) high = high - 1;
            else if (nums[low] <= nums[mid]) {
                if (target >= nums[low] && target <= nums[mid]) high = mid;
                else low = mid + 1;
            }
            else  {
                if (target > nums[mid] && target <= nums[high]) low = mid + 1;
                else high = mid;
            }
        }
        return (nums[low] == target)? true : false;            
    }
};
