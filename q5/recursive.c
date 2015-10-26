#include <stdlib.h>
#include "q5.h"

ListNode *detectCycle(ListNode *head)
{
    if (head == NULL)
        return NULL;
    if (head->pNext == (ListNode *)detectCycle)
        return head;

    ListNode *temp = head->pNext;
    head->pNext = (ListNode *)detectCycle;

    return detectCycle(temp);
}
