#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"
#include "types.h"

typedef int T;

Deque *create(int capacity)
{
    if (capacity <= 0)
        return 0;
    Deque *d = malloc(sizeof(Deque) + capacity * sizeof(T));
    if (d)
    {
        d->capacity = capacity;
        d->head = d->tail = -1;
        d->size = 0;
    }
    return d;
}

Deque *push_back(Deque *d, T elem)
{
    if (d->size)
    {
        if (++(d->tail) == d->capacity)
            d->tail = 0;
    }
    else
        d->tail = d->head = 0;
    d->data[d->tail] = elem;
    d->size++;
    return d;
}


Deque *push_front(Deque *d, T elem)
{
    if (d->size)
    {
        if(--(d->head) < 0)
            d->head = d->capacity - 1;
    }
    else
        d->tail = d->head = 0;
    d->data[d->head] = elem;
    d->size++;
    return d;
}

T pop_back(Deque *d)
{
    if (d->size == 1)
        d->tail = d->head = -1;
    else
        if (--(d->tail) < 0)
            d->tail = d->capacity - 1;
    d->size--;
    return d->data[d->tail];
}

T pop_front(Deque *d)

{
    int index = d->head;
    if (d->size == 1)
        d->tail = d->head = -1;
    else
        if (++(d->head) == d->capacity)
            d->head = 0;
    d->size--;
    return d->data[index];
}

bool is_empty(Deque *d)
{
    return !d->size;
}


bool is_full(Deque *d)
{
    return d->size == d->capacity;
}

void deque_destroy(Deque* const d) {
    free(d);
}
