# Отчёт по лабораторной работе №20 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «3» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «11» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Программирование на интерпретируемых командных языках.__

### 2. Цель работы
__Научиться использовать основные команды обработки текстовых файлов OC UNIX.__

### 3. Задание (Вариант 23)
__Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков OC UNIX, согласованном с преподавателем (Bash и Python3). Вариант 23: Запись имен и размеров всех выполняемых файлов с указанным суффиксом в заданный файл, размер которого не должен превышать заданной величины.__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения

###### Ввод: Путь к файлам, разрешение файла, называние текстового файла для вывода, максимальный размер файлов.
###### Вывод: Файл с именами и размерами искомых файлов.
##### На Bash:
Для выполнения данной задачи используем команду find с параметрами -type f (искать только файлы), -name (искать файлы с указанным суффиксом), -size (искать файлы, размер которых не превышает заданную величину) и -printf (выводить имя файла и его размер). Затем результат перенаправляем в указанный файл.
###### На Python 3:
Для выполнения данной задачи на языке Python 3 используем модуль os и его методы listdir и stat, а также модуль argparse для парсинга аргументов командной строки. 

### 7. Сценарий выполнения работы
```python
import os
import argparse

def write_files_with_suffix(directory, suffix, output_file, max_size):
    with open(output_file, 'w') as f:
        for filename in os.listdir(directory):
            if filename.endswith(suffix):
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

directory=$1
suffix=$2
output_file=$3
max_size=$4

find "$directory" -type f -name "*.$suffix" -size "-${max_size}c" -printf "%f %s\n" > "$output_file"
```


Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/l21$ cd dir
hackerman@WARMACHINE_mini:~/l21/dir$ ls -hl
total 12K
-rw-r--r-- 1 hackerman hackerman 147 Apr  1 14:34 file1.txt
-rw-r--r-- 1 hackerman hackerman  23 Apr  1 14:38 file2.txt
-rw-r--r-- 1 hackerman hackerman  26 Apr  1 14:38 file3.txt
hackerman@WARMACHINE_mini:~/l21/dir$ cd ..
hackerman@WARMACHINE_mini:~/l21$ cat < l21.py
import os
import argparse

def write_files_with_suffix(directory, suffix, output_file, max_size):
    with open(output_file, 'w') as f:
        for filename in os.listdir(directory):
            if filename.endswith(suffix):
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
hackerman@WARMACHINE_mini:~/l21$ cat < l21.sh
#!/bin/bash

directory=$1
suffix=$2
output_file=$3
max_size=$4

find "$directory" -type f -name "*.$suffix" -size "-${max_size}c" -printf "%f %s\n" > "$output_file"
hackerman@WARMACHINE_mini:~/l21$ python3 l21.py /home/hackerman/l21/dir .txt output.txt 24
hackerman@WARMACHINE_mini:~/l21$ bash l21.sh /home/hackerman/l21/dir txt output1.txt 27
hackerman@WARMACHINE_mini:~/l21$ ls
dir  l21.py  l21.sh  output.txt  output1.txt
hackerman@WARMACHINE_mini:~/l21$ cat < output.txt
file2.txt 23
hackerman@WARMACHINE_mini:~/l21$ cat < output1.txt
file2.txt 23
file3.txt 26
hackerman@WARMACHINE_mini:~/l21$
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 03.03.23 | 15:57 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы
https://codeforces.com/contest/1806/submission/197946453
https://codeforces.com/contest/1806/submission/198021332

### 11. Выводы
Были изучены методы работы с файлами посредством утилит OC UNIX. Наиболее подробно были рассмотрены следующие утилиты: head - выводит n-ое количество строк из файла, dd - копирует, конвертирует файлы, tar - средство, которое запаковывает, распаковывает архивы, и работает с архивами.

