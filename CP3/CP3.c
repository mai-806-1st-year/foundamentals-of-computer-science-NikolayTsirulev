#include <math.h>
#include <stdio.h>

#define MAX_ITER 100

typedef long double ld;
typedef unsigned uint;

ld compute_epsilon() {
    ld eps = 1;
    while (1 < 1 + eps)
        eps /= 2;
    return eps;
}

ld inner_func(ld x) {
    return (1 + x) * expl(-x);
}

ld taylor(ld x) {

    ld eps = compute_epsilon();
    int n = 0; 
    int sign = 1;
    ld cur_member = 1;
    ld result = 0;
    long long factorial = 1;
    ld temp = 1;
    while ((fabsl(cur_member) > sqrt(eps) && n < MAX_ITER) || n == 2) {
        sign *= -1;
        cur_member = sign * (n - 1) / (ld)factorial * temp;
        factorial *= (n + 1);
        temp *= x;
        result += cur_member;
        n++;
    }
    return result;
}

void tabulation(const ld a, const ld b, const uint steps) {
    const ld step = (b - a) / steps;
    for (ld x = a; x < b + step; x += step) {
        printf("|%.3Lf|%.19Lf|%.19Lf|\n", x, inner_func(x), taylor(x));
    }
}

int main() {
    const ld a = 0;
    const ld b = 1;
    const uint steps = 15;
    printf("__________________________________________________\n");
    printf("|  x  |   Inner function    |     Sum of row      |\n");
    printf("|_____|_____________________|_____________________|\n");
    tabulation(a, b, steps);
    printf("|_____|_____________________|_____________________|\n");
}
