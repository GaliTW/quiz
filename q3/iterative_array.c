#include <stdlib.h>
#include "q3.h"

typedef struct _Tree_Stack {
    TreeNode **pNodeSet;
    int head;
    int tail;
} Stack;

Stack *create(int size)
{
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->pNodeSet = (TreeNode **) malloc(sizeof(TreeNode *) * (size + 1));
    stack->head = stack->tail = 0;
    return stack;
}

TreeNode *pop(Stack *stack)
{
    if (stack->head == stack->tail)
        return NULL;

    return stack->pNodeSet[--stack->head];
}

void push(Stack *stack, TreeNode *node)
{
    if (node == NULL)
        return ;

    stack->pNodeSet[stack->head++] = node;
}

void flatten(TreeNode *node)
{
    if (node == NULL)
        return ;

    Stack *stack = create(TREE_SIZE);
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

