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
    struct compare {
        bool operator() (const ListNode* l1, const ListNode* l2) {
            return (l1->val > l2->val);
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i]) q.push(lists[i]);
        
        ListNode* fakeHead = new ListNode(-1);
        ListNode* ptr = fakeHead;
        
        while(!q.empty()) {
            ptr->next = q.top();
            ListNode* temp = q.top()->next;
            q.pop();
            if (temp) q.push(temp);
            ptr = ptr->next;
        }
        return fakeHead->next;
    }
};
