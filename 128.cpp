Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int res = 0;
        for (int s : nums) {
            if (map.find(s) == map.end()) {
                int left = (map.find(s - 1) != map.end())? map[s - 1] : 0;
                int right = (map.find(s + 1) != map.end())? map[s + 1] : 0;
                map[s] = left + right + 1;
                map[s - left] = left + right + 1;
                map[s + right] = left + right + 1;
                res = max(res, left + right + 1);
            }
        }
        return res;
    }
};
