#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "deq.h"

int main()
{
    deq *d = create_deq(10);
    while (!is_full(d))
    {
        int r = rand() % 10 + 1;
        printf("Добавляем ");
        if (r % 2)
        {
            printf("в хвост: %d\n", r);
            push_back(d, r);
        }
        else
        {
            printf("в голову: %d\n", r);
            push_front(d, r);
        }
    }
    print_deq(d);
    printf("\n");
    printf("Головной элемент: %d\n", top_front(d));
    printf("Хвостовой элемент: %d\n", top_back(d));
    while (!is_empty(d))
    {
        printf("Извлекаем из ");
        if (rand() % 2)
            printf("хвоста: %d\n", pop_back(d));
        else
            printf("головы: %d\n", pop_front(d));
    }        
    free(d);
}
