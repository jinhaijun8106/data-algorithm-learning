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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *preLoop, *cur, *next;
        ListNode *tmp;
        int total_cnt = 0;
        ListNode newHead(0);
        newHead.next = head;
        
        if (k <= 1 || !head) {
            return newHead.next;
        }
        
        preLoop = &newHead;
        cur = preLoop->next;
        
        tmp = head;
        while(tmp) {
            total_cnt ++;
            tmp = tmp->next;
        }
        
        while (total_cnt - k >= 0) {
            for (int switch_cnt = 0; switch_cnt < k -1 ; switch_cnt ++) {
                next = cur->next;
                cur->next = next->next;
                tmp = preLoop->next;
                preLoop->next = next;
                next->next = tmp;
            }
            preLoop = cur;
            cur = cur->next;
            total_cnt = total_cnt - k;
        }
        
        return newHead.next;
    }
};
