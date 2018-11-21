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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int left = 0;
        int size = lists.size();
        int start, end = size - 1;
        if (size == 0) {
            return NULL;
        } 

        while (end != 0) {
            start = 0;
            while (end > start) {
                lists[start] = merge2Lists(lists[start], lists[end]);
                start++; 
                end --;
            }
        }
        return lists[0];
        
    }
private:
    ListNode* merge2Lists(ListNode *list1, ListNode*list2) {
        ListNode newListNode(0);
        ListNode *curList;
        
        curList = &newListNode;
        while (list1 && list2) {
            if (list1->val < list2->val){
                curList->next = list1;
                list1 = list1->next;
            } else {
                curList->next = list2;
                list2 = list2->next;
            }
            curList = curList->next;
        }
        
        curList->next = list1?list1:list2;
        return newListNode.next;
    }
};
