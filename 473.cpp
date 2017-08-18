Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.

class Solution {
public:
    bool dfs(vector<int>& nums, vector<int>& partition, int target, int begin) {
        if (begin == nums.size()) {
            if (partition[0] == target && partition[1] == target && partition[2] == target) return true;
            else return false;
        }
        
        for (int i = 0; i < 4; i++) {
            if (partition[i] + nums[begin] > target) continue;
            partition[i] += nums[begin];
            if (dfs(nums, partition, target, begin + 1)) return true;
            partition[i] -= nums[begin];
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        int sum = 0, num = 0;
        vector<int> partition (4, 0);
        if (nums.size() == 0) return false;
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        for (int s : nums)
            sum += s;
        if (sum % 4 != 0) return false;
        else sum = sum / 4;
        return dfs(nums, partition, sum, 0);
    }
};
