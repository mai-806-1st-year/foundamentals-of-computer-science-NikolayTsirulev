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
    T data[];
} deq;

typedef struct
{
    deq *d;
    int index;
} iterator;

deq *create_deq(int size);
int deque_size(deq *d);
deq *push_back(deq *d, T elem);
T pop_back(deq *d);
T top_back(deq *d);
deq *push_front(deq *d, T elem);
T pop_front(deq *d);
T top_front(deq *d);
bool is_empty(deq *d);
bool is_full(deq *d);
iterator get_iterator(deq *d, bool head);
T next(iterator *it);
T prev(iterator *it);
void delete(deq *d);
deq *merge(deq *d1, deq *d2);
deq *sort(deq *d);


#endif //_DEQUE_H_
