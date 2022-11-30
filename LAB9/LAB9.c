#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct{
    int x, y;
} Pos;
typedef struct{
    Pos p;
    int l;
} PosAndL;

typedef struct{
    Pos v1, v2, v3;
} Triangle;

int sign(int a){
    if (a > 0) return 1;
    else if (a == 0) return 0;
    else return -1;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int mod(int a, int b){
    return a - (a / b) * b;
}


int signOfPoint(Pos p1, Pos p2, Pos p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool isPointInArea(Pos pt, Triangle ar)
{
    int d1, d2, d3;
    bool t,f;
    d1 = signOfPoint(pt, ar.v1, ar.v2);
    d2 = signOfPoint(pt, ar.v2, ar.v3);
    d3 = signOfPoint(pt, ar.v3, ar.v1);

    t = (d1 > 0) && (d2 > 0) && (d3 > 0);
    f = (d1 < 0) && (d2 < 0) && (d3 < 0);

    return (f || t);
}

PosAndL recalcPoint(PosAndL a, int k)
{
    PosAndL Result;
    int i_temp = a.p.x, j_temp = a.p.y, l_temp = a.l;
    Result.p.x = mod((mod((i_temp + j_temp), (abs(min(j_temp - l_temp, l_temp - k)) + 1)) - k), 20) + 10;
    Result.p.y = max((i_temp + j_temp) / (2 + sign(j_temp * l_temp - i_temp * k)), (j_temp + l_temp) / (2 + sign(i_temp * j_temp - l_temp*k))) - 10;
    Result.l = mod(max(i_temp, j_temp) * min(i_temp, l_temp), 30);
    return Result;
}

int main() {
    
    PosAndL PointAndL = {8, 15, 10};
    int k=0;
    const Pos v1 = {-10, 0}, v2 = {0, 10}, v3 = {-10, 20};
    Triangle ar = {v1, v2, v3};
    while(!isPointInArea(PointAndL.p, ar)){
        if(k==50)break;
        PointAndL = recalcPoint(PointAndL, k);
        k++;
    }
    if(k==50 && !isPointInArea(PointAndL.p, ar))
        printf("The point didn't reach the area in 50 steps\n");
    else
        printf("Point reached the area less or equal then 50 steps(%d)\n", k);
    printf("The coordinates are (%d, %d)\n", PointAndL.p.x, PointAndL.p.y);
    printf("The dynamic parameter of movement is %d\n", PointAndL.l);
}
