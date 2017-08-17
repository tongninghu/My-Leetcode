Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

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
    void helper(TreeNode* root, int l, vector<int>& res) {
        if (!root) return;
        if (l >= res.size()) res.push_back(root->val);
        helper(root->left, l + 1, res);
        helper(root->right, l + 1, res);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res[res.size() - 1];
    }
};
