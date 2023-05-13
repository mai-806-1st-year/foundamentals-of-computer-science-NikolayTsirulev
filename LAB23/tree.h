#ifndef TREE_H
#define TREE_H

#include <stddef.h>

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

struct TreeNode {
    TreeNode *parent, *left, *right;
    float value;
};

void treeClear(Tree *tree);

bool treeContains(const Tree *tree, float value);

void treeCreate(Tree *tree);

int treeErase(Tree * const tree, float value);

int treeInsert(Tree * const tree, float value);

size_t treeSize(const Tree *tree);

void treeDestroy(Tree *tree);

void preorder(struct TreeNode* root);

void inorder(struct TreeNode* root);

void postorder(struct TreeNode* root);

void printTree(struct TreeNode* root, int depth);

int minDepth(const Tree * const tree);

#endif // TREE_H
