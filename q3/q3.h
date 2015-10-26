#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define TREE_SIZE 15

typedef struct _Tree_Node {
    int value;
    struct _Tree_Node *pLeft;
    struct _Tree_Node *pRight;
} TreeNode;

void flatten(TreeNode *node);

#endif
