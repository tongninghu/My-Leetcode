Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
    void RootToLeaf(TreeNode* root, int sum, int target, bool& flag) {
        sum = sum + root->val;
        if (!root->left && !root->right)   if (sum == target) flag = true;
        if (root->left) RootToLeaf(root->left, sum, target, flag);
        if (root->right) RootToLeaf(root->right, sum, target, flag);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = false;
        if (!root) return false;
        RootToLeaf(root, 0, sum, flag);
        return flag;
    }
};
