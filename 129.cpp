Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.

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
    void accumulate(TreeNode* root, int sum, vector<int>& my_vector) {
        if (!root->left && !root->right) my_vector.push_back(sum * 10 + root->val);
        if (root->left)  accumulate(root->left, sum * 10 + root->val, my_vector);
        if (root->right) accumulate(root->right, sum * 10 + root->val, my_vector);
    }
    int sumNumbers(TreeNode* root) {
        vector<int> my_vector;
        if (!root) return 0;
        else accumulate(root, 0, my_vector);
        int sum = 0;
        for (int i = 0; i < my_vector.size(); i++) {
            sum = sum + my_vector[i];
        }
        return sum;
    }
};
