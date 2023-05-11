#ifndef _DEQUE_H_
#define _DEQUE_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

#include "types.h"

typedef int T;

typedef struct
{
    int head;
    int tail;
    int capacity;
    int size;
    T data[];
} deq;

deq *create_deq(int size);
deq *push_back(deq *d, T elem);
T pop_back(deq *d);
T top_back(deq *d);
deq *push_front(deq *d, T elem);
T pop_front(deq *d);
T top_front(deq *d);
bool is_empty(deq *d);
bool is_full(deq *d);
void print_deq(deq *d);

#endif //_DEQUE_H_
