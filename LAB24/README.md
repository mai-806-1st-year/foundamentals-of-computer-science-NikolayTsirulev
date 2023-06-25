
# Отчёт по лабораторной работе №24 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «25» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «25» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Деревья арифметических выражений.__

### 2. Цель работы
__Составить программу на Си выполнения заданных преобразований арифметическиз выражений с применением деревьев.__

### 3. Задание (Вариант 21)
__Заменить вычитание на сложениес противопложным числом, те. на сложение и унарный минус: a-b*c->a+(-b*c).__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
Переведем инфиксную запись в обратную польскую нотацию, а из нее построим дерево выражения. Далее напишем функцию согласно заданию.

### 7. Сценарий выполнения работы
```
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

```


Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/mai_labs/lab24$ gcc c24.c
hackerman@WARMACHINE_mini:~/mai_labs/lab24$ valgrind ./a.out
==4555== Memcheck, a memory error detector
==4555== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==4555== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==4555== Command: ./a.out
==4555==
Введите арифметическое выражение в инфиксной записи: E * ((A * B) - (C / D))
Постфиксное выражение: EAB*CD/-*
Дерево выражения:

            D

        /

            C

    -

            B

        *

            A

*

    E

Преобразование a+(-(b*c)):
                D

            /

                C

        -

    +

            B

        *

            A

*

    E
Инфиксная запись: (E*((A*B)+(-(C/D))))
==4555==
==4555== HEAP SUMMARY:
==4555==     in use at exit: 0 bytes in 0 blocks
==4555==   total heap usage: 12 allocs, 12 frees, 2,336 bytes allocated
==4555==
==4555== All heap blocks were freed -- no leaks are possible
==4555==
==4555== For lists of detected and suppressed errors, rerun with: -s
==4555== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
hackerman@WARMACHINE_mini:~/mai_labs/lab24$
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 25.06.23 | 21:55 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы
 Div 2
[1839А](https://codeforces.com/contest/1839/submission/208334151)
### 11. Выводы
Благодаря курсовой работе были получены навыки обработки арифметических выражений. Также были изучены методы построения деревьев выражений.

