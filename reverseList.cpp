#include<iostream>
#include<stdio.h>
struct listNode {
  int val;
  listNode *next;
  listNode(int v) : val(v), next(NULL) {}
};

class Solution1 {
public:
listNode *reverseList(listNode *root) {
    if (!root || !root->next) {
        return root;
    } 
    listNode *right = root->next;
    listNode *reversed = reverseList(right);
    right->next = root;
    root->next = NULL;
    return reversed;
}

};

class Solution {
public:
listNode *reverseList(listNode *root) {
    if (!root || !root->next) {
        return root;
    }
    return reverseListHelper(root, root->next);
}
private:
listNode *reverseListHelper(listNode *node, listNode *right) {
    if (!right->next) {
        right->next = node;
        return right;
    }
    listNode *reversed = reverseListHelper(right, right->next);
    /* node, revered,right */
    right->next = node;
    node->next = NULL;
    return reversed;
}
};

int main() {
    listNode a(-1), b(0), c(1), d(2), e(3), f(4);
    Solution1 so;
    a.next = &b; 
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = NULL;
    listNode *cur; 
    cur = so.reverseList(&a);
    int i = 0;
    while (cur) {
   // cout >> "i:" >> i++ >> ":">>cur->val;
    printf("i:%d, v:%d %d\n", i, cur->val, cur->next);
    cur = cur->next;
    }
    return 0;
}
