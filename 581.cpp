Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> array_max(nums.size(), 0);
        array_max[0] = nums[0];
        int left = 0, right = nums.size() - 1, maxi = INT_MIN, mini = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > array_max[i - 1]) array_max[i] = nums[i];
            else array_max[i] = array_max[i - 1];
        }
        while(left < nums.size() && array_max[left] == nums[left]) left++;
        while(right >= 0 && array_max[right] == nums[right]) right--;
        if (right < left) return 0;
        
        for (int i = left; i <= right; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        
        while (left > 0 && nums[left - 1] > mini) left--;
        while (right < nums.size() - 1 && nums[right + 1] < maxi) right++;
        
        return right - left + 1;  
    }
};
