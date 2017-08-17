You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]

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
    void helper(TreeNode* root, int l, vector<int>& res) {
        if (!root) return;
        if (l >= res.size()) res.push_back(root->val);
        else if (root->val > res[l]) res[l] = root->val;
        
        helper(root->left, l + 1, res);
        helper(root->right, l + 1, res);
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        helper(root, 0, res);
        return res;
    }
};
