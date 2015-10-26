#include <stdlib.h>
#include "q3.h"

TreeNode *_flatten(TreeNode *node)
{
    if (node == NULL)
        return NULL;

    TreeNode *leftTail = _flatten(node->pLeft);
    TreeNode *rightTail = _flatten(node->pRight);

    if (leftTail == NULL) {
        // leftTail == NULL && rightTail == NULL
        if (rightTail == NULL)
            return node;

        // leftTail == NULL && rightTail != NULL
        return rightTail;
    }

    // leftTail != NULL && rightTail != NULL
    if (rightTail != NULL)
        leftTail = leftTail->pRight = node->pRight;

    node->pRight = node->pLeft;
    node->pLeft = NULL;
    return leftTail;

}

void flatten(TreeNode *node)
{
    _flatten(node);
}
