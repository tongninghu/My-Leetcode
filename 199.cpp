Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

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
    void  InsertVector(TreeNode* root, int i, vector<int>& level) {
              if (i >= level.size()) {
                  level.push_back(root->val);
              }
              if (root->right) InsertVector(root->right, i + 1, level);
              if (root->left) InsertVector(root->left, i + 1, level);
           }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> level;
        if (!root) return level;
        InsertVector(root, 0, level);
        return level;
    }
};
