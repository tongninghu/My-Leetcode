Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

class Solution {
public:
    vector<int> helper(int low, int high, vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int l, r;
        int mid = (high - low) / 2 + low;
        while (nums[mid] != target && low < high) {
            if (nums[mid] > target) high = mid;
            else low = mid + 1;
            mid = (high - low) / 2 + low;
        }
        if (nums[mid] != target)  return res;
        
        if (high >= (mid + 1) && nums[mid + 1] == target)  {
            res = helper(mid + 1, high, nums, target);
            r = res[1];
        }
        else r = mid;
        if (low <= (mid - 1) && nums[mid - 1] == target) {
            res = helper(low, mid - 1, nums, target);
            l = res[0];
        }
        else l = mid;
        res = {l, r}; 
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int> {-1, -1};
        return helper(0, nums.size() - 1, nums, target);
    }
};
