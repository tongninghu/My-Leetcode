Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Example 1:
Input: 
	Tree 1                     Tree 2                  
          1                         2                             
         / \                       / \                            
        3   2                     1   3                        
       /                           \   \                      
      5                             4   7                  
Output: 
Merged tree:
	     3
	    / \
	   4   5
	  / \   \ 
	 5   4   7
   
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
    TreeNode* merge(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = new TreeNode(-1);
        if (!t1 && t2) root = t2;
        else if (t1 && !t2) root = t1;
        else if (t1 && t2) {
            root->val = t1->val + t2->val;
            root->left = merge(t1->left, t2->left);
            root->right = merge(t1->right, t2->right);
        }
        else root = NULL;
        return root;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        return merge(t1, t2);
    }
};
