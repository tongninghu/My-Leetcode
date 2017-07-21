Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum_p = 0, current_ending = 0, maxsum_n = INT_MIN;
        bool p = false;
        for (int s : nums) {
            if (s < 0) maxsum_n = max(maxsum_n, s);
            current_ending += s;
            
            if (current_ending >= 0) p = true;
            else if (current_ending < 0) current_ending = 0;
            
            maxsum_p = max(maxsum_p, current_ending);
        }
        return (p)? maxsum_p : maxsum_n;
    }
};
