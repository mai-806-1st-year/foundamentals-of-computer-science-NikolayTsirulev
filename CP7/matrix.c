#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>

Matrix* init() {
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = m->cols = 0;
    m->start = NULL;
    m->end = NULL;
    return m;
}

void free_matrix(Matrix* m) {
    Node* current = m->start;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(m);
}

void push_back(Matrix* m, int element) {
    if(m->end == NULL) {
        m->start = m->end = (Node*)malloc(sizeof(Node));
        m->start->data = element;
        m->start->next = m->start->prev = NULL;
        return;
    }
    Node* elem = m->end;
    elem->next = (Node*)malloc(sizeof(Node));
    elem->next->data = element;
    elem->next->next = NULL;
    m->end = elem->next;
    m->end->prev = elem;
}

bool enter(Matrix *m, char *filename) {
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        printf("File has not opened\n");
        return 0;
    }
    int cols, rows;
    fscanf(file, "%d %d", &cols, &rows);
    m->cols = cols;
    m->rows = rows;
    for (int i = 1; i <= rows; i++) {
        push_back(m, 0);
        push_back(m, i);
        for (int j = 1; j <= cols; j++) {
            int cur = 0;
            fscanf(file, "%d", &cur);
            if (cur != 0) {
                push_back(m, j);
                push_back(m, cur);
            }
        }

    }
    push_back(m, 0);
    push_back(m, 0);
    fclose(file);
    return 0;
}

Node* next(Node* node) {
    return node->next;
}

Node* prev(Node* node) {
    return node->prev;
}


void insert_xy(Matrix *m, int x, int y, int raw_index, int raw_data){
    Node* index = (Node*)malloc(sizeof(Node)),*data = (Node*)malloc(sizeof(Node));
    index->data = raw_index;
    data->data = raw_data;
    index->next = data;
    data->prev = index;
    index->prev = data->next = NULL;

    Node* cur_index = m->start;
    Node* cur_data = next(cur_index);
    int zero_count = 0;
    while(zero_count != y){
        if(cur_index->data == 0) {
            zero_count++;
        }
        cur_index = next(cur_data);
        cur_data = next(cur_index);
    }
    int col = cur_index->data;
    while (col < x && col > 0){
        cur_index = next(cur_data);
        cur_data = next(cur_index);
        col = cur_index->data;
    }
    Node* prev_cur_data = prev(cur_index);

    prev_cur_data->next = index;
    index->prev = prev_cur_data;

    data->next = cur_index;
    cur_index->prev = data;
}

void print_row_zeros(int n) {
    for (int i = 0; i < n; ++i) {
        printf("0 ");
    }
}

void print(Matrix *m){
    Node *flag = m->start, *data = next(flag);
    for (int i = 0; i < m->rows; ++i){
        while(flag->data == 0){
            if(data->data - i > 1 || (prev(flag) && prev(prev(flag)) && prev(prev(flag))->data == 0 && data->data == 0)) {
                print_row_zeros(m->cols);
                i++;
            }
            if(data->data == 0) {
                printf("\n");
                return;
            }
            printf("\n");
            flag = next(data);
            data = next(flag);
        }
        for (int j = 0; j < m->cols; ++j) {
            if(flag->data == 0){
                if(data->data == 0){
                    if(prev(prev(flag)) != 0)printf("0 ");
                    printf("\n");
                    return;
                }
                for (int k = j; k < m->cols; ++k) {
                    printf("0 ");
                }
                break;
            }
            if(flag->data > j + 1){
                printf("0 ");
                continue;
            }
            printf("%d ", data->data);
            flag = next(data);
            data = next(flag);
        }
    }
    printf("\n");
}


void print_inner(Matrix *m) {
    Node* el = m->start;
    while(el != m->end) {
        printf("%d ", el->data);
        el = el->next;
    }
    printf("%d\n", el->data);
}

bool skew_symmetric(Matrix *m) {
    return matrices_equal(transpose(m), negative_matrix(m));
}

Matrix* transpose(Matrix *m) {
    Matrix *m2 = (Matrix *)malloc(sizeof(Matrix));
    m2->rows = m->cols;
    m2->cols = m->rows;
    m2->end = m2->start = NULL;

    for (int i = 0; i < m2->rows; ++i) {
        push_back(m2, 0);
        push_back(m2, i+1);
    }
    push_back(m2, 0);
    push_back(m2, 0);

    Node *cur_index = next(next(m->start));
    Node *cur_data = next(cur_index);

    int x, y = 1;

    while(!(cur_index->data == 0 && cur_data->data == 0)) {
        if(cur_index->data == 0) {
            y = cur_data->data;
            goto renew;
        }
        x = cur_index->data;
        insert_xy(m2, y, x, y, cur_data->data);

        renew:
        cur_index = next(cur_data);
        cur_data = next(cur_index);
    }
    return m2;
}


Matrix* transpose_by_side_diagonal(Matrix *m) {
    Matrix *m2 = (Matrix *)malloc(sizeof(Matrix));
    m2->rows = m->cols;
    m2->cols = m->rows;
    m2->end = m2->start = NULL;

    for (int i = 0; i < m2->cols; ++i) {
        push_back(m2, 0);
        push_back(m2, i+1);
    }
    push_back(m2, 0);
    push_back(m2, 0);

    Node *cur_index = next(next(m->start));
    Node *cur_data = next(cur_index);

    int x, y = 1;

    while(!(cur_index->data == 0 && cur_data->data == 0)) {
        if(cur_index->data == 0) {
            y = cur_data->data;
            goto renew;
        }
        x = cur_index->data;
        int res_x = m->rows - y + 1;
        int res_y = m->cols - x + 1;
        insert_xy(m2, res_x, res_y, res_x, cur_data->data);

        renew:
        cur_index = next(cur_data);
        cur_data = next(cur_index);
    }
    return m2;
}

bool matrices_equal(Matrix *m1, Matrix *m2) {
    if(m1->rows != m2->rows || m1->cols != m2->cols) return false;
    Node *flag1 = m1->start, *data1 = next(flag1);
    Node *flag2 = m2->start, *data2 = next(flag2);

    while(data1 != m1->end && data2 != m2->end) {
        if(flag1->data != flag2->data || data1->data != data2->data) return false;
        flag1 = next(data1);
        data1 = next(flag1);
        flag2 = next(data2);
        data2 = next(flag2);
    }
    if(data1 == m1->end && data2 == m2->end)
        return true;
    return false;
}

Matrix* negative_matrix(Matrix *m) {
    Matrix *nm = (Matrix*)malloc(sizeof(Matrix));
    nm->cols = m->cols;
    nm->rows = m->rows;
    Node *flag = m->start;
    Node *data = next(flag);
    while(data != m->end) {
        push_back(nm, flag->data);
        if(flag->data > 0)
            push_back(nm, -data->data);
        else
            push_back(nm, data->data);
        flag = next(data);
        data = next(flag);
    }
    push_back(nm, flag->data);
    push_back(nm, -data->data);
    return nm;
}
