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
    void findMistake(TreeNode *root, int& num, bool& flag, int& i) {
        if (root->left)    findMistake(root->left, num, flag, i);
        if (num >= root->val && i != 1) flag = false;
        num = root->val;
        i++;
        if (root->right)   findMistake(root->right, num, flag, i);
    }
    bool isValidBST(TreeNode* root) {
        bool flag = true;
        int num = INT_MIN, i = 1;
        if (!root) return true;
        findMistake(root, num, flag, i);
        return flag;
    }
};
