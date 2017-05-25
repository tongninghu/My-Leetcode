Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

class Solution {
public:
    vector<vector<int>> threeSum(int begin, vector<int>& nums, int target) {
        vector<vector<int>> res;
        int start, end;
        for(int i = begin; i < nums.size(); i++) {
            start = i + 1;
            end = nums.size() - 1;
            while(start < end) {
                if (nums[start] + nums[end] < target - nums[i]) start++;
                else if (nums[start] + nums[end] > target - nums[i]) end--;
                else {
                    vector<int> temp (4, 0);
                    temp[1] = nums[i];
                    temp[2] = nums[start];
                    temp[3] = nums[end];
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
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        int start, end;
        for(int i = 0; i < nums.size() - 3; i++) {
            vector<vector<int>> temp = threeSum(i + 1, nums, target - nums[i]);
            for(int j = 0; j < temp.size(); j++) {
                temp[j][0] = nums[i];
                res.push_back(temp[j]);
            }
            while(i < nums.size() - 3 && nums[i] == nums[i + 1]) i++;
        }
        return res;
    }
};
