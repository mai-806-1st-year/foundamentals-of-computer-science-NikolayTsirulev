# Отчёт по лабораторной работе №21 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «26» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «1» <ins>апреля</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Программирование на интерпретируемых командных языках.__

### 2. Цель работы
__Научиться использовать основные команды обработки текстовых файлов OC UNIX.__

### 3. Задание (Вариант 23)
__Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков OC UNIX, согласованном с преподавателем (Bash и Python 3).__ 

__Вариант 23: Запись имен и размеров всех выполняемых файлов с указанным суффиксом в заданный файл, размер которого не должен превышать заданной величины.__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения

##### Ввод: Путь к файлам, разрешение файла, называние текстового файла для вывода, максимальный размер файлов.
##### Вывод: Файл с именами и размерами искомых файлов.
##### На Bash:
Для выполнения данной задачи используем команду find с параметрами -type f (искать только файлы), -name (искать файлы с указанным суффиксом), -size (искать файлы, размер которых не превышает заданную величину) и -printf (выводить имя файла и его размер). Затем результат перенаправляем в указанный файл.
##### На Python 3:
Для выполнения данной задачи на языке Python 3 используем модуль os и его методы listdir и stat, а также модуль argparse для парсинга аргументов командной строки. 

### 7. Сценарий выполнения работы
```python
mport os
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
hackerman@WARMACHINE_mini:~/l21$ cd dir
hackerman@WARMACHINE_mini:~/l21/dir$ chmod +x file2.txt
hackerman@WARMACHINE_mini:~/l21/dir$ chmod +x file3.txt
hackerman@WARMACHINE_mini:~/l21/dir$ ls -hl
total 12K
-rw-r--r-- 1 hackerman hackerman 147 Apr  1 14:34 file1.txt
-rw-r--r-x 1 hackerman hackerman  23 Apr  1 14:38 file2.txt
-rw-r--r-x 1 hackerman hackerman  26 Apr  1 14:38 file3.txt
hackerman@WARMACHINE_mini:~/l21/dir$ cd ..
hackerman@WARMACHINE_mini:~/l21$ cat < l21.py
mport os
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
hackerman@WARMACHINE_mini:~/l21$ cat < l21.sh
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
| 26.03.23 | 21:53 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы
https://codeforces.com/contest/1806/submission/197946453
https://codeforces.com/contest/1806/submission/198021332

### 11. Выводы
Благодаря лабораторной работе были получены навыки работы с bash-скриптами. Также были изучены методы языка Python работы с файлами, суффиксами и командной строкой. Было освоено определение суффикса файла и его размера с помощью интерпретируемых командных языков OC UNIX (Python 3 и Bash).

