Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
    int LeftDepth (TreeNode* root, int depth) {
            if (root->left) return LeftDepth (root->left, depth + 1);
            else return depth;
        }      
    int RightDepth (TreeNode* root, int depth) {
            if (root->right) return RightDepth (root->right, depth + 1);
            else return depth;
        }          
    int countNodes(TreeNode* root) {
        if (!root) return 0;        
        int LeftDep = LeftDepth (root, 1);
        int RightDep = RightDepth (root, 1);    
        if (LeftDep == RightDep) return (1 << LeftDep) - 1;
        else return countNodes(root->left) + countNodes(root->right) + 1;       
    }
};
