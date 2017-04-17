Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> my_stack;
        vector<int> my_vector;
        while(root) {
            my_stack.push(root);
            root = root->left;
        }
        while(!my_stack.empty()) {
          TreeNode *root = my_stack.top()->right;
          if (!root) {
             my_vector.push_back(my_stack.top()->val);
             my_stack.pop();
          }
          else {
             my_stack.top()->right = NULL;
             while(root) {
                my_stack.push(root);
                root = root->left;
             }
           }
        }
        return my_vector;
    }
};
