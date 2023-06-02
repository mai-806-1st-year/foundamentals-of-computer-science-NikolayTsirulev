#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "deque.h"

deq *create_deq(int capacity) {
    if (capacity <= 0)
        return 0;
    deq *d = malloc(sizeof(deq) + capacity * sizeof(T));
    if (d) {
        d->capacity = capacity;
        d->head = d->tail = -1;
    }
    return d;
}

int deque_size(deq *d) {
    if (is_empty(d)) {
        return 0;
    } else if (d->head <= d->tail) {
        return d->tail - d->head + 1;
    } else {
        return d->capacity - d->head + d->tail + 1;
    }
}

deq *push_back(deq *d, T elem) {
    if (deque_size(d)) {
        if (++(d->tail) == d->capacity)
            d->tail = 0;
    } else
        d->tail = d->head = 0;
    d->data[d->tail] = elem;
    return d;
}

deq *push_front(deq *d, T elem) {
    if (deque_size(d)) {
        if(--(d->head) < 0)
            d->head = d->capacity - 1;
    } else
        d->tail = d->head = 0;
    d->data[d->head] = elem;
    return d;
}

T pop_back(deq *d) {
    int index = d->tail;
    if (deque_size(d) == 1)
        d->tail = d->head = -1;
    else
        if (--(d->tail) < 0)
            d->tail = d->capacity - 1;
    return d->data[index];
}

T pop_front(deq *d) {
    int index = d->head;
    if (deque_size(d) == 1)
        d->tail = d->head = -1;
    else
        if (++(d->head) == d->capacity)
            d->head = 0;
    return d->data[index];
}

bool is_empty(deq *d) {
    return d->head == -1;
}

bool is_full(deq *d) {
    return deque_size(d) == d->capacity;
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
            it->index = deque_size(it->d) - 1;
    return it->d->data[index];
}

void delete(deq *d) {
    free(d);
}

deq *merge(deq *d1, deq *d2) {
    deq *d = create_deq(deque_size(d1) + deque_size(d2));
    while (!is_empty(d1) || !is_empty(d2)) {
        if (!is_empty(d1)&&(top_front(d1) <= top_front(d2) || is_empty(d2))) {
            d = push_back(d, top_front(d1));
            pop_front(d1);
        }
        if (!is_empty(d2)&&(top_front(d1) > top_front(d2) || is_empty(d1))) {
            d = push_back(d, top_front(d2));
            pop_front(d2);
        }
    }
    delete(d1);
    delete(d2);
    return d;
}

deq *sort(deq *d) {
    deq *d1 = create_deq(deque_size(d)/2);
    deq *d2 = create_deq(deque_size(d) - deque_size(d)/2);
    while (!is_full(d1)) {
        d1 = push_front(d1, top_back(d));
        pop_back(d);
    }
    while (!is_full(d2)) {
        d2 = push_front(d2, top_back(d));
        pop_back(d);
    }
    if(deque_size(d1) > 1) {
        d1 = sort(d1);
    }
    if(deque_size(d2) > 1) {
        d2 = sort(d2);
    }
    
    return (top_front(d1) <= top_front(d2)) ? merge(d1, d2) : merge(d2, d1);
}
