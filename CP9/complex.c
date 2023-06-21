#include "complex.h"

bool complex_read(key_complex* x) {
    if (scanf("%lf+%lf*i", &(x->real), &(x->img)) == 5)
        return true;
    return false;
}

bool complex_file_read(key_complex* x, FILE* in) {
    if (fscanf(in, "%lf+%lf*i", &(x->real), &(x->img)) == 5) {
        return true;
    }
    return false;
}

bool complex_is_equal(key_complex x1, key_complex x2) {
    if (x1.real == x2.real && x1.img == x2.img)
        return true;
    return false;
}

int fcompare(double a, double b) {
    return a < b ? 0 : a > b;
}

bool key_compare(key_complex a, key_complex b) {
    if (a.real != b.real)
        return fcompare(a.real, b.real);
    return fcompare(a.img, b.img);
}

void complex_print(key_complex x) {
    if (x.real != 0 || x.img !=0)
        printf("%.2lf+%.2lf*i", x.real, x.img);
}
