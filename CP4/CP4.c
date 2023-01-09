#include <stdio.h>
#include <math.h>

typedef long double ld;
typedef ld(*pFunc)(ld);

ld machineeps() {
    ld epsilon = 1, prev;
    ld expression;
    do {
        prev = epsilon;
        epsilon = epsilon / 2;
        expression = 1 + epsilon;

    } while (expression > 1);
    return prev;
}
ld dx(pFunc f, ld x) {
    ld eps = machineeps() * 2;
    return (f(x + eps / 2) - f(x - eps / 2)) / eps;
}

ld sign(ld x) {
    return x > machineeps() ? 1 : x < -machineeps() ? -1 : 0;
}

ld dht_method(pFunc f, ld a, ld b) {
    ld x = (a + b) / 2;
    while (fabsl(a - b) > machineeps()) {
        x = (a + b) / 2;
        if(f(a) * f(x) > 0.l) a = x;
        else b = x;
    }
    return x;
}

ld iter_method(pFunc f, ld a, ld b) {
    ld x = (a + b) / 2;
    while(fabsl(f(x)) > machineeps()){
        x = x - f(x) * sign(dx(f, x));
    }
    return x;
}

ld newton_method(pFunc f, ld a, ld b) {
    ld x = (a + b) / 2;
    while(fabsl(f(x) / dx(f, x)) > machineeps()){
        x = x - f(x) / dx(f, x);
    }
    return x;
}

ld a = 0, b = 1;
ld func(ld x) {
    return acosl(x) - sqrtl(1 - 0.3 * powl(x, 3));
}

int main() {
    printf("dichotomy method result for func: %Lf\n", dht_method(func, a, b));
    printf("iteration method result for func: %Lf\n", iter_method(func, a, b));
    printf("newton method result for func: %Lf\n", newton_method(func, a, b));
}
