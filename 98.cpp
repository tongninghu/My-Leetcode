Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3
Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3
Binary tree [1,2,3], return false.

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
    int findLarge(TreeNode* root, bool& Large) {
        if (!root->left && !root->right) return root->val; 
        if (root->left ) {
            int Left = findLarge(root->left, Large);
            if (root->val <= Left) {
                Large = false;
                return INT_MAX;
            }
        }
        if (root->right) {
            int Right = findLarge(root->right, Large);
            if (root->val >= Right) {
                Large = false;
                return INT_MAX;
            }
            else return Right;
        }
        return root->val;
    }
    int findSmall(TreeNode* root, bool& Small) {
        if (!root->left && !root->right) return root->val; 
        if (root->right ) {
            int Right = findSmall(root->right, Small);
            if (root->val >= Right) {
                Small = false;
                return INT_MIN;
            }
        }
        if (root->left) {
            int Left = findSmall(root->left, Small);
            if (root->val <= Left) {
                Small = false;
                return INT_MAX;
            }
            else return Left;
        }
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool Large = true, Small = true;
        int a = findLarge(root, Large);
        int b = findSmall(root, Small);
        return (Large && Small)? true : false;
    }
};
