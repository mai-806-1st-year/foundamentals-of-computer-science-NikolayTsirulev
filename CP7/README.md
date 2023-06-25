

# Отчёт по курсовой работе №7 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «23» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «23» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Разреженные матрицы.__

### 2. Цель работы
__Составить и отладить программу на языке Си для обработки разреженных матриц с элементами целого типа.__

### 3. Задание (Вариант 21)
- Вариант схемы размещения матрицы: 1 вектор.
- Вариант физического представления: отображение на динамические структуры данных.
- Транспонировать разреженную матрицу относительно побочной диагонали. Выяснить, является ли полученная матрица кососимметрической

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
```
Реализуем следующие функции:  
Matrix* init();  
void free_matrix(Matrix* m);  
void push_back(Matrix* m, int element);  
int pop_back(Matrix* m);  
bool enter(Matrix* m, char* filename);  
void print(Matrix *m);  
void print_inner(Matrix *m);  
bool skew_symmetric(Matrix *m);  
Matrix* transpose(Matrix *m);  
Matrix* transpose_by_side_diagonal(Matrix *m);  
bool matrices_equal(Matrix *m1, Matrix *m2);  
Matrix* negative_matrix(Matrix *m);  
```

### 7. Сценарий выполнения работы
```
hackerman@WARMACHINE_mini:~/mai_labs/cp7/cpnew$ make clean all
rm -fr *.o main
gcc -Wall  -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -Wno-unused-result -c main.c -o main.o
gcc -Wall  -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -Wno-unused-result -c matrix.c -o matrix.o
gcc  main.o matrix.o  -o main
```
![изображение](https://github.com/mai-806-1st-year/fundamentals-of-computer-science-NikolayTsirulev/assets/86667038/a0e56e9b-ac44-47cf-b9d5-25b0d52bd6e7)


Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/mai_labs/cp7/cpnew$ valgrind --leak-check=full --show-leak-kinds=all -s --track-origins=yes ./main
==3724== Memcheck, a memory error detector
==3724== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3724== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==3724== Command: ./main
==3724==
Print name of file: input.txt
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
1
The matrix was successfully read

1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
2

1 2 3 4
0 0 0 0
1 0 0 0
1 0 0 1
1 0 0 4
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
3
0 1 1 1 2 2 3 3 4 4 0 2 0 3 1 1 0 4 1 1 4 1 0 5 1 1 4 4 0 0
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
6
Matrix is not skew-symmetric.
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
4
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
2

1 0 1 1 1
2 0 0 0 0
3 0 0 0 0
4 0 0 1 4
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
4
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
5
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
2

4 1 0 0 4
0 0 0 0 3
0 0 0 0 2
1 1 1 0 1
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
7
1. Read matrix.
2. Print matrix.
3. Print inner data of matrix
4. Transpose matrix.
5. Transpose by side-diagonal matrix.
6. Check the whether the matrix is skew-matrix.
7. Quit.
The program is closed
==3698==
==3698== HEAP SUMMARY:
==3698==     in use at exit: 0 bytes in 0 blocks
==3724==   total heap usage: 187 allocs, 187 frees, 11,024 bytes allocated
==3698==
==3698== All heap blocks were freed -- no leaks are possible
==3698==
==3698== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 23.06.23 | 16:55 | Выполнение курсовой работы | |

### 10. Замечания автора по существу работы
Защита (contest 1841, Div 2):  
[задача A](https://codeforces.com/contest/1841/submission/209398915)  


### 11. Выводы
Были получены навыки написания эффективных программ для обработки разреженных матриц. Были отработаны навыки работы с файлами, динамическими структурами и указателями в Си. Были получены навыки устранения утечек памяти с помощью Valgrind.

