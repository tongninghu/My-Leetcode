Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
    void Invert(TreeNode* root) {
        TreeNode* temp;
        if (root->left || root->right) {
            temp = root->left;
            root->left = root->right;
            root->right = temp;
        }
        if (root->left) Invert(root->left);
        if (root->right) Invert(root->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        Invert(root);
        return root;
    }
};
