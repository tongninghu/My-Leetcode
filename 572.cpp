Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2
Return false.

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (isSameTree(p->left, q->left) && isSameTree(p->right, q->right) && p->val == q->val) return true;
            else return false;
        }
        else if (!p && !q) return true;
        else return false;
    }
    
    void Subtree(TreeNode* s, TreeNode* t, bool& flag) {
        if (isSameTree(s, t)) flag = true;
        if (s->left) Subtree(s->left, t, flag);
        if (s->right) Subtree(s->right, t, flag);
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool flag = false;
        Subtree(s, t, flag);
        return flag;
    }
};
