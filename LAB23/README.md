# Отчёт по лабораторной работе №23 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «13» <ins>апреля</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «13» <ins>апреля</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Динамические структуры данных. Обработка деревьев__

### 2. Цель работы
__Составить программуна языке Си для построения и обработки упорядоченного двоичного дерева, содержащего узлы типа float.__

### 3. Задание (Вариант 21)
__Определить глубину минимальной вершины двоичного дерева.__ 

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
1. Создадим двоичное дерево;
2. Напишем для него функции вывода значений узлов в порядке ЛКП, КЛП, ЛПК обходов (для обхода будем использовать нерекурсивный алгоритм, использующий импровизированный стек на массиве);
3. Напишем функцию удаления дерева, где порядок удаления элементов будет соответствовать ЛПК обходу;
4. Напишем функцию вывода глубины минимальной вершины двоичного дерева.

### 7. Сценарий выполнения работы
##Makefile
[https://github.com/mai-806-1st-year/fundamentals-of-computer-science-NikolayTsirulev/blob/f2066667520561309491d8013404107279357481/LAB23/Makefile#L1C1-L22](https://github.com/mai-806-1st-year/fundamentals-of-computer-science-NikolayTsirulev/blob/998e091066763a9bf1a207f2690f150f456e24f9/LAB23/Makefile#L1C1-L22)

```C
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "tree.h"

int main(void) {
    float n;
    Tree tr;
    treeCreate(&tr);
    treeInsert(&tr, 4);
    treeInsert(&tr, 2);
    treeInsert(&tr, 1);
    treeInsert(&tr, 3);
    treeInsert(&tr, 6.7);
    treeInsert(&tr, 5);
    treeInsert(&tr, 7.1);
    struct TreeNode * node = tr.root;
    int choice;

    do {
        printf(
            "1 - добавить узел\n"
            "2 - удалить узел\n"
            "3 - КЛП обход\n"
            "4 - ЛКП обход\n"
            "5 - ЛПК обход\n"
            "6 - текстовая визуализация дерева\n"
            "7 - вывести глубину минимальной вершины дерева\n"
            "8 - уничтожить дерево\n"
            "0 - выход\n"
        );
        if (scanf("%d", &choice)) {
		switch (choice) {
		    case 1:
		        printf("Введите значение добавляемого узла: \n");
		        if (scanf("%f", &n) == 1) {
		        	treeInsert(&tr, n);
		        }
		        break;
		    case 2:
		        printf("Введите значение удаляемого узла: \n");
		        if (scanf("%f", &n) == 1) {
		        	treeErase(&tr, n);
		        }
		        break;
		    case 3:
		        printf("\n");
		        preorder(node);
		        printf("\n");
		        break;
		    case 4:
		        printf("\n");
		        inorder(node);
		        printf("\n");
		        break;
		    case 5:
		        printf("\n");
		        postorder(node);
		        printf("\n");
		        break;
		    case 6:
		        printf("\n");
		        printTree(node, 0);
		        printf("\n");
		        break;
		    case 7:
		        printf("\n%d\n", minDepth(&tr));
		        break;
		    case 8:
		        treeClear(&tr);
		        break;
		    case 0:
		        printf("До свидания!\n");
		        break;
		    default:
		        printf("Некорректный выбор. Попробуйте еще раз.\n");
		        break;
		}
        }
    } while (choice != 0);
    
}
```
```C
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

bool treeContains(const Tree * const tree, const float value) {
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

int treeErase(Tree * const tree, const float value) {
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
        float * const value = &node->value;
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

int treeInsert(Tree * const tree, const float value) {
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

void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[MAX_SIZE];
    int top = 0;
    stack[top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        printf("%f ", node->value);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

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
        printf("%f ", node->value);
        node = node->right;
    }
}

void postorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack1[MAX_SIZE];
    struct TreeNode* stack2[MAX_SIZE];
    int top1 = 0;
    int top2 = -1;
    stack1[top1] = root;

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
        printf("%f ", node->value);
    }
}

void printTree(struct TreeNode* root, int depth) {
    if (root == NULL)
        return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%f\n", root->value);
    printTree(root->left, depth + 1);
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
```
```C
#ifndef TREE_H
#define TREE_H

#include null

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

#endif null
```


Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/l2325$ ls
Makefile  main.c  tree.c  tree.h
hackerman@WARMACHINE_mini:~/l2325$ cat Makefile
CC=gcc
RM=rm -fr
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
SOURCES=main.c tree.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

debug: CFLAGS+=-Og -g
debug: all

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
        $(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        $(RM) *.o $(EXECUTABLE)
hackerman@WARMACHINE_mini:~/l2325$ cat main.c
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "tree.h"

int main(void) {
    float n;
    Tree tr;
    treeCreate(&tr);
    treeInsert(&tr, 4);
    treeInsert(&tr, 2);
    treeInsert(&tr, 1);
    treeInsert(&tr, 3);
    treeInsert(&tr, 6.7);
    treeInsert(&tr, 5);
    treeInsert(&tr, 7.1);
    struct TreeNode * node = tr.root;
    int choice;

    do {
        printf(
            "1 - добавить узел\n"
            "2 - удалить узел\n"
            "3 - КЛП обход\n"
            "4 - ЛКП обход\n"
            "5 - ЛПК обход\n"
            "6 - текстовая визуализация дерева\n"
            "7 - вывести глубину минимальной вершины дерева\n"
            "8 - уничтожить дерево\n"
            "0 - выход\n"
        );
        if (scanf("%d", &choice)) {
                switch (choice) {
                    case 1:
                        printf("Введите значение добавляемого узла: \n");
                        if (scanf("%f", &n) == 1) {
                                treeInsert(&tr, n);
                        }
                        break;
                    case 2:
                        printf("Введите значение удаляемого узла: \n");
                        if (scanf("%f", &n) == 1) {
                                treeErase(&tr, n);
                        }
                        break;
                    case 3:
                        printf("\n");
                        preorder(node);
                        printf("\n");
                        break;
                    case 4:
                        printf("\n");
                        inorder(node);
                        printf("\n");
                        break;
                    case 5:
                        printf("\n");
                        postorder(node);
                        printf("\n");
                        break;
                    case 6:
                        printf("\n");
                        printTree(node, 0);
                        printf("\n");
                        break;
                    case 7:
                        printf("\n%d\n", minDepth(&tr));
                        break;
                    case 8:
                        treeClear(&tr);
                        break;
                    case 0:
                        printf("До свидания!\n");
                        break;
                    default:
                        printf("Некорректный выбор. Попробуйте еще раз.\n");
                        break;
                }
        }
    } while (choice != 0);

}
hackerman@WARMACHINE_mini:~/l2325$ cat tree.c
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

bool treeContains(const Tree * const tree, const float value) {
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

int treeErase(Tree * const tree, const float value) {
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
        float * const value = &node->value;
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

int treeInsert(Tree * const tree, const float value) {
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

void preorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack[MAX_SIZE];
    int top = 0;
    stack[top] = root;

    while (top >= 0) {
        struct TreeNode* node = stack[top--];
        printf("%f ", node->value);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

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
        printf("%f ", node->value);
        node = node->right;
    }
}

void postorder(struct TreeNode* root) {
    if (root == NULL) return;

    struct TreeNode* stack1[MAX_SIZE];
    struct TreeNode* stack2[MAX_SIZE];
    int top1 = 0;
    int top2 = -1;
    stack1[top1] = root;

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
        printf("%f ", node->value);
    }
}

void printTree(struct TreeNode* root, int depth) {
    if (root == NULL)
        return;
    printTree(root->right, depth + 1);
    for (int i = 0; i < depth; i++)
        printf("    ");
    printf("%f\n", root->value);
    printTree(root->left, depth + 1);
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
hackerman@WARMACHINE_mini:~/l2325$ cat tree.h
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
hackerman@WARMACHINE_mini:~/l2325$ make
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -Og -g -c main.c -o main.o
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -Og -g -c tree.c -o tree.o
tree.c: In function ‘treeErase’:
tree.c:84:1: error: control reaches end of non-void function [-Werror=return-type]
   84 | }
      | ^
compilation terminated due to -Wfatal-errors.
cc1: all warnings being treated as errors
make: *** [Makefile:19: tree.o] Error 1
hackerman@WARMACHINE_mini:~/l2325$ make
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -Og -g -c tree.c -o tree.o
gcc  main.o tree.o  -o main
hackerman@WARMACHINE_mini:~/l2325$ ./main
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
6

        7.100000
    6.700000
        5.000000
4.000000
        3.000000
    2.000000
        1.000000

1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
1
Введите значение добавляемого узла:
2.1
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
6

        7.100000
    6.700000
        5.000000
4.000000
        3.000000
            2.100000
    2.000000
        1.000000

1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
2
Введите значение удаляемого узла:
2.1
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
6

        7.100000
    6.700000
        5.000000
4.000000
        3.000000
    2.000000
        1.000000

1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
3

4.000000 2.000000 1.000000 3.000000 6.700000 5.000000 7.100000
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
4

1.000000 2.000000 3.000000 4.000000 5.000000 6.700000 7.100000
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
5

1.000000 3.000000 2.000000 5.000000 7.100000 6.700000 4.000000
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
7

2
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
8
1 - добавить узел
2 - удалить узел
3 - КЛП обход
4 - ЛКП обход
5 - ЛПК обход
6 - текстовая визуализация дерева
7 - вывести глубину минимальной вершины дерева
8 - уничтожить дерево
0 - выход
0
До свидания!
hackerman@WARMACHINE_mini:~/l2325$
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 13.05.23 | 12:23 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы
контест
https://codeforces.com/contest/1807/submission/198136631
дорешка
https://codeforces.com/contest/1807/submission/201980199
https://codeforces.com/contest/1807/submission/201986109
https://codeforces.com/contest/1807/submission/201991595

### 11. Выводы
Благодаря лабораторной работе были получены навыки работы с bash-скриптами. Также были изучены методы языка Python работы с файлами, суффиксами и командной строкой. Было освоено определение суффикса файла и его размера с помощью интерпретируемых командных языков OC UNIX (Python 3 и Bash).

