#ifndef _TABLE_H
#define _TABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "complex.h"

int table_read(data_str table[], FILE* in);
void table_print(data_str table[], size_t size);
void bin_ins_sort(data_str table[], size_t size);
void binary_search(data_str table[], size_t size, key_complex k);
void table_reverse(data_str table[], size_t size);
void table_rand(data_str table[], size_t size);

#endif
