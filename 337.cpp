The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.

class Solution {
public:
    void helper(TreeNode* root, unordered_map<TreeNode*, int>& WOR, unordered_map<TreeNode*, int>& WIR) {
        if (!root) return;
        helper(root->left, WOR, WIR);
        helper(root->right, WOR, WIR);
        int i = max(WOR[root->left], WIR[root->left]) + max(WOR[root->right], WIR[root->right]);
        WOR[root] = i;
        WIR[root] = WOR[root->left] + WOR[root->right] + root->val;
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> WOR;
        unordered_map<TreeNode*, int> WIR;
        WOR[NULL] = 0;
        WIR[NULL] = 0;
        helper(root, WOR, WIR);
        return max(WOR[root], WIR[root]);
    }
};
