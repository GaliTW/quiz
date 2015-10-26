#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <string.h>

#include "q3.h"

TreeNode *createNode(int value)
{
    TreeNode *n = (TreeNode *) malloc(sizeof(TreeNode));
    n->value = value;
    n->pLeft = n->pRight = NULL;
    return n;
}

int find(int set[], int start, int end, int value)
{
    while (start <= end) {
        if(set[start] == value)
            return start;
        else
            ++start;
    }
    return -1;
}

TreeNode *buildTree(int inorder[], int preorder[], int start, int end)
{
    static int preIndex = 0;

    if (start > end)
        return NULL;

    TreeNode *cur = createNode(preorder[preIndex++]);

    if (start == end)
        return cur;

    int inIndex = find(inorder, start, end, cur->value);
    assert(inIndex != -1 && "the input tree format error");

    cur->pLeft = buildTree(inorder, preorder, start, inIndex - 1);
    cur->pRight = buildTree(inorder, preorder, inIndex + 1, end);

    return cur;
}

void printPreorder(TreeNode *node, char str[])
{
    if (node != NULL) {
        sprintf(str, "%s%d,", str, node->value);
        printPreorder(node->pLeft, str);
        printPreorder(node->pRight, str);
    }
}

void printInorder(TreeNode *node, char str[])
{
    if (node != NULL) {
        printInorder(node->pLeft, str);
        sprintf(str, "%s%d,", str, node->value);
        printInorder(node->pRight, str);
    }
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

int main()
{
    struct timespec start, end;
    struct timespec cpu_time;

    char inorderStr[100], preorderStr[100];
    inorderStr[0] = preorderStr[0] = '\0';

#if TREE_SIZE == 6
    int preorder[TREE_SIZE] = {1, 2, 3, 4, 5, 6};
    int inorder[TREE_SIZE] = {3, 2, 4, 1, 5, 6};
#elif TREE_SIZE == 15
    int preorder[TREE_SIZE] = {1, 2, 4, 5, 10, 21, 3, 6, 12, 24, 25, 7, 15, 31, 63};
    int inorder[TREE_SIZE] = {4, 2, 10, 21, 5, 1, 24, 12, 25, 6, 3, 7, 15, 31, 63};
#else
    #error TREE_SIZE must exist
#endif

    TreeNode *root = buildTree(inorder, preorder, 0, TREE_SIZE - 1);

    clock_gettime(CLOCK_REALTIME, &start);
    flatten(root);
    clock_gettime(CLOCK_REALTIME, &end);
    cpu_time = diffTime(start, end);

    printPreorder(root, preorderStr);
    printInorder(root, inorderStr);

    assert(0 == strcmp(preorderStr, inorderStr));
    printf("execution time of flatten() : %ld.%09ld sec\n", (long)cpu_time.tv_sec, cpu_time.tv_nsec);

    return 0;
}
