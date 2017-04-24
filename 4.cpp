There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

class Solution {
public:
    double getKthSmall(vector<int>& nums1, int s1, vector<int>& nums2, int s2, int k) {
        int n1 = nums1.size() - s1, n2 = nums2.size() - s2;
        if (n1 == 0) return nums2[s2 + k - 1];
        if (n2 == 0) return nums1[s1 + k - 1];
    
        if (k == 1) return min(nums1[s1], nums2[s2]);
        int i = min(n1, k / 2), j = min(n2, k / 2);
        
        if (nums1[s1 + i - 1] > nums2[s2 + j - 1]) return getKthSmall(nums1, s1, nums2, s2 + j, k - j);
        else return getKthSmall(nums1, s1 + i, nums2, s2, k - i);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k1 = (nums1.size() + nums2.size() + 1) / 2;
        int k2 = (nums1.size() + nums2.size() + 2) / 2;
        double a = getKthSmall(nums1, 0, nums2, 0, k1);
        double b = getKthSmall(nums1, 0, nums2, 0, k2);
        return (a + b) / 2;
    }
};
