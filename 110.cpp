Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
    int hight(TreeNode* root, int depth) {
        int l = depth, r = depth;
        if (!root->left && !root->right) return depth;
        if (root->left)  l = hight(root->left, depth + 1);
        if (root->right) r = hight(root->right, depth + 1);
        if ((l - r) > 1 || (r - l) > 1) return INT_MAX;
        else return max(l, r);
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        if(hight(root, 1) == INT_MAX) return false;
        else return true;
    }
};
