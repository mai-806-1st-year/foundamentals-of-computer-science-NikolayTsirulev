#ifndef LAB_MATRIX_H
#define LAB_MATRIX_H

#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* next, *prev;
} Node;

typedef struct{
    int cols, rows;
    Node* start, *end;
} Matrix;

Matrix* init();
void free_matrix(Matrix* m);
void push_back(Matrix* m, int element);
bool enter(Matrix* m, char* filename);
void print(Matrix *m);
void print_inner(Matrix *m);
bool skew_symmetric(Matrix *m);
Matrix* transpose(Matrix *m);
Matrix* transpose_by_side_diagonal(Matrix *m);
bool matrices_equal(Matrix *m1, Matrix *m2);
Matrix* negative_matrix(Matrix *m);

#endif //LAB_MATRIX_H
