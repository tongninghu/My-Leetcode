Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int start, end;
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size(); i++) {
            start = i + 1;
            end = nums.size() - 1;
            while(start < end) {
                if (nums[start] + nums[end] < target - nums[i]) {
                    if(target - (nums[i] + nums[start] + nums[end]) < abs(target - res)) res = nums[i] + nums[start] + nums[end];
                    start++;
                }
                else if (nums[start] + nums[end] > target - nums[i]) {
                    if(nums[i] + nums[start] + nums[end] - target < abs(target - res)) res = nums[i] + nums[start] + nums[end];
                    end--;
                }
                else {
                    res = target;
                    break;
                }
            }
        }
        return res;
    }
};
