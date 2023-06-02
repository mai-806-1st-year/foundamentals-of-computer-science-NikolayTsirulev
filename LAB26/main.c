#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "deque.h"

void test1()
{
    srand(time(NULL));
    deq *d = create_deq(10);
    while (!is_full(d))
    {
        T el = rand() % 10;
        if (el % 2) {
            printf("push front: %d\n", el);
            push_front(d, el);
        } else {
            printf("push back: %d\n", el);
            push_back(d, el);
    iterator it = get_iterator(d, true);
    printf("print deque from head to tail:\n");
    while (it.index != -1) {
        printf("%d ", next(&it));
    }
    it = get_iterator(d, false);
    printf("\nprint deque from tail to head:\n");
    while (it.index != -1) {
        printf("%d ", prev(&it));
    }
    printf("\n");
    d = sort(d);
    it = get_iterator(d, true);
    printf("print deque after merge sort:\n");
    while (it.index != -1) {
        printf("%d ", next(&it));
    }
    printf("\n");
    printf("head: %d\n", top_front(d));
    printf("tail: %d\n", top_back(d));
    
    delete(d);
}

int main(void)
{
    test1();
}
