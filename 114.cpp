Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
    TreeNode* helper(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* L = helper(root->left);
        TreeNode* R = helper(root->right);
        if(!root->left && !root->right) return root;
        else if(root->left && !root->right) {
            root->right = root->left;
            root->left = NULL;
            return L;
        }
        else if(!root->left && root->right)  return R;
        else {
            L->right = root->right;
            root->right = root->left;
            root->left = NULL;
            return R;
        }
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};

