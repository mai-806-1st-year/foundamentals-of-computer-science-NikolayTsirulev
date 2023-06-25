#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

int getPriority(char operator) {
    if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '+' || operator == '-') {
        return 1;
    }
    return 0;
}

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return 1;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    int infixLength = strlen(infix);
    int postfixIndex = 0;
    char stack[100];
    int top = -1;

    for (int i = 0; i < infixLength; i++) {
        if (infix[i] == ' ') {
            continue;
        } else if (!isOperator(infix[i]) && infix[i] != '(' && infix[i] != ')') {
            postfix[postfixIndex++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = '(';
        } else if (infix[i] == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[postfixIndex++] = stack[top--];
            }
            if (top >= 0 && stack[top] == '(') {
                top--;
            }
        } else {
            while (top >= 0 && getPriority(stack[top]) >= getPriority(infix[i])) {
                postfix[postfixIndex++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while (top >= 0) {
        postfix[postfixIndex++] = stack[top--];
    }

    postfix[postfixIndex] = '\0';
}

struct Node* buildExpressionTree(char* postfix) {
    struct Node* stack[100];
    int top = -1;
    for (int i = 0; postfix[i]; i++) {
        if (isOperator(postfix[i])) {
            struct Node* rightNode = stack[top--];
            struct Node* leftNode = stack[top--];
            struct Node* operatorNode = createNode(postfix[i]);
            operatorNode->left = leftNode;
            operatorNode->right = rightNode;
            stack[++top] = operatorNode;
        } else {
            struct Node* newNode = createNode(postfix[i]);
            stack[++top] = newNode;
        }
    }
    return stack[top];
}

void replaceSubtraction(struct Node* root) {
    if (root != NULL) {
        replaceSubtraction(root->left);
        replaceSubtraction(root->right);
        if (root->data == '-') {
            struct Node* newNode = createNode('+');
            newNode->left = root->left;
            struct Node* negationNode = createNode('-');
            negationNode->left = NULL;
            negationNode->right = root->right;
            newNode->right = negationNode;
            *root = *newNode;
        }
    }
}

void visualizeExpressionTree(struct Node* root, int space) {
    if (root == NULL) {
        return;
    }
    space += 4;
    visualizeExpressionTree(root->right, space);
    printf("\n");
    for (int i = 4; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);
    visualizeExpressionTree(root->left, space);
}

void treeToInfix(struct Node* root, char* infix) {
    if (root == NULL) {
        return;
    }
    if (isOperator(root->data)) {
        strcat(infix, "(");
        treeToInfix(root->left, infix);
        strncat(infix, &root->data, 1);
        treeToInfix(root->right, infix);
        strcat(infix, ")");
    } else {
        strncat(infix, &root->data, 1);
    }
}

void freeExpressionTree(struct Node* root) {
    if (root != NULL) {
        freeExpressionTree(root->left);
        freeExpressionTree(root->right);
        free(root);
    }
}

int main() {
    char infix[100];
    char postfix[100];
    printf("Введите арифметическое выражение в инфиксной записи: ");
    fgets(infix, sizeof(infix), stdin);
    infixToPostfix(infix, postfix);
    printf("Постфиксное выражение: %s\n", postfix);

    struct Node* expressionTree = buildExpressionTree(postfix);
    printf("Дерево выражения:\n");
    visualizeExpressionTree(expressionTree, 0);
    printf("\nПреобразование a+(-(b*c)): ");
    replaceSubtraction(expressionTree);
    visualizeExpressionTree(expressionTree, 0);
    char infix_new[100];
    infix_new[0] = '\0';

    treeToInfix(expressionTree, infix_new);
    printf("Инфиксная запись: %s\n", infix_new);

    freeExpressionTree(expressionTree);
    return 0;
}
