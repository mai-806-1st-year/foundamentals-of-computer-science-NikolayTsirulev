#include <stdio.h>
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include "types.h"
#include "list.h"

struct ListNode {
    ListNode *next, *prev;
    int data;
};

struct ListIterator {
    ListNode *node;
};

bool Equal(const ListIterator* lhs, const ListIterator* rhs) {
    return lhs->node == rhs->node;
}


int listTopBack(const List * const list) {
    if (list->size == 0)
        return EINVAL;
    return list->tail->data;;
}

int listTopFront(const List * const list) {
    if (list->size == 0)
        return EINVAL;
    return list->head->data;;
}

void listClear(List * const list) {
    for (ListNode *node = list->head; node != NULL; node = node->next) {
        free(node);
    }
    *list = (List) { .head = NULL, .tail = NULL, .size = 0 };
}

void listCreate(List * const list) {
    *list = (List) { .head = NULL, .tail = NULL, .size = 0 };
}

void listDestroy(List * const list) {
    listClear(list);
}

ListIterator listIteratorBegin(List *list) {
    ListIterator res = { .node = list->head };
    return res;
}

ListIterator listIteratorEnd(List *list) {
    ListIterator res = { .node = list->tail };
    return res;
}

ListIterator listIteratorInsert(List *list, ListIterator *listIterator, const int value) {
    ListIterator res = { malloc(sizeof(List)) };
    if (!res.node)
        return listIteratorBegin(list);
    res.node->data = value;
    res.node->next = listIterator->node;
    res.node->prev = listIterator->node->prev;
    res.node->prev->next = res.node;
    listIterator->node->prev = res.node;
    list->size++;
    return res;
    // вставить узел перед listIterator->node
    // т.е. узел будет между listIterator->node->prev и listIterator->node
}

ListIterator listIteratorRemove(List *list, ListIterator *listIterator) {
    ListIterator res = listIteratorEnd(list);
    if (Equal(listIterator, &res)) {
        listPopBack(list);
        res = listIteratorEnd(list);
        listIterator->node = 0;
        return res;
    }
    res = listIteratorBegin(list);
    if (Equal(listIterator, &res)) {
        listPopFront(list);
        res = listIteratorBegin(list);
        listIterator->node = 0;
        return res;
    }
    if (listIterator->node->prev) {
        res.node = listIterator->node->prev;
        res.node->prev = listIterator->node->prev->prev;
        res.node->next = listIterator->node->next;
        res.node->next->prev = res.node;
        list->size--;
        free(listIterator->node);
        listIterator->node = 0;
    } else {
        free(listIterator->node);
        listIterator->node = 0;
    }
}

ListIterator *listIteratorNext(ListIterator * const listIterator) {
	listIterator->node = listIterator->node->next;
    return listIterator;
}

ListIterator *listIteratorPrev(ListIterator * const listIterator) {
	listIterator->node = listIterator->node->prev;
    return listIterator;
}


int listIteratorGet(const ListIterator *listIterator) {
    // посмотреть
    return listIterator->node->data;
}

int listIteratorSet(ListIterator *listIterator, int value) {
    // поставить
    listIterator->node->data = value;
    return 0;
}

bool listIsEmpty(const List * const list) {
    return list->size == 0;
}

int listPushBack(List * const list, const int value) {
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL)
        return errno;
    *node = (ListNode) { .prev = list->tail, .next = NULL, .data = value };
    if (list->size == 0)
        list->head = list->tail = node;
    else
        list->tail = list->tail->next = node;
    ++list->size;
    return 0;
}

int listPushFront(List * const list, const int value) {
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL)
        return errno;
    *node = (ListNode) { .prev = NULL, .next = list->head, .data = value };
    if (list->size == 0)
        list->head = list->tail = node;
    else
        list->head = list->head->prev = node;
    ++list->size;
    return 0;
}

int listPopBack(List * const list) {
    if (list->size == 0)
        return EINVAL;
    ListNode * const node = list->tail;
    list->tail = list->tail->prev;
    free(node);
    if (list->tail == NULL)
        list->head = NULL;
    else
        list->tail->next = NULL;
    --list->size;
    return 0;
}

int listPopFront(List * const list) {
    if (list->size == 0)
        return EINVAL;
    ListNode * const node = list->head;
    list->head = list->head->next;
    free(node);
    if (list->head == NULL)
        list->tail = NULL;
    else
        list->head->prev = NULL;
    --list->size;
    return 0;
}

size_t listSize(const List * const list) {
    return list->size;
}

void listPrint(List *list) {
    for (ListIterator i = listIteratorBegin(list); i.node; listIteratorNext(&i)) {
        printf("%d ",listIteratorGet(&i));
    }
    printf ("\n");
}

void listRemoveFromRange(List *list, int a, int b) {
    ListIterator i = listIteratorBegin(list);
    while (i.node) {
        if (listIteratorGet(&i) < b && listIteratorGet(&i) > a) {
            i = listIteratorRemove(list, &i);
        } else
            listIteratorNext(&i);
    }
}
