#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <stdbool.h>
#include <stdio.h>

#define MAX_STRING_SIZE 100

typedef struct {
    double real;
    double img;
} key_complex;

typedef struct {
    key_complex key;
    char str[MAX_STRING_SIZE];
} data_str;

bool complex_read(key_complex* x);

bool complex_file_read(key_complex* x, FILE* in);

bool complex_is_equal(key_complex x1, key_complex x2);

int fcompare(double a, double b);

bool key_compare(key_complex a, key_complex b);

void complex_print(key_complex x);

#endif
