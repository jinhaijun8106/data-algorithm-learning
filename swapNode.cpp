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
    ListNode* swapPairs(ListNode* head) {
        ListNode newhead(0), *tail, *a, *b;
        
        if (!head || !head->next) {
            return head;
        }
        newhead.next = head;
        tail = &newhead;        
        
        while (tail->next && tail->next->next){
            /* start:
            *  tail = &newhead
            * newhead A->B->C->D
            * after:
            *newhead->B->A->C->D
            * tail =A
            */
            a = tail->next;
            b = a->next;
            a->next = b->next;
            b->next = a;
            tail->next = b;
            tail = a;
        }
        return newhead.next;
    }
};
