Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> my_stack;
        vector<int> my_vector;
        while(root) {
            my_vector.push_back(root->val);
            if (root->right) my_stack.push(root);
            root = root->left;
        }
        while(!my_stack.empty()) {
          TreeNode *root = my_stack.top()->right;
          my_stack.pop();
          while(root) {
            my_vector.push_back(root->val);
            if (root->right) my_stack.push(root);
            root = root->left;
          }
        }
        return my_vector;
    }
};
