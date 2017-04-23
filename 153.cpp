Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int low = 0, high = nums.size() - 1, mid;
        while (low < high) {
            mid = (high - low) / 2 + low;
            if (nums[mid] < nums[high]) high = mid;
            else low = mid + 1;
        }
        return nums[low];
    }
};
