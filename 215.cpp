Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ? k ? array's length.

class Solution {
public:
    int partition(vector<int>& nums, int left, int right) {
        int l = left + 1, r = right, pivot = nums[left];
        while(l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) l++;
            if (nums[r] <= pivot) r--;
        }
        swap(nums[r], nums[left]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, position;
        while (1) {
            position = partition(nums, l, r);
            if (position == k - 1) return nums[position];
            else if (position < k - 1) l = position + 1;
            else r = position - 1;
        }      
    }
};
