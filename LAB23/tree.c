#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_SIZE 100
#include "tree.h"
#include <stdio.h>

void treeClear(Tree * const tree) {
    TreeNode * root = tree->root;
    if (root == NULL) return;

    struct TreeNode* stack[MAX_SIZE];
    int top = -1;
    struct TreeNode* node = root;

    while (node != NULL || top >= 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }

        node = stack[top--];
        free(node);
        node = node->right;
    }
}

bool treeContains(const Tree * const tree, const int value) {
    TreeNode *node = tree->root;
    while (node != NULL) {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return true;
    }
    return false;
}

void treeCreate(Tree * const tree) {
    tree->root = NULL;
    tree->size = 0;
}

int treeErase(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            break;
    }
    if (node == NULL)
        return EINVAL;

    assert(node->value == value);
    if (node->left != NULL && node->right != NULL) {
        int * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL) {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL) {
        assert(node->right == NULL);
        *ptr = node->left;
        node->left->parent = node->parent;
    } else if (node->right != NULL) {
        assert(node->left == NULL);
        *ptr = node->right;
        node->right->parent = node->parent;
    } else
        *ptr = NULL;
    free(node);
    --tree->size;
}

int treeInsert(Tree * const tree, const int value) {
    TreeNode **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL) {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
            return EINVAL;
    }
    *ptr = malloc(sizeof(TreeNode));
    if (*ptr == NULL)
        return errno;
    ++tree->size;
    (*ptr)->parent = node;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = value;
    return 0;
}

bool treeIsEmpty(const Tree * const tree) {
    return tree->size == 0;
}

size_t treeSize(const Tree * const tree) {
    return tree->size;
}

void treeDestroy(Tree * const tree) {
    treeClear(tree);
}

// Функция для Pre-order обхода дерева без рекурсии
void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        printf("%d ", node->value);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

// Функция для In-order обхода дерева без рекурсии
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[MAX_SIZE];
    int top = -1;
    struct TreeNode* node = root;

    while (node != NULL || top >= 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }

        node = stack[top--];
        printf("%d ", node->value);
        node = node->right;
    }
}

// Функция для Post-order обхода дерева без рекурсии
void postorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack1[MAX_SIZE];
    struct TreeNode* stack2[MAX_SIZE];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        struct TreeNode* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }

    while (top2 >= 0) {
        struct TreeNode* node = stack2[top2--];
        printf("%d ", node->value);
    }
}

void printTree(struct TreeNode* root, int depth) {
    if (root == NULL)
        return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", root->value);
    printTree(root->left, depth + 1);
}

int findDepth(struct TreeNode* root, int x) {
    if (root == NULL)
        return -1;
    int dist = -1;
    if ((dist = findDepth(root->left, x)) >= 0)
        return dist + 1;
  
    return dist;
}

int minDepth(const Tree * const tree) {
    struct TreeNode * node = tree->root;
    int depth = 0;
    while(node->left) {
        node = node->left;
        depth++;
    }
    return depth;
}
