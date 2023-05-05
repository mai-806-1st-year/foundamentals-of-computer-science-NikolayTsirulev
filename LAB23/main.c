#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Структура для узла дерева
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Функция для Pre-order обхода дерева без рекурсии
void preorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

// Функция для In-order обхода дерева без рекурсии
void inorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack[MAX_SIZE];
    int top = -1;
    struct node* node = root;

    while (node != NULL || top >= 0) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;
        }

        node = stack[top--];
        printf("%d ", node->data);
        node = node->right;
    }
}

// Функция для Post-order обхода дерева без рекурсии
void postorder(struct node* root) {
    if (root == NULL) return;

    struct node* stack1[MAX_SIZE];
    struct node* stack2[MAX_SIZE];
    int top1 = -1;
    int top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        struct node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left != NULL) {
            stack1[++top1] = node->left;
        }
        if (node->right != NULL) {
            stack1[++top1] = node->right;
        }
    }

    while (top2 >= 0) {
        struct node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

// Функция для создания нового узла
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Функция для вставки нового узла в дерево
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    } else {
        if (data <= node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
}

// Функция для поиска узла в дереве
struct node* search(struct node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    } else if (data <= node->data) {
        return search(node->left, data);
    } else {
        return search(node->right, data);
    }
}

// Функция для удаления узла из дерева
struct node* delete(struct node* root, int data) {
    if (root == NULL) {
        return root;
    }

    struct node* temp = root;
    struct node* parent = NULL;
    while (temp != NULL && temp->data != data) {
        parent = temp;
        if (data < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }

    if (temp == NULL) {
        return root;
    }

    struct node* child = NULL;
    if (temp->left == NULL && temp->right == NULL) {
        child = NULL;
    } else if (temp->left != NULL && temp->right == NULL) {
        child = temp->left;
    } else if (temp->left == NULL && temp->right != NULL) {
        child = temp->right;
    } else {
        struct node* succ_parent = temp;
        struct node* succ = temp->right;
        while (succ->left != NULL) {
            succ_parent = succ;
            succ = succ->left;
        }
        if (succ_parent != temp) {
            succ_parent->left = succ->right;
            succ->right = temp->right;
       }
        succ->left = temp->left;
        child = succ;
    }

    if (parent == NULL) {
        root = child;
    } else if (parent->left == temp) {
        parent->left = child;
    } else {
        parent->right = child;
    }
    free(temp);
    return root;
}


// Функция для обхода дерева в ширину без дополнительной памяти
void levelorder(struct node* root) {
    if (root == NULL) return;

    struct node* queue[MAX_SIZE];
    int front = 0;
    int rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct node* node = queue[front++];
        printf("%d ", node->data);

        if (node->left != NULL) {
            queue[rear++] = node->left;
        }
        if (node->right != NULL) {
            queue[rear++] = node->right;
        }
    }
}

void printTree(struct node* root, int depth) {
    if (root == NULL)
        return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%d\n", root->data);
    printTree(root->left, depth + 1);
}

int findMinDepth(struct node* root, int depth, int minVal) {
    if (root == NULL) {
        return depth;
    }
    if (root->data < minVal) {
        minVal = root->data;
    }
    int left = findMinDepth(root->left, depth + 1, minVal);
    int right = findMinDepth(root->right, depth + 1, minVal);
    if (left == depth + 1 || right == depth + 1) {
        return depth + 1;
    } else {
        return minVal == root->data ? depth : depth + 1;
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 41);
    root = insert(root, 21);
    root = insert(root, 11);
    root = insert(root, 31);
    root = insert(root, 61);
    root = insert(root, 51);
    root = insert(root, 71);
    printf("Inorder обход: ");
    inorder(root);
    printf("\n");
    printf("Preorder обход: ");
    preorder(root);
    printf("\n");
    printf("Postorder обход: ");
    postorder(root);
    printf("\n");
    printf("Обход в ширину: ");
    levelorder(root);
    printf("\n");
    int minDepth = findMinDepth(root, 0, root->data);
    printf("Глубина минимальной вершины: %d\n", minDepth);
    printf("дерево: \n");
    printTree(root, 0);
    root = delete(root, 4);
    printf("Дерево после удаления узла со значением 4: ");
    printTree(root, 0);
    printf("\n");
    return 0;
}
