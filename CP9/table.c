#include "table.h"

int table_read(data_str table[], FILE* in) {
    int i = 0;
    while (!feof(in)){
        complex_file_read(&(table[i].key), in);
        fgets(table[i].str, MAX_STRING_SIZE, in);
        ++i;
    }
    return i;
}
void table_print(data_str table[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        complex_print(table[i].key);
        char *newline = strchr(table[i].str, '\n');
        if (newline != NULL) {
            printf("%s", table[i].str);
        } else {
            printf("%s\n", table[i].str);
        }
    }
}

void bin_ins_sort(data_str table[], size_t size) {
    for (size_t i = 1; i < size; ++i) {
        data_str temp = table[i];
        int left = 0;
        int right = i - 1;
        int mid;

        while (left <= right) {
            mid = (left + right) / 2;
            if (key_compare(table[mid].key, temp.key)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; --j) {
            table[j + 1] = table[j];
        }

        table[left] = temp;
    }
}

void binary_search(data_str table[], size_t size, key_complex k) {
    int left = 0, right = size, mid;
    while(left < right){
        mid = left + (right - left) / 2;

        if(key_compare(table[mid].key, k)) right = mid;
        else left = mid + 1;
    }

    if(complex_is_equal(table[--right].key, k)){
        complex_print(k);
        printf("  %s\n", table[right].str);
    }
    else{
        printf("Key not found\n");
    }
}

void table_reverse(data_str table[], size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        data_str temp = table[i];
        table[i] = table[size - i - 1];
        table[size - i - 1] = temp;
    }
}

void table_rand(data_str table[], size_t size) {
    srand(time(NULL));
    for(size_t  i = 0; i < size - 1; ++i) {
        int randIndex = rand() % size;
        data_str temp = table[i];
        table[i] = table[randIndex];
        table[randIndex] = temp;
    }
}
