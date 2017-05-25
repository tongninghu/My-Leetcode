Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int start, end;
        for(int i = 0; i < nums.size(); i++) {
            start = i + 1;
            end = nums.size() - 1;
            while(start < end) {
                if (nums[start] + nums[end] < -nums[i]) start++;
                else if (nums[start] + nums[end] > -nums[i]) end--;
                else {
                    vector<int> temp (3, 0);
                    temp[0] = nums[i];
                    temp[1] = nums[start];
                    temp[2] = nums[end];
                    res.push_back(temp);
                    while(start < end && nums[start] == nums[start + 1]) start++;
                    while(start < end && nums[end] == nums[end - 1]) end--;
                    start++;
                    end--;
                }
            }
            while(i < nums.size() && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};
