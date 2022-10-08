# Отчет по лабораторной работе №1-2 по курсу "Фундаментальная информатика"
___Студент группы:___ М8О-108Б-22 \
___ФИО:___ Цирулев Николай Владимирович \
___Почта:___ mrcirniko@gmail.com \
___Преподаватель:___ Сахарин Никита Александрович 

### 1. Тема
__Операционная среда ОС UNIX__

### 2. Цель работы
__Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX__

### 3. Задание
__Приобрести основные навыки работы в ОС UNIX и научиться навигации в иерархической файловой системе, манипуляции с файлами (создание, копирование, удаление и т. д.).__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 8192 MiB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Для достижения поставленной цели используем основные команды bash для работы с каталогами, текстовыми файлами, тектовыми редакторами и некоторыми утилитами.__

### 7. Сценарий выполнения работы
#### Используем команды:
```
whoami 
```
Называет имя пользователя
```
hostname
```
Используется для вывода или установки имени системного хоста
```
uname
```
Отображает сведения о системе
```
date
```
Отображает системную дату
```
finger
```
Сообщает некоторую информацию о пользователе
```
pwd
```
Отображает имя текущего/рабочего каталога
```
ls
```
Отображает содержимое каталога
```
mkdir
```
Команда используется для создания одного или нескольких каталогов
```
cd
```
Позволяет перемещаться между каталогами
```
nano
```
Запускает текстовый редактор nano
```
rmdir
```
Помогает удалить пустые каталоги
```
touch
```
Создает файл
```
cp
```
Копирует файлы и каталоги из одного места в другое
```
mv
```
Используется для переименования файлов или каталогов
```
chmod
```
Используется для изменения/обновления прав доступа к файлу
```
find
```
Позволяет искать файлы в каталоге, а также в его подкаталогах
```
cat
```
Открывает файл в командной строке, и позволяет его редактировать
```
grep
```
Ищет упоминание текста в файле
```
rm
```
Удаляет файл
```
uptime
```
Вызывает время работы сервера
```
who
```
Выводит информацию о пользователях, которые подключены к системе, в том числе и об терминальных сессиях, через которые происходит подключение
```
man
```
Используется для просмотра справочных руководств системы
#### Создаем скрипт, демонстрирующий работу некоторых команд: 
```
#1/bin/bash
echo "Hello $(whoami)"
echo "You are in this  directory $(pwd)"
echo "And the time is now $(date)"
echo "Content of the current directory: $(ls)"
```


### 8. Распечатка протокола
```
hackerman@WARMACHINE_mini:~$ whoami
hackerman
hackerman@WARMACHINE_mini:~$ hostname
WARMACHINE_mini
hackerman@WARMACHINE_mini:~$ uname
Linux
hackerman@WARMACHINE_mini:~$ date
Wed Sep 28 20:58:50 MSK 2022
hackerman@WARMACHINE_mini:~$ finger hackerman
Login: hackerman                        Name:
Directory: /home/hackerman              Shell: /bin/bash
Never logged in.
No mail.
No Plan.
hackerman@WARMACHINE_mini:~$ pwd
/home/hackerman
hackerman@WARMACHINE_mini:~$ ls
hey.txt  hey.txt.save  lab_fundamentals_of_computer_science  test.sh  test.sh.save
hackerman@WARMACHINE_mini:~$ mkdir test
hackerman@WARMACHINE_mini:~$ cd test
hackerman@WARMACHINE_mini:~/test$ cd
hackerman@WARMACHINE_mini:~$ file test
test: directory
hackerman@WARMACHINE_mini:~$ rmdir tesy
rmdir: failed to remove 'tesy': No such file or directory
hackerman@WARMACHINE_mini:~$ rmdir test
hackerman@WARMACHINE_mini:~$ touch text.txt
hackerman@WARMACHINE_mini:~$ ls
hey.txt       lab_fundamentals_of_computer_science  test.sh.save
hey.txt.save  test.sh                               text.txt
hackerman@WARMACHINE_mini:~$ cp text.txt text1.txt
hackerman@WARMACHINE_mini:~$ mv text.txt text
hackerman@WARMACHINE_mini:~$ chmod u+x text
hackerman@WARMACHINE_mini:~$ ls
hey.txt       lab_fundamentals_of_computer_science  test.sh.save  text1.txt
hey.txt.save  test.sh                               text
hackerman@WARMACHINE_mini:~$ find text
text
hackerman@WARMACHINE_mini:~$ cat>text
WORDS^Z
[2]+  Stopped                 cat > text
hackerman@WARMACHINE_mini:~$ grep WORDS text

hackerman@WARMACHINE_mini:~$ rm text
hackerman@WARMACHINE_mini:~$ ls
hey.txt       lab_fundamentals_of_computer_science  test.sh.save  text1.txt
hey.txt.save  test.sh                              
hackerman@WARMACHINE_mini:~$ uptime
 21:31:03 up 59 min,  1 user,  load average: 0,06, 0,03, 0,00
hackerman@WARMACHINE_mini:~$
hackerman@WARMACHINE_mini:~$ nano script.sh
hackerman@WARMACHINE_mini:~$ bash ./script.sh
Hello hackerman
You are in this  directory /home/hackerman
And the time is now Fri Sep 30 23:09:08 MSK 2022
Content of the current directory: Documentals
gnuplot
hey.txt
hey.txt.save
lab_fundamentals_of_computer_science
script.sh
test.sh.save
text1.txt
hackerman@WARMACHINE_mini:~$
```
### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 28.09.22 | 21:02 | rmdir: failed to remove 'tesy': No such file or directory | Вводим правильное имя директории |

### 10. Замечания автора по существу работы

### 11. Выводы

Я изучил и освоил программное обеспечение ОС UNIX и приобрел навыки, необходимые для выполнения курсовых и лабораторных работ в среде UNIX. Я научился навигации в иерархической файловой системе, манипуляциям с файлами (создание, удаление, перемещение, копирование, редактирование).

