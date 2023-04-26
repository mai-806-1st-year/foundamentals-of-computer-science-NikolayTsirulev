#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef int T;

typedef struct
{
    int head;
    int tail;
    int capacity;
    int size;
    T data[];
} Deque;

Deque *create_deq(int size);               //создать дек
Deque *push_back(Deque *d, T elem);        //вставить в конец
T pop_back(Deque *d);                      //удалить из конца
Deque *push_front(Deque *d, T elem);       //вставить в начало
T pop_front(Deque *d);                     //удалить из начала
bool is_empty(Deque *d);                   //true, если дек пустой
bool is_full(Deque *d);                    //true, если дек полный
