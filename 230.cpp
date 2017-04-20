Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

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
    vector<int> my_vector;
public:
    void helper(TreeNode* root) {
        if (root->left) helper(root->left);
        my_vector.push_back(root->val);
        if (root->right) helper(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        my_vector.push_back(0);
        helper(root);
        return my_vector[k];
    }
};

/**     faster method
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
    void helper(TreeNode* root, int & k, int &find) {
        if (root->left)  helper(root->left, k, find);
            k--;
        if (k == 0) find = root->val;
        if (root->right) helper(root->right, k, find);
    }
    int kthSmallest(TreeNode* root, int k) {
        int find = 0;
        helper(root, k, find);
        return find;
    }
};
