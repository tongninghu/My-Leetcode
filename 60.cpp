The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        int flag = 0;
        for (int i = nums.size() - 2; i >= 0 && flag == 0; i--) {
            if(nums[i + 1] > nums[i]) {
                for (int j = nums.size() - 1; j >= i + 1; j--) {
                    if(nums[i] < nums[j]) {
                        swap(nums[i], nums[j]);
                        reverse(nums.begin() + i + 1, nums.end());
                        flag = 1;
                        break;
                    }
                }
            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i = 1; i <= n; i++) nums.push_back(i);
        for(int j = 1; j < k; j++) nextPermutation(nums);
        string res;
        for(int i = 0; i < nums.size(); i++) res += '0' + nums[i];
        return res;
    }
};
