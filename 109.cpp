Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);
        ListNode* fp = head, * sp = head, * prev = NULL;
        while (fp && fp->next) {
            if (!prev) prev = head;
            else prev = prev->next;
            fp = fp->next->next;
            sp = sp->next;
        }
        prev->next = NULL;
        
        TreeNode* root = new TreeNode(sp->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(sp->next);
        return root;
    }
};
