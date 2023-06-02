
# Отчёт по лабораторной работе №26 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «2» <ins>июня</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «3» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Абстрактные типы данных. Рекурсия. Модульное программирование на языке Си.__

### 2. Цель работы
__Составить и отладить модуль определений и модуль реaлизaции по заданной схеме модуля определений для абстрактного (пользовательского) типа данных. Составить программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля.__

### 3. Задание (Вариант 23)
__Тип данных: дек. Процедура: слияние вдух деков, упорядоченных по возрастанию, с сохранением порядка. Метод: сортировка слиянием.__ 

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
Дек сделан на закольцованном массиве, для него определены понятия "head" (головной) и "tail" (хвостовой)- адреса первого и последнего элемента в деке относительно массива, также "capacity" - максимальное количество элементов в деке или же просто количество элементов в массиве. Для каждого элемента определены предыдущий и следующий за ним в деке элементы.
При вставке в хвост (push back) мы помещаем элемент дека в элемент массива, следующий за элементом, в котором содержится "старый" хвостовой элемент. А при вставке в голову (push front) помещаем элемент дека в элемент массива, предшествующий элементу, в котором хранится "старый" головной элемент.
Таким образом, если элемент массива с нулевым (максимальным) индексом занят, то при вставке в голову (в хвост) элемент дека помещается в элемент массива с максимальным (нулевым) индексом. Такой подход гарантирует, что всегда, когда в массиве имеются свободные элементы, допустимы операции вставки как в голову, так и в хвост.
Алгоритм сортировки: мы делим дек на две части, а потом каждую из тех частей тоже делим на две, пока в деке не будет только один элемент. Далее мы по очереди сливаем по два дека в один, сортируя их по возрастанию по определенному алгоритму.
Программа состоит из 4 файлов: 2 заголовочных "deque.h" и "types.h" и 2 файлов с кодом "deque.h" - в нем все функции дека а также сортировка и "main.c" - с демонстрацией работы программы.
### 7. Сценарий выполнения работы
```python
import os
import argparse
import sys

if len(sys.argv) > 1 and sys.argv[1] == "?":
    print("Usage: script.py directory suffix output_file max_size")
    print("directory - directory to search files in")
    print("suffix - files suffix to search for")
    print("output_file - file to write results to")
    print("max_size - maximum file size in bytes")
    sys.exit(0)

def write_files_with_suffix(directory, suffix, output_file, max_size):
    with open(output_file, 'w') as f:
        for filename in os.listdir(directory):
            if filename.endswith(suffix) and os.access(filename, os.X_OK):
                filepath = os.path.join(directory, filename)
                size = os.stat(filepath).st_size
                if size <= max_size:
                    f.write(f"{filename} {size}\n")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('directory', help='directory to search for files')
    parser.add_argument('suffix', help='file suffix to search for')
    parser.add_argument('output_file', help='file to write results to')
    parser.add_argument('max_size', type=int, help='maximum file size in bytes')
    args = parser.parse_args()

    write_files_with_suffix(args.directory, args.suffix, args.output_file, args.max_size)
```
```bash
#!/bin/bash

if [[ "$1" == "?" ]]; then
    echo "Usage: script.sh directory suffix output_file max_size"
    echo "directory - directory to search files in"
    echo "suffix - files suffix to search for"
    echo "output_file - file to write results to"
    echo "max_size - maximum file size in bytes"
    exit 0
fi

directory=$1
suffix=$2
output_file=$3
max_size=$4

find "$directory" -type f -name "*.$suffix" -size "-${max_size}c" -perm /u=x,g=x,o=x -printf "%f %s\n" > "$output_file"
```


Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/mai_labs/lab26$ ls
Makefile  deque.c  deque.h  deque.o  main  main.c  main.o  types.h
hackerman@WARMACHINE_mini:~/mai_labs/lab26$ make
make: Nothing to be done for 'debug'.
hackerman@WARMACHINE_mini:~/mai_labs/lab26$ ./main
push front: 9
push front: 5
push front: 7
push back: 0
push back: 8
push back: 8
push front: 5
push front: 9
push back: 4
push front: 1
print deque from head to tail:
1 9 5 7 5 9 0 8 8 4
print deque from tail to head:
4 8 8 0 9 5 7 5 9 1
print deque after merge sort:
0 1 4 5 5 7 8 8 9 9
head: 0
tail: 9
hackerman@WARMACHINE_mini:~/mai_labs/lab26$
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 26.03.23 | 21:53 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы
https://codeforces.com/contest/1806/submission/197946453
https://codeforces.com/contest/1806/submission/198021332

### 11. Выводы
Благодаря лабораторной работе были получены навыки работы с bash-скриптами. Также были изучены методы языка Python работы с файлами, суффиксами и командной строкой. Было освоено определение суффикса файла и его размера с помощью интерпретируемых командных языков OC UNIX (Python 3 и Bash).

