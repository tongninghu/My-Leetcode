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
            if (nums[mid] < nums[high]) high = mid;   // this means when upper half is normal, so mini must lies in lower half, whether it's normal or not.
            else low = mid + 1;     // when upper half is abnormal, it means the rotating point is in upper half, so mini is there.
        }
        return nums[low];
    }
};
