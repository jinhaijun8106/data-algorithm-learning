#include <iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        int sum = 0;
        while (l1 || l2 || extra) {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra;
            extra = sum / 10;
            p->next = new ListNode (sum%10);
            p = p->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return preHead.next;
    }
};


int main()
{
   ListNode l1PreHead(0), l2PreHead(0);
   ListNode *pl1 = &l1PreHead, *pl2 = &l2PreHead;
   pl1->next = new ListNode (1);
   pl1 = pl1->next;
   pl1->next = new ListNode (2);
   pl1 = pl1->next;
   pl1->next = new ListNode (3);
   pl1 = pl1->next;

   pl2->next = new ListNode (4);
   pl2 = pl2->next;
   pl2->next = new ListNode (5);
   pl2 = pl2->next;
   pl2->next = new ListNode (6);
   pl2 = pl2->next;
   pl2->next = new ListNode (6);
   pl2 = pl2->next;

   Solution solution_a;

   ListNode *p;
   ListNode *result = solution_a.addTwoNumbers(l1PreHead.next,
                                               l2PreHead.next);
   int value = 0;
   int base = 1;
   while (result) {
       value += result->val * base;
       base *= 10;
       p = result->next;
       delete result;
       result = p;
   }
   cout << value <<endl;
}
