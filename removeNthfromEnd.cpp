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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /* lists pointed which are tried to point the last 1, last N  from the end */
        ListNode *L1 = head, *Ln = head; 
        ListNode *toBeDelete = NULL, *ret = NULL;
        int cnt = 1;
        L1 = head;
        if (head == NULL || n <= 0) {
            return head;
        }
        
        while(cnt < n) {
            if (L1->next == NULL) {
                return head;
            }
            L1 = L1->next;
            cnt ++;
        }
        
        if (L1->next == NULL) {
            toBeDelete = head;
            ret = head->next;
            delete toBeDelete;
            return ret;
        } 
        
        while (L1->next) {
            if (L1->next->next) {
                L1 = L1->next;
                Ln = Ln->next;
            } else {
                toBeDelete = Ln->next;                
                Ln->next = Ln->next->next;
                delete toBeDelete;
                break;
            }
        }
        
        return head;
        
    }   
        
};
