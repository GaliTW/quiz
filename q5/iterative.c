#include <stdlib.h>
#include "q5.h"

ListNode *detectCycle(ListNode *head)
{
    while (head != NULL) {
        if (head->pNext == (ListNode *)detectCycle)
            return head;

        ListNode *temp = head;
        head = head->pNext;
        temp->pNext = (ListNode *)detectCycle;
    }

    return NULL;
}
