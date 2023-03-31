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

### 3. Задание (Вариант 21)
__Составить программу выполнения заданных действий над файлами на одном из интерпретируемых командных языков OC UNIX, согласованном с преподавателем (Bash и Python3). Вариант 21: Удаление всех синонимов указанного файла из указанного каталога и его поддиректорий.__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Составим программы на Python3 и Bash для решения данной задачи, и протестируем на каталогах ```lab21```, с поддиректориями ```dir1``` и ```dir2``` и с файлами ```file.txt``` и ```file1.txt```.__


### 7. Сценарий выполнения работы
Программа на Python:
1. Ищем все файлоы с заданным именем и расширением в каталоге и его поддиректориях с помощью функции ```glob.glob()```;
2. Удаляем синонимы  с помощью функции  ```os.remove()```.
Программа на bash:
1. Переходим в нужную директорию с помощью функции ```cd```;
2. Задаем имя файла, синонимы которого нужно удалить;
3. Используем команду ```find``` для поиска всех файлов с именем ```filename``` в текущей директории и ее поддиректориях;
4. Проверяем, является ли файл синонимом;
5. Если файл является синонимом, то удаляем его.

Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~$ mkdir lab21
hackerman@WARMACHINE_mini:~$ cd lab21
hackerman@WARMACHINE_mini:~/lab21$ mkdir dir1
hackerman@WARMACHINE_mini:~/lab21$ mkdir dir2
hackerman@WARMACHINE_mini:~/lab21$ touch file.txt
hackerman@WARMACHINE_mini:~/lab21$ touch file1.txt
hackerman@WARMACHINE_mini:~/lab21$ touch file2.txt
hackerman@WARMACHINE_mini:~/lab21$ ls
dir1  dir2  file.txt  file1.txt  file2.txt
hackerman@WARMACHINE_mini:~/lab21$ cd dir1
hackerman@WARMACHINE_mini:~/lab21/dir1$ touch file.txt
hackerman@WARMACHINE_mini:~/lab21/dir1$ touch file1.txt
hackerman@WARMACHINE_mini:~/lab21/dir1$ cd ..
hackerman@WARMACHINE_mini:~/lab21$ cd dir2
hackerman@WARMACHINE_mini:~/lab21/dir2$ touch file.txt
hackerman@WARMACHINE_mini:~/lab21/dir2$ touch file1.txt
hackerman@WARMACHINE_mini:~/lab21/dir2$ cd ..
hackerman@WARMACHINE_mini:~/lab21$ cd ..
hackerman@WARMACHINE_mini:~$ cat > lab21sh.sh
#!/bin/bash
cd /home/hackerman/lab21
filename="file.txt"

find . -type f -name "$filename" -print0 | while read -d $'\0' file
do
    if [ -f "$file" ]; then
        rm "$file"
        echo "File synonym removed $file"
    fi
done

echo "Synonym deletion completed"^C
hackerman@WARMACHINE_mini:~$ bash lab21sh.sh
File synonym removed ./file.txt
File synonym removed ./dir2/file.txt
File synonym removed ./dir1/file.txt
hackerman@WARMACHINE_mini:~$ cd lab21
hackerman@WARMACHINE_mini:~/lab21$ ls
dir1  dir2  file1.txt  file2.txt
hackerman@WARMACHINE_mini:~/lab21$ cd dir1
hackerman@WARMACHINE_mini:~/lab21/dir1$ ls
file1.txt
hackerman@WARMACHINE_mini:~/lab21/dir1$ cd ..
hackerman@WARMACHINE_mini:~/lab21$ cd dir2
hackerman@WARMACHINE_mini:~/lab21/dir2$ ls
file1.txt
hackerman@WARMACHINE_mini:~/lab21/dir2$ cd ..
hackerman@WARMACHINE_mini:~/lab21$ cd ..
hackerman@WARMACHINE_mini:~$ cat > lab21.py
import os
import glob

def main(filename: str, directory: str):

    file_list = glob.glob(os.path.join(directory, '**', filename), recursive=True)

    for file_path in file_list:
        if os.path.islink(file_path):
            os.remove(file_path)
        else:
            os.remove(file_path)

if __name__ == '__main__':
    filename = 'file1.txt'
    directory = '/home/hackerman/lab21'
    main(filename, directory)
^C
hackerman@WARMACHINE_mini:~$ python3 lab21.py
hackerman@WARMACHINE_mini:~$ cd lab21
hackerman@WARMACHINE_mini:~/lab21$ ls
dir1  dir2  file2.txt
hackerman@WARMACHINE_mini:~/lab21$ cd dir1
hackerman@WARMACHINE_mini:~/lab21/dir1$ ls
hackerman@WARMACHINE_mini:~/lab21/dir1$ cd ..
hackerman@WARMACHINE_mini:~/lab21$ cd dir2
hackerman@WARMACHINE_mini:~/lab21/dir2$ ls
hackerman@WARMACHINE_mini:~/lab21/dir2$
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

