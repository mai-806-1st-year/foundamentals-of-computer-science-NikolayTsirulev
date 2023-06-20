#ifndef _TABLE_H
#define _TABLE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "complex.h"

int table_read(data_str*, FILE*);
void table_print(data_str*, size_t size);
void bin_ins_sort(data_str*, size_t size);
void binary_search(data_str*, size_t size, key_complex);
void table_reverse(data_str*, size_t size);
void table_rand(data_str*, size_t size);

#endif
