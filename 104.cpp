Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxD(TreeNode* root) {
        if (!root) return 0;
        int left = maxD(root->left);
        int right = maxD(root->right);
        return max(left, right) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        return maxD(root);
    }
};
