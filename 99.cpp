Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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
    TreeNode *p1 = NULL, *p2 = NULL, *prev;
public:
    void findMistake(TreeNode *root, int& num) {
        if (root->left)    findMistake(root->left, num);
        if (num >= root->val) {
            if (!p1) {
                p1 = prev;
                p2 = root;
            }
            else p2 = root;
        }
        num = root->val;
        prev = root;
        if (root->right)   findMistake(root->right, num);
    }
    void recoverTree(TreeNode* root) {
        int num = INT_MIN;
        findMistake(root, num);
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
    }
};
