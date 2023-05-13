#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int main(void) {
    Tree tr;
    treeCreate(&tr);
    treeInsert(&tr, 4);
    treeInsert(&tr, 2);
    treeInsert(&tr, 1);
    treeInsert(&tr, 3);
    treeInsert(&tr, 6);
    treeInsert(&tr, 5);
    treeInsert(&tr, 7);
    struct TreeNode * node = tr.root;
    printf("\npostorder: ");
    postorder(node);
    printf("\npreorder: ");
    preorder(node);
    printf("\ninorder: ");
    inorder(node);
    printf("\nprint:\n");
    printTree(node, 0);
    printf("\nDepth of minimal node: %d\n", minDepth(&tr));
    printf("\nprint when add 8:\n");
    printTree(node, 0);
    treeInsert(&tr, 8);
    printf("\nprint without 2:\n");
    treeErase(&tr, 4);
    printTree(node, 0);
    treeClear(&tr);
    
}
