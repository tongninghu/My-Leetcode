A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> my_map;
        RandomListNode *copyhead = new RandomListNode(head->label);
        RandomListNode *p = head, *q = copyhead;
        my_map[head] = copyhead;
        while (p && p->next) {
            q->next = new RandomListNode(p->next->label);
            q = q->next;
            p = p->next;
            my_map[p] = q;
        }
        
        p = head;
        q = copyhead;
        
        while (p) {            
            if (p->random) q->random = my_map[p->random];
            q = q->next;
            p = p->next;
        }  
        return copyhead;
    }
};
