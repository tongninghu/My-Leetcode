Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArray(vector<int>& nums, int begin, int end) {
        if (begin == end) return new TreeNode(nums[begin]);
        else if (begin + 1 == end) {
            TreeNode *root = new TreeNode(nums[end]);
            root->left = new TreeNode(nums[begin]);
            return root;
        }
        else {
            int middle;
            if ((end - begin + 1) % 2 == 1) middle = (begin + end) / 2;
            else middle = (begin + end + 1) / 2;
            TreeNode *root = new TreeNode(nums[middle]);
            root->left = sortedArray(nums, begin, middle - 1);
            root->right = sortedArray(nums, middle + 1, end);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return sortedArray(nums, 0, nums.size() - 1);
    }
};
