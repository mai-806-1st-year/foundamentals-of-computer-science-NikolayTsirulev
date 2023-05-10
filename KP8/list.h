#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

#include "types.h"

typedef struct ListNode ListNode;

typedef struct {
    ListNode *head, *tail;
    size_t size;
} List;

typedef struct {
    ListNode *node;
}ListIterator;

int listBack(const List *list, int *value);

void listClear(List *list);

void listCreate(List *list);

bool listIsEmpty(const List *list);

ListIterator listIteratorBegin(List *list);

ListIterator listIteratorEnd(List *list);

ListIterator listIteratorInsert(List *list, ListIterator *listIterator, const int value);

ListIterator listIteratorRemove(List *list, ListIterator * const listIterator);

ListIterator *listIteratorNext(ListIterator * const listIterator);

ListIterator *listIteratorPrev(ListIterator *listIterator);

int listIteratorGet(const ListIterator *listIterator);

int listIteratorSet(ListIterator *listIterator, int value);

int listPopBack(List *list);

int listPopFront(List *list);

int listPushBack(List *list, int value);

int listPushFront(List *list, int value);

size_t listSize(const List *list);

void listDestroy(List *list);

bool Equal(const ListIterator* lhs, const ListIterator* rhs);

#endif // LIST_H
