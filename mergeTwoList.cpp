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
        ListNode new_head(0);
        ListNode *new_p = &new_head;
        
        while (l1 || l2) {
            if (!l1) {
                new_p->next = l2;
                break;
            } else if (!l2){
                new_p->next = l1;
                break;
            }
            
            if (l1->val <= l2->val) {
                new_p->next = l1;
                l1 = l1->next;
            } else {
                new_p->next = l2;
                l2 = l2->next;
            }
            
            new_p = new_p->next;
        }
        return new_head.next;
    }
};
