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

int factorial(long long  n){
    ld ans = 1;
    for (long long i = 2; i <= n; ++i) {
        ans *= i;
    }
    return ans;
}

ld teilor_member(ld x, int n){
    ld v = 2 * ((-1) * ((n + 1) & 1)) + 1;
    v *= (n-1);
    v /= (ld)factorial(n);
    v *= powl(x, n);
    return v;
}

int main() {
    const ld k = 10e2;
    const ld a = 0;
    const ld b = 1;
    const int steps = 15;
    const int max_iters = 100;

    ld step = (b-a) / steps;
    ld eps = compute_epsilon();

    printf("Machine epsilon for long double for this system is %.20Lf\n", eps);
    printf("______________________________________________________\n");
    printf("|x   | Sum                 |(1 + x) * e ^ (-x)   |  n|\n");
    printf("|____|_____________________|_____________________|___|\n");

    for (ld x = a; x < b + step; x += step) {
        int n = 0;
        ld cur_member = 1;
        ld sum = 0;
        while ((fabsl(cur_member) > eps * k && n < max_iters) || n == 2) {
            cur_member = teilor_member(x, n);
            sum += cur_member;
            n++;
        }
        printf("|%.2Lf|%.19Lf|%.19Lf|%3d|\n", x, sum, inner_func(x), n);
    }
    printf("|____|_____________________|_____________________|___|\n");
}
