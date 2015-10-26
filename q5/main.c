#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "q5.h"

ListNode *createNode()
{
    ListNode *node = (ListNode *) malloc(sizeof(ListNode));
    node->pNext = NULL;
    return node;
}

static struct timespec diffTime(struct timespec t1, struct timespec t2)
{
    struct timespec diff;
    if (t2.tv_nsec-t1.tv_nsec < 0) {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec - 1;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
    } else {
        diff.tv_sec  = t2.tv_sec - t1.tv_sec;
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
    }
    return diff;
}

static struct timespec sumTime(struct timespec t1, struct timespec t2)
{
    struct timespec sum;
    sum.tv_sec  = t1.tv_sec + t2.tv_sec;
    sum.tv_nsec = t1.tv_nsec + t2.tv_nsec;
    return sum;
}

int main()
{
    struct timespec start, end;
    struct timespec cpu_time, cpu_time2, sum_time;

    ListNode *pHead, *pTail, *pCycleHead = NULL;

    pTail = pHead = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pCycleHead = pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail->pNext = pCycleHead;

    assert(pCycleHead == detectCycle(pHead));
    clock_gettime(CLOCK_REALTIME, &start);
    detectCycle(pHead);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diffTime(start, end);

    pTail = pHead = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();

    assert(NULL == detectCycle(pHead));
    assert(NULL == detectCycle(NULL));
    clock_gettime(CLOCK_REALTIME, &start);
    detectCycle(pHead);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diffTime(start, end);
    sum_time = sumTime(cpu_time, cpu_time2);

    pTail = pHead = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pCycleHead = pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail = pTail->pNext = createNode();
    pTail->pNext = pCycleHead;

    assert(pCycleHead == detectCycle(pHead));
    clock_gettime(CLOCK_REALTIME, &start);
    detectCycle(pHead);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time2 = diffTime(start, end);
    sum_time = sumTime(sum_time, cpu_time2);

    printf("execution time of flatten() : %ld.%09ld sec\n", (long)sum_time.tv_sec, sum_time.tv_nsec);

    return 0;
}
