Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.

Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
        
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
    TreeNode* insert(int element, TreeNode* root, unordered_map<int, int>& map) {
        if (!root) return new TreeNode(element);
        if (map[element] > map[root->val]) 
            root->right = insert(element, root->right, map);
        else if (map[element] < map[root->val]) 
            root->left = insert(element, root->left, map);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }
        sort(nums.begin(), nums.end());
        TreeNode* root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
            root = insert(nums[i], root, map);
        }
        return root;
    }
};
