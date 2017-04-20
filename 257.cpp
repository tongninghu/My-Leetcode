Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]

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
    void rootToleaf (TreeNode* root, string pass, vector<string>& my_vector) {
        pass += to_string (root->val);
        if (!root->left && !root->right) my_vector.push_back(pass);
        pass += "->";
        if (root->left) rootToleaf (root->left, pass, my_vector);
        if (root->right) rootToleaf (root->right, pass, my_vector);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> my_vector;
        if (!root) return my_vector;
        rootToleaf (root, "", my_vector);
        return my_vector;
    }
};
