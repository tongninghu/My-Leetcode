Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]

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
    void helper(TreeNode* root, vector<int> path, vector<vector<int>>& my_vector, int sum) {
        if (!root) return;
        path.push_back(root->val);
        if (root->val == sum && !root->left && !root->right)   my_vector.push_back(path);
        helper(root->left, path, my_vector, sum - root->val);
        helper(root->right, path, my_vector, sum - root->val);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> my_vector;
        vector<int> temp;
        helper(root, temp, my_vector, sum);
        return my_vector;
    }
};
