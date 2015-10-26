#ifndef _Q5_H_
#define _Q5_H_

typedef struct _List_Node {
    struct _List_Node *pNext;
} ListNode;

ListNode *createNode();
ListNode *detectCycle(ListNode *head);

#endif
