# Отчёт по лабораторной работе №10 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 23</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «10» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «24» <ins>сентября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Отладчик системы программирования OC UNIX.__

### 2. Цель работы
__Научиться отлаживать программы с помощью gdb на языке C__

### 3. Задание (Вариант 22)
__Запустить отладчик gdb и проверить основные команды отладчика.__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 8192 MiB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Cкомпилируем программу с ключом компилятора -g с помощью g++; запустим отладчик gdb и отладим программу__

### 7. Сценарий выполнения работы
1) Компилируем: ```g++ -g filename.c```.
2) Запускаем отладчик: ```gdb a.out```.
3) Используем команды: 
```
list
```
- Распечатка текста функции/процедуры/файла или всей программы, начиная с указанной строки (по умолчанию распечатываются следующие 10 строк программы);
```
break
```
- Задается точка остановки программы на указанной строке/функции;
```
run
```
-Запуск программы на выполнение.
```
print
```
- Печать значения выражения;
```
next
```
- Выполнение очередной строки программы при пошаговой трассировке;
```
step
```
- Выполнение очередной строки программы;
```
set var
```
- Присваивание значения переменной;
```
ptype
```
- Распечатка содержимого стека вызовов;
```
continue
```
- Продолжение выполнения программы после остановки;
```
quit
```
- Выход из отладчика.

### 8. Распечатка протокола
```
hackerman@WARMACHINE_mini:~$ g++ -g LAB8.c
hackerman@WARMACHINE_mini:~$ gdb a.out
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb) list 1
1       #include<stdio.h>
2       int main(){
3          int year;
4          scanf("%d",&year);
5          if (((year%4==0)&&(year%100!=0))||(year%400==0))
6             printf("%d is a leap year\n", year);
7          else printf("%d is not a leap year\n", year);
8          return 0;
9       }
(gdb) break 5
Breakpoint 1 at 0x11bc: file LAB8.c, line 5.
(gdb) run
Starting program: /home/hackerman/a.out
400

Breakpoint 1, main () at LAB8.c:5
5          if (((year%4==0)&&(year%100!=0))||(year%400==0))
(gdb) continue
Continuing.
400 is a leap year
[Inferior 1 (process 573) exited normally]
(gdb) print 1+2
$1 = 3
(gdb) run
Starting program: /home/hackerman/a.out
n

Breakpoint 1, main () at LAB8.c:5
5          if (((year%4==0)&&(year%100!=0))||(year%400==0))
(gdb) n
7          else printf("%d is not a leap year\n", year);
(gdb) set var year=2
(gdb) n
2 is not a leap year
8          return 0;
(gdb) ptype year
type = int
(gdb) quit
A debugging session is active.

        Inferior 1 [process 577] will be killed.

Quit anyway? (y or n)
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

    t = (d1 < 0) || (d2 < 0) || (d3 < 0);
    f = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(f && t);
}



int main() {
    const int i0 = 8, j0 = 15, l0 = 10;
    int i=i0, j=j0, l=l0, k=0;
    while(!isPointInArea(i, j)){
        if(k==50)break;
        printf("(i,j) = (%d,%d)\n", i, j);
        printf("l = %d\n", l);
        printf("k = %d\n", k);
        int i_temp = i, j_temp = j, l_temp = l;
        i = mod((mod((i_temp + j_temp), (abs(min(j_temp-l_temp, l_temp - k)) + 1)) - k), 20) + 10;
        j = max((i_temp + j_temp)/(2 + sign(j_temp * l_temp - i_temp * k)), (j_temp + l_temp)/(2 + sign(i_temp * j_temp - l_temp*k))) - 10;
        l = mod(max(i_temp, j_temp) * min(i_temp, l_temp), 30);
        k++;
    }
    if(k==50&&!isPointInArea(i, j))
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
| 10.11.22 | 11:56 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы

Были изучены методы отладки программы на C с помощью компиляции с использованием ключа компилятора -g и запуска отладчика gdb, а также основные команды отладчика gdb.
