Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minD (TreeNode* root) {
        if (!root) return 0;
        int left = minD(root->left);
        int right = minD(root->right);
        if (left == 0) return right + 1;
        else if (right == 0) return left + 1;
        else return min(left, right) + 1;
    }
    
    int minDepth(TreeNode* root) {
        return minD(root);
    }
};
