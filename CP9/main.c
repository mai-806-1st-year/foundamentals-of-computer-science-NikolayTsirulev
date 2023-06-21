#include "table.h"
#include "complex.h"

#include <stdlib.h>

int main() {
    FILE *in = fopen("data.txt","r");
    if (!in) exit(EXIT_FAILURE);
    data_str* table = (data_str*)malloc(MAX_STRING_SIZE* sizeof(data_str));
    int size = table_read(table, in);
    int choose;
    bool flag = true;
    while(flag){
        printf("\n1. Print table\t 2. binary insertion sort\t 3. randomize\t 4. Reverse\t 5. binary search\t 6. exit\n");
        scanf("%d", &choose);
        switch(choose){
            case 1:
            {
                table_print(table, size);
                break;
            }
            case 2:
            {
                bin_ins_sort(table, size);
                table_print(table, size);
                break;
            }
            case 3:
            { 
                table_rand(table, size);
                table_print(table, size);
                break;
            }
            case 4:
            {
                table_reverse(table, size);
                table_print(table, size);
                break;
            }
            case 5:
            {
                key_complex x;
                complex_read(&x);
                binary_search(table, size, x);
                break;
            }
            case 6:
            {
                flag = false;
                break;
            }
        }
    }
    fclose(in);
    free(table);
    return 0;
}
