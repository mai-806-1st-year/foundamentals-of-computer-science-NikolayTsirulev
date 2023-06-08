#include <stdio.h>
#include "list.h"

int main(void) {
    List l;
    listCreate(&l);
    listPushFront(&l, 1);
    listPushFront(&l, 2);
    listPushFront(&l, 3);
    listPushBack(&l, 4);
    listPushBack(&l, 5);
    listPushBack(&l, 6);
    listPushBack(&l, 7);
    listPushBack(&l, 8);
    listPushBack(&l, 96);
    listPushBack(&l, 9);
    listPushBack(&l, 10);
    printf("size of list = %d\n", (int)listSize(&l));
    listPrint(&l);
    ListIterator i = listIteratorBegin(&l);
    listIteratorNext(&i);
    printf("remove elem with data = %d\n", listIteratorGet(&i));
    i = listIteratorRemove(&l, &i);
    listPrint(&l);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    listIteratorNext(&i);
    printf("remove elem with data = %d\n", listIteratorGet(&i));
    i = listIteratorRemove(&l, &i);
    listPrint(&l);
    i = listIteratorEnd(&l);
    printf("remove tail =  %d\n", listIteratorGet(&i));
    i = listIteratorRemove(&l, &i);
    listPrint(&l);
    printf("Insert 99,98,97\n");
    i = listIteratorBegin(&l);
    listIteratorNext(&i);
    listIteratorInsert(&l, &i, 97);
    listPrint(&l);
    listIteratorNext(&i);
    listIteratorInsert(&l, &i, 98);
    listPrint(&l);
    listIteratorNext(&i);
    listIteratorInsert(&l, &i, 99);
    listPrint(&l);
    listRemoveFromRange(&l, 80, 100);
    listPrint(&l);
}
