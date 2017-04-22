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
    void helper(TreeNode* root, vector<int>& my_vector) {
        if (!root) return;
        my_vector.push_back(root->val);
        helper(root->left, my_vector);
        helper(root->right, my_vector);
    }
    void flatten(TreeNode* root) {
        vector<int> my_vector;
        helper(root, my_vector);
        TreeNode *p = root;
        for (int i = 0; i < my_vector.size(); i++) {
            if (i == 0) {
                p->val = my_vector[i];
                p->left = NULL;
            }
            else {
                p->right = new TreeNode (my_vector[i]);
                p = p->right;
            }
        }
    }
};
/*
class Solution {
private:
    TreeNode* head, * p = NULL;
public:
    void helper(TreeNode* root) {
        if (!root) return;
        if(!p) {
            p = new TreeNode(root->val);
            head = p;
        }
        else {
            p->right = new TreeNode(root->val);
            p = p->right;
        }
        helper(root->left);
        helper(root->right);
    }
    void flatten(TreeNode* root) {
        helper(root);
        root = head;
        }
    }
}; */
