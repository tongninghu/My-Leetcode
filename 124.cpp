Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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
private:
    int sum = INT_MIN;
public:
    int helper(TreeNode* root) {
        if (!root) return 0;
        int L = max(0, helper(root->left));
        int R = max(0, helper(root->right));
        sum = max(root->val + L + R, sum);
        return max(L, R) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return sum;
    }
};
