#include <stdlib.h>
#include "q3.h"

typedef struct _Tree_List_Node {
    TreeNode *node;
    struct _Tree_List_Node *pNext;
} TreeList;

typedef struct _Tree_Stack {
    TreeList *pHead;
    TreeList *pTail;
} Stack;

Stack *create()
{
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->pHead = stack->pTail = NULL;
    return stack;
}

TreeNode *pop(Stack *stack)
{
    if (stack->pHead == NULL)
        return NULL;

    TreeNode *node = stack->pHead->node;
    if (stack->pHead == stack->pTail)
        stack->pHead = stack->pTail = NULL;
    else
        stack->pHead = stack->pHead->pNext;

    return node;
}

void push(Stack *stack, TreeNode *node)
{
    if (node == NULL)
        return ;

    TreeList *temp = (TreeList *) malloc(sizeof(TreeList));
    temp->node = node;
    temp->pNext = NULL;

    if (stack->pHead == stack->pTail && stack->pHead == NULL)
        stack->pHead = stack->pTail = temp;
    else {
        temp->pNext = stack->pHead;
        stack->pHead = temp;
    }
}

void flatten(TreeNode *node)
{
    if (node == NULL)
        return ;

    Stack *stack = create();
    push(stack, node);
    for (TreeNode *walk = pop(stack); walk != NULL; walk = pop(stack)) {
        push(stack, walk->pRight);
        push(stack, walk->pLeft);

        if (walk->pLeft != NULL) {
            walk->pRight = walk->pLeft;
            walk->pLeft = NULL;
        } else {
            walk->pRight = pop(stack);
            push(stack, walk->pRight);
        }

    }
}

