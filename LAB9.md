# Отчёт по лабораторной работе №9 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 23</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «9» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «24» <ins>сентября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Составление простейших программ на языке С.__

### 2. Цель работы
__Составление и отладка простейшей программы на языке С итеративного характера с целочисленными рекуррентными соотношениями, задающими некоторое регулярное движение точки в целочисленной системе координат (i, j) с дискретным временем k и динамическим параметром движения l.__

### 3. Задание (Вариант 22)
__Треугольник с вершинами в точках (-10, 0) , (0, 10), (-10, 20). i0 = 8, j0=15, l0=10__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 8192 MiB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Если соединить все точки, образующие треугольник, линиями, то мы сможем узнать, находится ли точка внутри треугольника или нет, определив с какой стороны от каждой линии находится точка.__

### 7. Сценарий выполнения работы
1) Напишем функцию ```SignOfPoint```, которая будет определять "знак" точки относительно прямой.
2) Напишем вспомогательные функции min, max, sign, mod.
3) Объявим структуру "Pos", которая будет описывать точку на плоскости.
4) Напишем функцию ```isPointinArea```, которая будет на выходе давать ответ, принадлежит ли точка области или нет.
5) Напишем цикл "While", в условии которого будет невыполнение функции ```isPointinArea```, она будет на каждой итерации изменять значения.

### 8. Распечатка протокола
```
hackerman@WARMACHINE_mini:~$ nano LAB9.c
hackerman@WARMACHINE_mini:~$ gcc -std=c18 LAB9.c
hackerman@WARMACHINE_mini:~$ ./a.out
Point reached the area less or equal then 50 steps(16)
The coordinates are (-9, 7)
The dynamic parameter of movement is 16
hackerman@WARMACHINE_mini:~$
```

```
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

```
### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 09.11.22 | 19:39 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы

Были изучены методы нахождения принадлежности точки к треугольнику в декартовой системе координат, а также составление простых программ на языке С.

