#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "deque.h"

deq *create_deq(int capacity) {
    if (capacity <= 0)
        return 0;
    deq *d = malloc(sizeof(deq) + capacity * sizeof(T));
    if (d) {
        d->capacity = capacity;
        d->head = d->tail = -1;
        d->size = 0;
    }
    return d;
}

deq *push_back(deq *d, T elem) {
    if (d->size) {
        if (++(d->tail) == d->capacity)
            d->tail = 0;
    } else
        d->tail = d->head = 0;
    d->data[d->tail] = elem;
    d->size++;
    return d;
}

deq *push_front(deq *d, T elem) {
    if (d->size) {
        if(--(d->head) < 0)
            d->head = d->capacity - 1;
    } else
        d->tail = d->head = 0;
    d->data[d->head] = elem;
    d->size++;
    return d;
}

T pop_back(deq *d) {
    int index = d->tail;
    if (d->size == 1)
        d->tail = d->head = -1;
    else
        if (--(d->tail) < 0)
            d->tail = d->capacity - 1;
    d->size--;
    return d->data[index];
}

T pop_front(deq *d) {
    int index = d->head;
    if (d->size == 1)
        d->tail = d->head = -1;
    else
        if (++(d->head) == d->capacity)
            d->head = 0;
    d->size--;
    return d->data[index];
}

bool is_empty(deq *d) {
    return !d->size;
}

bool is_full(deq *d) {
    return d->size == d->capacity;
}

T top_back(deq *d) {
    return d->data[d->tail];
}

T top_front(deq *d) {
    return d->data[d->head];
}

iterator get_iterator(deq *d, bool head) {
    iterator it;
    it.d = d;
    it.index = head ? d->head : d->tail;
    return it;
}

T next(iterator *it) {
    int index = it->index;
    if (index == it->d->tail)
        it->index = -1;
    else
        if  (++(it->index) == it->d->capacity)
            it->index = 0;
    return it->d->data[index];
}

T prev(iterator *it) {
    int index = it->index;
    if (index == it->d->head)
        it->index = -1;
    else
        if  (--(it->index) < 0)
            it->index = it->d->size - 1;
    return it->d->data[index];
}

bool delete(deq *d) {
    free(d);
}

deq *merge(deq *d1, deq *d2) {
    deq *d = create_deq(d1->size + d2->size);
    while (!is_empty(d1)) {
        d = push_back(d, top_back(d1));
        pop_back(d1);
    }
    while (!is_empty(d1)) {
        d = push_back(d, top_back(d2));
        pop_back(d2);
    }
    return d;
}

deq *sort(deq *d) {
    //printf("111");
    deq *d1 = create_deq(d->size/2);
    deq *d2 = create_deq(d->size - d->size/2);
    while (!is_full(d1)) {
        d1 = push_back(d1, top_back(d));
        //printf("%d  ", top_back(d1));
        pop_back(d);
    }
    while (!is_full(d2)) {
        d2 = push_back(d2, top_back(d));
        //printf("%d  ", top_back(d2));
        pop_back(d);
    }
    if(d1->size>1) {
        sort(d1);
    }
    if(d2->size>1) {
        sort(d2);
    }
    return (top_front(d1) < top_front(d2)) ? merge(d1, d2) : merge(d2, d1);
}
