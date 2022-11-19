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

struct Pos{
    int x, y;
};

int sign(int a){
    if (a > 0) return 1;
    else 
       if (a == 0) return 0;
       else 
          if (a < 0) return -1;
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

const int x1_=-10, y1_=0, x2_=0, y2_=10, x3_ = -10, y3_ = 20;
const struct Pos v1 = {x1_, y1_}, v2 = {x2_, y2_}, v3 = {x3_, y3_};

int signOfPoint (struct Pos p1, struct Pos p2, struct Pos p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool isPointInArea (int x, int y)
{
    struct Pos pt = {x, y};
    int d1, d2, d3;
    bool t,f;

    d1 = signOfPoint(pt, v1, v2);
    d2 = signOfPoint(pt, v2, v3);
    d3 = signOfPoint(pt, v3, v1);

    t = (d1 > 0) && (d2 > 0) && (d3 > 0);
    f = (d1 < 0) && (d2 < 0) && (d3 < 0);

    return (f || t);
}



int main() {
    const int i0 = 8, j0 = 15, l0 = 10;
    int i=i0, j=j0, l=l0, k=0;
    while(!isPointInArea(i, j)){
        if(k==50)break;
        int i_temp = i, j_temp = j, l_temp = l;
        i = mod((mod((i_temp + j_temp), (abs(min(j_temp-l_temp, l_temp - k)) + 1)) - k), 20) + 10;
        j = max((i_temp + j_temp) / (2 + sign(j_temp * l_temp - i_temp * k)), (j_temp + l_temp) / (2 + sign(i_temp * j_temp - l_temp*k))) - 10;
        l = mod(max(i_temp, j_temp) * min(i_temp, l_temp), 30);
        k++;
    }
    if(k==50 && !isPointInArea(i, j))
        printf("The point didn't reach the area in 50 steps\n");
    else
        printf("Point reached the area less or equal then 50 steps(%d)\n", k);
    printf("The coordinates are (%d, %d)\n", i, j);
    printf("The dynamic parameter of movement is %d\n", l);
}

```
### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 09.11.22 | 19:39 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы

Были изучены методы нахождения принадлежности точки к треугольнику в декартовой системе координат, а также составление простых программ на языке С.

