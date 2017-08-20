Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:
Input: [1,2,3]
Output: 6
Example 2:
Input: [1,2,3,4]
Output: 24

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0, max3 = 0, min1 = 0, min2 = 0, nmax1 = INT_MIN, nmax2 = INT_MIN, nmax3 = INT_MIN;
        bool flag = false;
        for (int s : nums) {
            if (s > 0) {
                if (s >= max1) {
                    max3 = max2;
                    max2 = max1;
                    max1 = s;
                }
                else if (s >= max2) {
                    max3 = max2;
                    max2 = s;
                }
                else if (s >= max3)
                    max3 = s;
            }
            else if (s < 0) {
                if (s <= min1) {
                    min2 = min1;
                    min1 = s;
                }
                else if (s <= min2)
                    min2 = s;
                if (s >= nmax1) {
                    nmax3 = nmax2;
                    nmax2 = nmax1;
                    nmax1 = s;
                }
                else if (s >= nmax2) {
                    nmax3 = nmax2;
                    nmax2 = s;
                }
                else if (s >= nmax3)
                    nmax3 = s;
            } 
            else flag = true;
        }
        if (max1 == 0) return (flag) ? 0 : (nmax1 * nmax2 * nmax3);
        return max(max1 * max2 * max3, max1 * min1 * min2);
    }
};
