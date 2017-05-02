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
    int hight(TreeNode* root) {
        if (!root) return 0;
        int left = hight(root->left);
        int right = hight(root->right);
        if (abs(left - right) > 1 || left == -1 || right == -1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(hight(root) == -1) return false;
        else return true;
    }
};
