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
        
        if (size == 0) {
            return NULL;
        } 
        
        while (lists.size() > 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
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
