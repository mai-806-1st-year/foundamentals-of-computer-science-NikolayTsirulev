#include <stdio.h>
#include <math.h>

typedef long double ld;
typedef ld(*pFunc)(ld);

ld compute_epsilon(){
    ld eps = 1;
    while (1 < 1 + eps)
        eps /= 2;
    return eps;
}
ld dx(pFunc f, ld x) {
    ld eps = compute_epsilon() * 2;
    return (f(x + eps / 2) - f(x - eps / 2)) / eps;
}

ld sign(ld x) {
    return x > compute_epsilon() ? 1 : x < -compute_epsilon() ? -1 : 0;
}

ld dht_method(pFunc f, ld a, ld b) {
    ld x = (a + (b - a) / 2);
    while (fabsl(a - b) > fmax(sqrt(compute_epsilon()) * fabs(x), compute_epsilon())) {
        x = (a + (b - a) / 2);
        if(f(a) * f(x) > 0) a = x;
        else b = x;
    }
    return x;
}

ld iter_method(pFunc f, ld a, ld b) {
    ld x = (a + (b - a) / 2);
    x = f(x);
    while(fabsl(f(x) - x) > fmax(sqrt(compute_epsilon()) * fabs(x), compute_epsilon())) {
        x = f(x);
    }
    return x;
}

ld newton_method(pFunc f, ld a, ld b) {
    ld x = (a + (b - a) / 2);
    while(fabsl(f(x) / dx(f, x)) > fmax(sqrt(compute_epsilon()) * fabs(x), compute_epsilon())){
        //if (dx(f, x) < fmax(sqrt(compute_epsilon()) * fabs(x), compute_epsilon())) return x;
        //printf("%ld\n", dx(f, x));
        x = x - f(x) / (dx(f, x));
    }
    return x;
}

ld func1(ld x) {
    return acosl(x) - sqrtl(1 - 0.3 * powl(x, 3));
}

ld funx1(ld x) {
    return cos(sqrtl(1 - 0.3 * powl(x, 3)));
}

ld func2(ld x) {
    return 3*x - 4*log(x) - 5;
}

ld funx2(ld x) {
    return (4*log(x) + 5) / 3;
}

int main() {
    ld a = 0, b = 1;
    printf("dichotomy method result for func1: %Lf\n", dht_method(func1, a, b));
    printf("iteration method result for func1: %Lf\n", iter_method(funx1, a, b));
    printf("newton method result for func1: %Lf\n", newton_method(func1, a, b));
    a = 2, b = 4;
    printf("dichotomy method result for func2: %Lf\n", dht_method(func2, a, b));
    printf("iteration method result for func2: %Lf\n", iter_method(funx2, a, b));
    printf("newton method result for func2: %Lf\n", newton_method(func2, a, b));
}
