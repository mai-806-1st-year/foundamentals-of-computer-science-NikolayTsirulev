#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>
#include <stddef.h>

#include "types.h"

typedef int T;

typedef struct {
    int first;
    int last;
    int capacity;
    T data[];
} Deque;

Deque* deque_create(const int);

bool deque_is_empty(const Deque*);

bool deque_is_full(const Deque*);

size_t deque_capacity(const Deque*);

size_t deque_length(const Deque*);

Deque* deque_resize(Deque*, int);

int deque_push_front(Deque**, const T);

int deque_push_back(Deque**, const T);

int deque_pop_front(Deque*);

int deque_pop_back(Deque*);

int deque_front(const Deque*, T*);

int deque_back(const Deque*, T*);

void deque_destroy(Deque*);

#endif //_DEQUE_H_
