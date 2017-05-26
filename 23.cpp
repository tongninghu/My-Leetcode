Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *fakeHead = new ListNode(-1);
        ListNode *ptr = fakeHead;
        while(l1 && l2) {
            if (l1->val > l2->val) {
                ptr->next = l2;
                l2 = l2->next;
                ptr = ptr->next;
            }
            else {
                ptr->next = l1;
                l1 = l1->next;
                ptr = ptr->next;
            }
        } 
        if(l1) ptr->next = l1;
        else ptr->next = l2;
        return fakeHead->next;    
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp = NULL;
        for (int i = 0; i < lists.size(); i++) {
            temp = mergeTwoLists(temp, lists[i]);
        }
        return temp;
    }
};
