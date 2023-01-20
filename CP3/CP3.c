#include <math.h>
#include <stdio.h>

typedef long double ld;

ld compute_epsilon(){
    ld eps = 1;
    while (1 < 1 + eps)
        eps /= 2;
    return eps;
}

ld inner_func(ld x){
    return (1 + x) * expl(-x);
}

ld teilor_member(ld x, int n, long long factorial, ld temp, int n0){
    ld v = n0;
    v *= (n - 1);
    v /= (ld)factorial;
    v *= temp;
    return v;
}

int main() {
    const ld k = 10e2;
    const ld a = 0;
    const ld b = 1;
    const int steps = 15;
    const int max_iters = 100;

    ld step = (b - a) / steps;
    ld eps = compute_epsilon();

    printf("Machine epsilon for long double for this system is %.20Lf\n", eps);
    printf("______________________________________________________\n");
    printf("|x   | Sum                 |(1 + x) * e ^ (-x)   |  n|\n");
    printf("|____|_____________________|_____________________|___|\n");

    for (ld x = a; x < b + step; x += step) {
        int n = 0;
        int n0 = 1;
        ld cur_member = 1;
        ld sum = 0;
        long long factorial = 1;
        ld temp = 1;
        while ((fabsl(cur_member) > sqrt(eps) * k && n < max_iters) || n == 2) {
            n0 *= -1;
            cur_member = teilor_member(x, n , factorial, temp, n0);
            factorial *= (n + 1);
            temp *= x;
            sum += cur_member;
            n++;
        }
        printf("|%.2Lf|%.19Lf|%.19Lf|%3d|\n", x, sum, inner_func(x), n);
    }
    printf("|____|_____________________|_____________________|___|\n");
}
