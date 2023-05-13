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
