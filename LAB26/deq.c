#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "deq.h"

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

void print_deq(deq *d) {
    for (int i=0; i<(d->size);i++) {
        printf("%d ", d->data[i-1]);
    }
}
