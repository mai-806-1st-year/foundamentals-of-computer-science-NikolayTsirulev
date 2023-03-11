# Отчёт по лабораторной работе №20 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «3» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «11» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Стандартные утилиты UNIX для обработки файлов.__

### 2. Цель работы
__Научиться использовать основные команды обработки текстовых файлов OC UNIX.__

### 3. Задание (Вариант 21)
__Изучить не менее, чем 20 "обязательных" утилит пакетного режима, изучить более подробно 3 утилиты согласно варианту (21 вариант: №25 - head, №4 - dd, №19 - tar).__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 16GB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Используем данные утилиты, вводя по несколько команд каждой.__

| Команда |  Базовый синтакис | Флаги | Описание |
| ------ | ------ | ------ | ------ |
| head | head [опции] <файл_1> ... <файл_n> | -c (--bytes) — позволяет задавать количество текста не в строках, а в байтах, при записи в виде --bytes=[-]NUM выводит на экран все содержимое файла, кроме NUM байт, расположенных в конце документа; -n (--lines) — показывает заданное количество строк вместо 10, которые выводятся по умолчанию, если записать эту опцию в виде --lines=[-]NUM, будет показан весь текст кроме последних NUM строк; -q (--quiet, --silent) — выводит только текст, не добавляя к нему название файла; -v (--verbose) — перед текстом выводит название файла; -z (--zero-terminated) — символы перехода на новую строку заменяет символами завершения строк | Команда head выводит начальные строки (по умолчанию — 10)  из одного или нескольких документов. Также она может показывать данные, которые передает на вывод другая утилита |
| dd | dd if=<путь_к_файлy> of=<куда_копировать> [опции] |bs - указывает сколько байт читать и записывать за один раз; count - скопировать указанное количество блоков, размер одного блока указывается в параметре bs; conv - применить фильтры к потоку данных; ibs - читать указанное количество байт за раз; obs - записывать указанное количество байт за раз; seek - пропустить указанное количество байт в начале устройства для чтения; skip - пропустить указанное количество байт в начале устройства вывода; | Команда служит для копирования, конвертации файлов, а так же для чтения данных |
| tar | tar [опции] <архив>.tar <файлы_для_архивации> | -A 	(--concatenate) 	присоединить существующий архив к другому; -c 	(--create) создать новый архив; -d 	(--diff --delete) 	проверить различие между архивам и файловой системой, удалить из существующего архива файл; -r 	(--append) 	присоединить файлы к концу архива; -t 	(--list) 	сформировать список содержимого архива; -u 	(--update) 	обновить архив более новыми файлами с тем же именем; -x 	(--extract) 	извлечь файлы из архива; -f file 	(--file) 	вывести результат в файл (или на устройство) file; -p 	(--same-permissions) 	сохранить все права доступа к файлу; -v 	(--verbose) 	выводить подробную информацию процесса; --totals 	выводить итоговую информацию завершенного процесса | Архиватор |


### 7. Сценарий выполнения работы

1. ```cmp``` – сравнивает два файла и, если они различаются, сообщает о первом байте и строке, где было обнаружено различие
2. ```wc``` – вывод числа переводов строк, слов и байт для каждого указанного файла и итоговую строку, если было задано несколько файлов
3. ```diff``` – утилита сравнения файлов, выводящая разницу между двумя файлами
4. ```grep``` – утилита для поиска наборов данных в виде обычного текста строк, соответствующих регулярному выражению
5. ```tail``` – вывод нескольких (по умолчанию 10) последних строк из файла
6. ```tr``` – утилита для преобразования символов
7. ```uniq``` – вывод или отфильтр повторяющиеся строки в отсортированном файле
8. ```od``` – вывод дампа файла
9. ```sum``` - вывод контрольной суммы каждого файла, а также количество блоков, которые эти файлы занимают на запоминающем устройстве
10. ```gzip``` – утилита сжатия и декомпрессии файлов
11. ```bzip2``` – сжатие, распаковка данных
12. ```icnov``` – преобразует текст из одной кодировки в другую
13. ```patch``` – утилита для переноса правок между разными версиями текстовых файлов
14. ```du``` – оценка занимаемого файлового пространства
15. ```file``` – определяет тип файла
16. ```touch``` – создание пустого файла, если его нет. Если файл есть, то команда установит дату обращения в текущий момент времени
17. ```find``` – утилита поиска файлов по имени и другим свойствам
18. ```df``` – оказывает список всех файловых систем по именам устройств, сообщает их размер, занятое и свободное пространство и точки монтирования
19. ```split``` – разделение компьютерного файла на два или более файлов меньшего размера
20. ```mktemp``` – создает уникальное временное имя файлу                  

Пункты 1-7 отчета составляются строго до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________

### 8. Распечатка протокола
 ```
hackerman@WARMACHINE_mini:~/lab20$ cat file1.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
6 nostra, per inceptos himenaeos. In sagittis dui purus, sit amet faucibus nulla rutrum vitae.
7 Morbi elit nunc, ullamcorper eget velit eu, elementum vehicula sapien. Sed nec enim est.
hackerman@WARMACHINE_mini:~/lab20$ cat file2.txt
1 Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
2 tortor. Praesent quis suscipit ipsum. Aliquam erat volutpat. Duis turpis erat, auctor sed
3 sodales non, ullamcorper vel est. Ut sagittis libero et massa sollicitudin vestibulum.
4 Vivamus egestas leo id consectetur maximus. Nullam dignissim libero at lectus maximus, non
5 blandit orci porta. Morbi non mauris tellus.
hackerman@WARMACHINE_mini:~/lab20$ head file1.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
6 nostra, per inceptos himenaeos. In sagittis dui purus, sit amet faucibus nulla rutrum vitae.
7 Morbi elit nunc, ullamcorper eget velit eu, elementum vehicula sapien. Sed nec enim est.
hackerman@WARMACHINE_mini:~/lab20$ head -c 251 file1.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringhackerman@WARMACHINE_mini:~/lab20$
hackerman@WARMACHINE_mini:~/lab20$
hackerman@WARMACHINE_mini:~/lab20$ head -n 3 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ head -n 3 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ head -n 3 file1.txt file2.txt
==> file1.txt <==
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.

==> file2.txt <==
1 Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
2 tortor. Praesent quis suscipit ipsum. Aliquam erat volutpat. Duis turpis erat, auctor sed
3 sodales non, ullamcorper vel est. Ut sagittis libero et massa sollicitudin vestibulum.
hackerman@WARMACHINE_mini:~/lab20$ head --lines=-2 file1.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
hackerman@WARMACHINE_mini:~/lab20$ head -q file1.txt file2.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
6 nostra, per inceptos himenaeos. In sagittis dui purus, sit amet faucibus nulla rutrum vitae.
7 Morbi elit nunc, ullamcorper eget velit eu, elementum vehicula sapien. Sed nec enim est.
1 Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
2 tortor. Praesent quis suscipit ipsum. Aliquam erat volutpat. Duis turpis erat, auctor sed
3 sodales non, ullamcorper vel est. Ut sagittis libero et massa sollicitudin vestibulum.
4 Vivamus egestas leo id consectetur maximus. Nullam dignissim libero at lectus maximus, non
5 blandit orci porta. Morbi non mauris tellus.
hackerman@WARMACHINE_mini:~/lab20$ head -v file1.txt
==> file1.txt <==
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
6 nostra, per inceptos himenaeos. In sagittis dui purus, sit amet faucibus nulla rutrum vitae.
7 Morbi elit nunc, ullamcorper eget velit eu, elementum vehicula sapien. Sed nec enim est.
hackerman@WARMACHINE_mini:~/lab20$ head -z file1.txt
1 Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
2 scelerisque. Aenean cursus nibh et suscipit gravida. Nullam condimentum nec dolor sit amet
3 tincidunt. In hac habitasse platea dictumst. Curabitur fringilla justo ac hendrerit blandit.
4 Mauris aliquet quam bibendum magna condimentum placerat quis in elit. Curabitur aliquet lorem
5 egestas lacus malesuada porta. Class aptent taciti sociosqu ad litora torquent per conubia
6 nostra, per inceptos himenaeos. In sagittis dui purus, sit amet faucibus nulla rutrum vitae.
7 Morbi elit nunc, ullamcorper eget velit eu, elementum vehicula sapien. Sed nec enim est.
hackerman@WARMACHINE_mini:~/lab20$ cat > file3.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
^C
hackerman@WARMACHINE_mini:~/lab20$ cat > file4.txt
Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
^C
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt
0+1 records in
0+1 records out
94 bytes copied, 0.000134617 s, 698 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat > file4.txt
^C
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat > file4.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
^C
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat > file4.txt
Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
^C
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt bs=1 seek=8
94+0 records in
94+0 records out
94 bytes copied, 0.000201223 s, 467 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integer Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat > file4.txt
Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
^C
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt skip=2 seek=8
dd: file3.txt: cannot skip to specified offset
0+0 records in
0+0 records out
0 bytes copied, 0.000196825 s, 0.0 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integer sit amet nunc venenatis, tincidunt ex in, feugiat metus. Fusce elementum ligula
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt bs=1 skip=1 seek=3
93+0 records in
93+0 records out
93 bytes copied, 0.000171307 s, 543 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Intorem ipsum dolor sit amet, consectetur adipiscing elit. Etiam euismod magna ut lectus tempus
hackerman@WARMACHINE_mini:~/lab20$ nano file3.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum
hackerman@WARMACHINE_mini:~/lab20$ nano file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integer sit amet
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt bs=1 count=10 seek=3
10+0 records in
10+0 records out
10 bytes copied, 0.000123656 s, 80.9 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
IntLorem ipsuhackerman@WARMACHINE_mcat file3.txt
Lorem ipsum
hackerman@WARMACHINE_mini:~/lab20$ nano file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integer sit amet
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt ibs=1 obs=2 skip=1 seek=3
11+0 records in
5+1 records out
11 bytes copied, 7.3279e-05 s, 150 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
Lorem ipsum
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integeorem ipsum
hackerman@WARMACHINE_mini:~/lab20$ nano file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
Integer sit amet
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt conv=ucase
0+1 records in
0+1 records out
12 bytes copied, 0.000207686 s, 57.8 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
LOREM IPSUM
hackerman@WARMACHINE_mini:~/lab20$ dd if=file3.txt of=file4.txt conv=lcase
0+1 records in
0+1 records out
12 bytes copied, 0.000260977 s, 46.0 kB/s
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
lorem ipsum
hackerman@WARMACHINE_mini:~/lab20$ tar --totals
--create --verbose --file ar1.tar file1.txt file2.txt
file1.txt
file2.txt
Total bytes written: 10240 (10KiB, 16MiB/s)
hackerman@WARMACHINE_mini:~/lab20$ tar --totals --create --verbose --file ar2.tar file2.txt file3.txt
file2.txt
file3.txt
Total bytes written: 10240 (10KiB, 18MiB/s)
hackerman@WARMACHINE_mini:~/lab20$ tar -df ar1.tar
hackerman@WARMACHINE_mini:~/lab20$ tar -tf ar1.tar
file1.txt
file2.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
ar1.tar  ar2.tar  file1.txt  file2.txt  file3.txt  file4.txt  text.txt
hackerman@WARMACHINE_mini:~/lab20$ rm file1.txt
hackerman@WARMACHINE_mini:~/lab20$ rm file2.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
ar1.tar  ar2.tar  file3.txt  file4.txt  text.txt
hackerman@WARMACHINE_mini:~/lab20$ tar -xvf ar1.tar
file1.txt
file2.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
ar1.tar  ar2.tar  file1.txt  file2.txt  file3.txt  file4.txt  text.txt
hackerman@WARMACHINE_mini:~/lab20$
hackerman@WARMACHINE_mini:~/lab20$ tar --totals -cjvf ar4.tar.bz2 file3.txt
file3.txt
Total bytes written: 10240 (10KiB, 36MiB/s)
hackerman@WARMACHINE_mini:~/lab20$ rm file3.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
ar1.tar  ar2.tar  ar3.tar  ar4.tar.bz2  file1.txt  file2.txt  file4.txt  text.txt
hackerman@WARMACHINE_mini:~/lab20$ tar -xzvf ar4.tar.bz2

gzip: stdin: not in gzip format
tar: Child returned status 1
tar: Error is not recoverable: exiting now
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt  file2.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file1.txt
123
345
567
hackerman@WARMACHINE_mini:~/lab20$ cat file2.txt
123
467
890
hackerman@WARMACHINE_mini:~/lab20$ cmp file1.txt file2.txt
file1.txt file2.txt differ: byte 5, line 2
hackerman@WARMACHINE_mini:~/lab20$ cmp -b file1.txt file2.txt
file1.txt file2.txt differ: byte 5, line 2 is  63 3  64 4
hackerman@WARMACHINE_mini:~/lab20$ wc -c file1.txt
12 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ wc -l file1.txt
3 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ wc -w file1.txt
3 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ diff -q file1.txt file2.txt
Files file1.txt and file2.txt differ
hackerman@WARMACHINE_mini:~/lab20$ diff -y file1.txt file2.txt
123                                            123
345                                                  |  467
567                                                  |  890
hackerman@WARMACHINE_mini:~/lab20$ grep -c op file1.txt
0
hackerman@WARMACHINE_mini:~/lab20$ grep -c 23 file1.txt
1
hackerman@WARMACHINE_mini:~/lab20$ grep -n 23 fi
le1.txt
1:123
hackerman@WARMACHINE_mini:~/lab20$ touch file4.txt
hackerman@WARMACHINE_mini:~/lab20$ nano file3.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
abcdef
hackerman@WARMACHINE_mini:~/lab20$ tr "[:lower:]
" "[:upper:]" < file3.txt > file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
ABCDEF
hackerman@WARMACHINE_mini:~/lab20$ tr -cs "[:alpha:]" "[\n*]" < file3.txt > file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
abcdef
hackerman@WARMACHINE_mini:~/lab20$ tail file1.txt
123
345
567
hackerman@WARMACHINE_mini:~/lab20$ tail -n 2 fil
e1.txt
345
567
hackerman@WARMACHINE_mini:~/lab20$ uniq -c file1.txt
      1 123
      1 345
      1 567
hackerman@WARMACHINE_mini:~/lab20$ uniq -u file1.txt
123
345
567
hackerman@WARMACHINE_mini:~/lab20$ od -b file1.txt
0000000 061 062 063 012 063 064 065 012 065 066 067 012
0000014
hackerman@WARMACHINE_mini:~/lab20$ od -c file1.txt
0000000   1   2   3  \n   3   4   5  \n   5   6   7  \n
0000014
hackerman@WARMACHINE_mini:~/lab20$ sum file1.txt
21597     1
hackerman@WARMACHINE_mini:~/lab20$ gzip file1.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt.gz  file2.txt  file3.txt  file4.txt
hackerman@WARMACHINE_mini:~/lab20$ gzip -d file1
.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt  file2.txt  file3.txt  file4.txt
hackerman@WARMACHINE_mini:~/lab20$ bzip2 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt.bz2  file2.txt  file3.txt  file4.txt
hackerman@WARMACHINE_mini:~/lab20$ bzip2 -d file
1.txt.bz2
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt  file2.txt  file3.txt  file4.txt
hackerman@WARMACHINE_mini:~/lab20$ iconv -l
The following list contains all the coded character sets known.  This does
not necessarily mean that all combinations of these names can be used for
the FROM and TO command line parameters.  One coded character set can be
listed with several different names (aliases).

  437, 500, 500V1, 850, 851, 852, 855, 856, 857, 858, 860, 861, 862, 863, 864,
  865, 866, 866NAV, 869, 874, 904, 1026, 1046, 1047, 8859_1, 8859_2, 8859_3,
  8859_4, 8859_5, 8859_6, 8859_7, 8859_8, 8859_9, 10646-1:1993,
  10646-1:1993/UCS4, ANSI_X3.4-1968, ANSI_X3.4-1986, ANSI_X3.4,
  ANSI_X3.110-1983, ANSI_X3.110, ARABIC, ARABIC7, ARMSCII-8, ARMSCII8, ASCII,
  ASMO-708, ASMO_449, BALTIC, BIG-5, BIG-FIVE, BIG5-HKSCS, BIG5, BIG5HKSCS,
  BIGFIVE, BRF, BS_4730, CA, CN-BIG5, CN-GB, CN, CP-AR, CP-GR, CP-HU, CP037,
  CP038, CP273, CP274, CP275, CP278, CP280, CP281, CP282, CP284, CP285, CP290,
  CP297, CP367, CP420, CP423, CP424, CP437, CP500, CP737, CP770, CP771, CP772,
  CP773, CP774, CP775, CP803, CP813, CP819, CP850, CP851, CP852, CP855, CP856,
  CP857, CP858, CP860, CP861, CP862, CP863, CP864, CP865, CP866, CP866NAV,
  CP868, CP869, CP870, CP871, CP874, CP875, CP880, CP891, CP901, CP902, CP903,
  CP904, CP905, CP912, CP915, CP916, CP918, CP920, CP921, CP922, CP930, CP932,
  CP933, CP935, CP936, CP937, CP939, CP949, CP950, CP1004, CP1008, CP1025,
  CP1026, CP1046, CP1047, CP1070, CP1079, CP1081, CP1084, CP1089, CP1097,
  CP1112, CP1122, CP1123, CP1124, CP1125, CP1129, CP1130, CP1132, CP1133,
  CP1137, CP1140, CP1141, CP1142, CP1143, CP1144, CP1145, CP1146, CP1147,
  CP1148, CP1149, CP1153, CP1154, CP1155, CP1156, CP1157, CP1158, CP1160,
  CP1161, CP1162, CP1163, CP1164, CP1166, CP1167, CP1250, CP1251, CP1252,
  CP1253, CP1254, CP1255, CP1256, CP1257, CP1258, CP1282, CP1361, CP1364,
  CP1371, CP1388, CP1390, CP1399, CP4517, CP4899, CP4909, CP4971, CP5347,
  CP9030, CP9066, CP9448, CP10007, CP12712, CP16804, CPIBM861, CSA7-1, CSA7-2,
  CSASCII, CSA_T500-1983, CSA_T500, CSA_Z243.4-1985-1, CSA_Z243.4-1985-2,
  CSA_Z243.419851, CSA_Z243.419852, CSDECMCS, CSEBCDICATDE, CSEBCDICATDEA,
  CSEBCDICCAFR, CSEBCDICDKNO, CSEBCDICDKNOA, CSEBCDICES, CSEBCDICESA,
  CSEBCDICESS, CSEBCDICFISE, CSEBCDICFISEA, CSEBCDICFR, CSEBCDICIT, CSEBCDICPT,
  CSEBCDICUK, CSEBCDICUS, CSEUCKR, CSEUCPKDFMTJAPANESE, CSGB2312, CSHPROMAN8,
  CSIBM037, CSIBM038, CSIBM273, CSIBM274, CSIBM275, CSIBM277, CSIBM278,
  CSIBM280, CSIBM281, CSIBM284, CSIBM285, CSIBM290, CSIBM297, CSIBM420,
  CSIBM423, CSIBM424, CSIBM500, CSIBM803, CSIBM851, CSIBM855, CSIBM856,
  CSIBM857, CSIBM860, CSIBM863, CSIBM864, CSIBM865, CSIBM866, CSIBM868,
  CSIBM869, CSIBM870, CSIBM871, CSIBM880, CSIBM891, CSIBM901, CSIBM902,
  CSIBM903, CSIBM904, CSIBM905, CSIBM918, CSIBM921, CSIBM922, CSIBM930,
  CSIBM932, CSIBM933, CSIBM935, CSIBM937, CSIBM939, CSIBM943, CSIBM1008,
  CSIBM1025, CSIBM1026, CSIBM1097, CSIBM1112, CSIBM1122, CSIBM1123, CSIBM1124,
  CSIBM1129, CSIBM1130, CSIBM1132, CSIBM1133, CSIBM1137, CSIBM1140, CSIBM1141,
  CSIBM1142, CSIBM1143, CSIBM1144, CSIBM1145, CSIBM1146, CSIBM1147, CSIBM1148,
  CSIBM1149, CSIBM1153, CSIBM1154, CSIBM1155, CSIBM1156, CSIBM1157, CSIBM1158,
  CSIBM1160, CSIBM1161, CSIBM1163, CSIBM1164, CSIBM1166, CSIBM1167, CSIBM1364,
  CSIBM1371, CSIBM1388, CSIBM1390, CSIBM1399, CSIBM4517, CSIBM4899, CSIBM4909,
  CSIBM4971, CSIBM5347, CSIBM9030, CSIBM9066, CSIBM9448, CSIBM12712,
  CSIBM16804, CSIBM11621162, CSISO4UNITEDKINGDOM, CSISO10SWEDISH,
  CSISO11SWEDISHFORNAMES, CSISO14JISC6220RO, CSISO15ITALIAN, CSISO16PORTUGESE,
  CSISO17SPANISH, CSISO18GREEK7OLD, CSISO19LATINGREEK, CSISO21GERMAN,
  CSISO25FRENCH, CSISO27LATINGREEK1, CSISO49INIS, CSISO50INIS8,
  CSISO51INISCYRILLIC, CSISO58GB1988, CSISO60DANISHNORWEGIAN,
  CSISO60NORWEGIAN1, CSISO61NORWEGIAN2, CSISO69FRENCH, CSISO84PORTUGUESE2,
  CSISO85SPANISH2, CSISO86HUNGARIAN, CSISO88GREEK7, CSISO89ASMO449, CSISO90,
  CSISO92JISC62991984B, CSISO99NAPLPS, CSISO103T618BIT, CSISO111ECMACYRILLIC,
  CSISO121CANADIAN1, CSISO122CANADIAN2, CSISO139CSN369103, CSISO141JUSIB1002,
  CSISO143IECP271, CSISO150, CSISO150GREEKCCITT, CSISO151CUBA,
  CSISO153GOST1976874, CSISO646DANISH, CSISO2022CN, CSISO2022JP, CSISO2022JP2,
  CSISO2022KR, CSISO2033, CSISO5427CYRILLIC, CSISO5427CYRILLIC1981,
  CSISO5428GREEK, CSISO10367BOX, CSISOLATIN1, CSISOLATIN2, CSISOLATIN3,
  CSISOLATIN4, CSISOLATIN5, CSISOLATIN6, CSISOLATINARABIC, CSISOLATINCYRILLIC,
  CSISOLATINGREEK, CSISOLATINHEBREW, CSKOI8R, CSKSC5636, CSMACINTOSH,
  CSNATSDANO, CSNATSSEFI, CSN_369103, CSPC8CODEPAGE437, CSPC775BALTIC,
  CSPC850MULTILINGUAL, CSPC858MULTILINGUAL, CSPC862LATINHEBREW, CSPCP852,
  CSSHIFTJIS, CSUCS4, CSUNICODE, CSWINDOWS31J, CUBA, CWI-2, CWI, CYRILLIC, DE,
  DEC-MCS, DEC, DECMCS, DIN_66003, DK, DS2089, DS_2089, E13B, EBCDIC-AT-DE-A,
  EBCDIC-AT-DE, EBCDIC-BE, EBCDIC-BR, EBCDIC-CA-FR, EBCDIC-CP-AR1,
  EBCDIC-CP-AR2, EBCDIC-CP-BE, EBCDIC-CP-CA, EBCDIC-CP-CH, EBCDIC-CP-DK,
  EBCDIC-CP-ES, EBCDIC-CP-FI, EBCDIC-CP-FR, EBCDIC-CP-GB, EBCDIC-CP-GR,
  EBCDIC-CP-HE, EBCDIC-CP-IS, EBCDIC-CP-IT, EBCDIC-CP-NL, EBCDIC-CP-NO,
  EBCDIC-CP-ROECE, EBCDIC-CP-SE, EBCDIC-CP-TR, EBCDIC-CP-US, EBCDIC-CP-WT,
  EBCDIC-CP-YU, EBCDIC-CYRILLIC, EBCDIC-DK-NO-A, EBCDIC-DK-NO, EBCDIC-ES-A,
  EBCDIC-ES-S, EBCDIC-ES, EBCDIC-FI-SE-A, EBCDIC-FI-SE, EBCDIC-FR,
  EBCDIC-GREEK, EBCDIC-INT, EBCDIC-INT1, EBCDIC-IS-FRISS, EBCDIC-IT,
  EBCDIC-JP-E, EBCDIC-JP-KANA, EBCDIC-PT, EBCDIC-UK, EBCDIC-US, EBCDICATDE,
  EBCDICATDEA, EBCDICCAFR, EBCDICDKNO, EBCDICDKNOA, EBCDICES, EBCDICESA,
  EBCDICESS, EBCDICFISE, EBCDICFISEA, EBCDICFR, EBCDICISFRISS, EBCDICIT,
  EBCDICPT, EBCDICUK, EBCDICUS, ECMA-114, ECMA-118, ECMA-128, ECMA-CYRILLIC,
  ECMACYRILLIC, ELOT_928, ES, ES2, EUC-CN, EUC-JISX0213, EUC-JP-MS, EUC-JP,
  EUC-KR, EUC-TW, EUCCN, EUCJP-MS, EUCJP-OPEN, EUCJP-WIN, EUCJP, EUCKR, EUCTW,
  FI, FR, GB, GB2312, GB13000, GB18030, GBK, GB_1988-80, GB_198880,
  GEORGIAN-ACADEMY, GEORGIAN-PS, GOST_19768-74, GOST_19768, GOST_1976874,
  GREEK-CCITT, GREEK, GREEK7-OLD, GREEK7, GREEK7OLD, GREEK8, GREEKCCITT,
  HEBREW, HP-GREEK8, HP-ROMAN8, HP-ROMAN9, HP-THAI8, HP-TURKISH8, HPGREEK8,
  HPROMAN8, HPROMAN9, HPTHAI8, HPTURKISH8, HU, IBM-803, IBM-856, IBM-901,
  IBM-902, IBM-921, IBM-922, IBM-930, IBM-932, IBM-933, IBM-935, IBM-937,
  IBM-939, IBM-943, IBM-1008, IBM-1025, IBM-1046, IBM-1047, IBM-1097, IBM-1112,
  IBM-1122, IBM-1123, IBM-1124, IBM-1129, IBM-1130, IBM-1132, IBM-1133,
  IBM-1137, IBM-1140, IBM-1141, IBM-1142, IBM-1143, IBM-1144, IBM-1145,
  IBM-1146, IBM-1147, IBM-1148, IBM-1149, IBM-1153, IBM-1154, IBM-1155,
  IBM-1156, IBM-1157, IBM-1158, IBM-1160, IBM-1161, IBM-1162, IBM-1163,
  IBM-1164, IBM-1166, IBM-1167, IBM-1364, IBM-1371, IBM-1388, IBM-1390,
  IBM-1399, IBM-4517, IBM-4899, IBM-4909, IBM-4971, IBM-5347, IBM-9030,
  IBM-9066, IBM-9448, IBM-12712, IBM-16804, IBM037, IBM038, IBM256, IBM273,
  IBM274, IBM275, IBM277, IBM278, IBM280, IBM281, IBM284, IBM285, IBM290,
  IBM297, IBM367, IBM420, IBM423, IBM424, IBM437, IBM500, IBM775, IBM803,
  IBM813, IBM819, IBM848, IBM850, IBM851, IBM852, IBM855, IBM856, IBM857,
  IBM858, IBM860, IBM861, IBM862, IBM863, IBM864, IBM865, IBM866, IBM866NAV,
  IBM868, IBM869, IBM870, IBM871, IBM874, IBM875, IBM880, IBM891, IBM901,
  IBM902, IBM903, IBM904, IBM905, IBM912, IBM915, IBM916, IBM918, IBM920,
  IBM921, IBM922, IBM930, IBM932, IBM933, IBM935, IBM937, IBM939, IBM943,
  IBM1004, IBM1008, IBM1025, IBM1026, IBM1046, IBM1047, IBM1089, IBM1097,
  IBM1112, IBM1122, IBM1123, IBM1124, IBM1129, IBM1130, IBM1132, IBM1133,
  IBM1137, IBM1140, IBM1141, IBM1142, IBM1143, IBM1144, IBM1145, IBM1146,
  IBM1147, IBM1148, IBM1149, IBM1153, IBM1154, IBM1155, IBM1156, IBM1157,
  IBM1158, IBM1160, IBM1161, IBM1162, IBM1163, IBM1164, IBM1166, IBM1167,
  IBM1364, IBM1371, IBM1388, IBM1390, IBM1399, IBM4517, IBM4899, IBM4909,
  IBM4971, IBM5347, IBM9030, IBM9066, IBM9448, IBM12712, IBM16804, IEC_P27-1,
  IEC_P271, INIS-8, INIS-CYRILLIC, INIS, INIS8, INISCYRILLIC, ISIRI-3342,
  ISIRI3342, ISO-2022-CN-EXT, ISO-2022-CN, ISO-2022-JP-2, ISO-2022-JP-3,
  ISO-2022-JP, ISO-2022-KR, ISO-8859-1, ISO-8859-2, ISO-8859-3, ISO-8859-4,
  ISO-8859-5, ISO-8859-6, ISO-8859-7, ISO-8859-8, ISO-8859-9, ISO-8859-9E,
  ISO-8859-10, ISO-8859-11, ISO-8859-13, ISO-8859-14, ISO-8859-15, ISO-8859-16,
  ISO-10646, ISO-10646/UCS2, ISO-10646/UCS4, ISO-10646/UTF-8, ISO-10646/UTF8,
  ISO-CELTIC, ISO-IR-4, ISO-IR-6, ISO-IR-8-1, ISO-IR-9-1, ISO-IR-10, ISO-IR-11,
  ISO-IR-14, ISO-IR-15, ISO-IR-16, ISO-IR-17, ISO-IR-18, ISO-IR-19, ISO-IR-21,
  ISO-IR-25, ISO-IR-27, ISO-IR-37, ISO-IR-49, ISO-IR-50, ISO-IR-51, ISO-IR-54,
  ISO-IR-55, ISO-IR-57, ISO-IR-60, ISO-IR-61, ISO-IR-69, ISO-IR-84, ISO-IR-85,
  ISO-IR-86, ISO-IR-88, ISO-IR-89, ISO-IR-90, ISO-IR-92, ISO-IR-98, ISO-IR-99,
  ISO-IR-100, ISO-IR-101, ISO-IR-103, ISO-IR-109, ISO-IR-110, ISO-IR-111,
  ISO-IR-121, ISO-IR-122, ISO-IR-126, ISO-IR-127, ISO-IR-138, ISO-IR-139,
  ISO-IR-141, ISO-IR-143, ISO-IR-144, ISO-IR-148, ISO-IR-150, ISO-IR-151,
  ISO-IR-153, ISO-IR-155, ISO-IR-156, ISO-IR-157, ISO-IR-166, ISO-IR-179,
  ISO-IR-193, ISO-IR-197, ISO-IR-199, ISO-IR-203, ISO-IR-209, ISO-IR-226,
  ISO/TR_11548-1, ISO646-CA, ISO646-CA2, ISO646-CN, ISO646-CU, ISO646-DE,
  ISO646-DK, ISO646-ES, ISO646-ES2, ISO646-FI, ISO646-FR, ISO646-FR1,
  ISO646-GB, ISO646-HU, ISO646-IT, ISO646-JP-OCR-B, ISO646-JP, ISO646-KR,
  ISO646-NO, ISO646-NO2, ISO646-PT, ISO646-PT2, ISO646-SE, ISO646-SE2,
  ISO646-US, ISO646-YU, ISO2022CN, ISO2022CNEXT, ISO2022JP, ISO2022JP2,
  ISO2022KR, ISO6937, ISO8859-1, ISO8859-2, ISO8859-3, ISO8859-4, ISO8859-5,
  ISO8859-6, ISO8859-7, ISO8859-8, ISO8859-9, ISO8859-9E, ISO8859-10,
  ISO8859-11, ISO8859-13, ISO8859-14, ISO8859-15, ISO8859-16, ISO11548-1,
  ISO88591, ISO88592, ISO88593, ISO88594, ISO88595, ISO88596, ISO88597,
  ISO88598, ISO88599, ISO88599E, ISO885910, ISO885911, ISO885913, ISO885914,
  ISO885915, ISO885916, ISO_646.IRV:1991, ISO_2033-1983, ISO_2033,
  ISO_5427-EXT, ISO_5427, ISO_5427:1981, ISO_5427EXT, ISO_5428, ISO_5428:1980,
  ISO_6937-2, ISO_6937-2:1983, ISO_6937, ISO_6937:1992, ISO_8859-1,
  ISO_8859-1:1987, ISO_8859-2, ISO_8859-2:1987, ISO_8859-3, ISO_8859-3:1988,
  ISO_8859-4, ISO_8859-4:1988, ISO_8859-5, ISO_8859-5:1988, ISO_8859-6,
  ISO_8859-6:1987, ISO_8859-7, ISO_8859-7:1987, ISO_8859-7:2003, ISO_8859-8,
  ISO_8859-8:1988, ISO_8859-9, ISO_8859-9:1989, ISO_8859-9E, ISO_8859-10,
  ISO_8859-10:1992, ISO_8859-14, ISO_8859-14:1998, ISO_8859-15,
  ISO_8859-15:1998, ISO_8859-16, ISO_8859-16:2001, ISO_9036, ISO_10367-BOX,
  ISO_10367BOX, ISO_11548-1, ISO_69372, IT, JIS_C6220-1969-RO,
  JIS_C6229-1984-B, JIS_C62201969RO, JIS_C62291984B, JOHAB, JP-OCR-B, JP, JS,
  JUS_I.B1.002, KOI-7, KOI-8, KOI8-R, KOI8-RU, KOI8-T, KOI8-U, KOI8, KOI8R,
  KOI8U, KSC5636, L1, L2, L3, L4, L5, L6, L7, L8, L10, LATIN-9, LATIN-GREEK-1,
  LATIN-GREEK, LATIN1, LATIN2, LATIN3, LATIN4, LATIN5, LATIN6, LATIN7, LATIN8,
  LATIN9, LATIN10, LATINGREEK, LATINGREEK1, MAC-CENTRALEUROPE, MAC-CYRILLIC,
  MAC-IS, MAC-SAMI, MAC-UK, MAC, MACCYRILLIC, MACINTOSH, MACIS, MACUK,
  MACUKRAINIAN, MIK, MS-ANSI, MS-ARAB, MS-CYRL, MS-EE, MS-GREEK, MS-HEBR,
  MS-MAC-CYRILLIC, MS-TURK, MS932, MS936, MSCP949, MSCP1361, MSMACCYRILLIC,
  MSZ_7795.3, MS_KANJI, NAPLPS, NATS-DANO, NATS-SEFI, NATSDANO, NATSSEFI,
  NC_NC0010, NC_NC00-10, NC_NC00-10:81, NF_Z_62-010, NF_Z_62-010_(1973),
  NF_Z_62-010_1973, NF_Z_62010, NF_Z_62010_1973, NO, NO2, NS_4551-1, NS_4551-2,
  NS_45511, NS_45512, OS2LATIN1, OSF00010001, OSF00010002, OSF00010003,
  OSF00010004, OSF00010005, OSF00010006, OSF00010007, OSF00010008, OSF00010009,
  OSF0001000A, OSF00010020, OSF00010100, OSF00010101, OSF00010102, OSF00010104,
  OSF00010105, OSF00010106, OSF00030010, OSF0004000A, OSF0005000A, OSF05010001,
  OSF100201A4, OSF100201A8, OSF100201B5, OSF100201F4, OSF100203B5, OSF1002011C,
  OSF1002011D, OSF1002035D, OSF1002035E, OSF1002035F, OSF1002036B, OSF1002037B,
  OSF10010001, OSF10010004, OSF10010006, OSF10020025, OSF10020111, OSF10020115,
  OSF10020116, OSF10020118, OSF10020122, OSF10020129, OSF10020352, OSF10020354,
  OSF10020357, OSF10020359, OSF10020360, OSF10020364, OSF10020365, OSF10020366,
  OSF10020367, OSF10020370, OSF10020387, OSF10020388, OSF10020396, OSF10020402,
  OSF10020417, PT, PT2, PT154, R8, R9, RK1048, ROMAN8, ROMAN9, RUSCII, SE, SE2,
  SEN_850200_B, SEN_850200_C, SHIFT-JIS, SHIFTJISX0213, SHIFT_JIS,
  SHIFT_JISX0213, SJIS-OPEN, SJIS-WIN, SJIS, SS636127, STRK1048-2002,
  ST_SEV_358-88, T.61-8BIT, T.61, T.618BIT, TCVN-5712, TCVN, TCVN5712-1,
  TCVN5712-1:1993, THAI8, TIS-620, TIS620-0, TIS620.2529-1, TIS620.2533-0,
  TIS620, TS-5881, TSCII, TURKISH8, UCS-2, UCS-2BE, UCS-2LE, UCS-4, UCS-4BE,
  UCS-4LE, UCS2, UCS4, UHC, UJIS, UK, UNICODE, UNICODEBIG, UNICODELITTLE,
  US-ASCII, US, UTF-7, UTF-8, UTF-16, UTF-16BE, UTF-16LE, UTF-32, UTF-32BE,
  UTF-32LE, UTF7, UTF8, UTF16, UTF16BE, UTF16LE, UTF32, UTF32BE, UTF32LE,
  VISCII, WCHAR_T, WIN-SAMI-2, WINBALTRIM, WINDOWS-31J, WINDOWS-874,
  WINDOWS-936, WINDOWS-1250, WINDOWS-1251, WINDOWS-1252, WINDOWS-1253,
  WINDOWS-1254, WINDOWS-1255, WINDOWS-1256, WINDOWS-1257, WINDOWS-1258,
  WINSAMI2, WS2, YU
hackerman@WARMACHINE_mini:~/lab20$  iconv -f ISO-8859-1 -t UTF-8//TRANSLIT file3.txt -o file4.tx
t
hackerman@WARMACHINE_mini:~/lab20$ ls
file1.txt  file2.txt  file3.txt  file4.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file3.txt
abcdef
hackerman@WARMACHINE_mini:~/lab20$ cat file4.txt
abcdef
hackerman@WARMACHINE_mini:~/lab20$ diff -u file1.txt file2.txt > differ.diff
hackerman@WARMACHINE_mini:~/lab20$ ls
differ.diff  file2.txt  file4.txt
file1.txt    file3.txt
hackerman@WARMACHINE_mini:~/lab20$ patch < differ.diff
patching file file1.txt
hackerman@WARMACHINE_mini:~/lab20$ cat file1.txt
123
467
890
hackerman@WARMACHINE_mini:~/lab20$ cat file2.txt
123
467
890
hackerman@WARMACHINE_mini:~/lab20$ cd ~
hackerman@WARMACHINE_mini:~$ ls
'Untitled Document 1'
 a.out
 cw
 lab20
 lab_fundamentals_of_computer_science
 labs
 nam
 nam:Zone.Identifier
hackerman@WARMACHINE_mini:~$ du -s lab20
24      lab20
hackerman@WARMACHINE_mini:~$ du -sh
756K    .
hackerman@WARMACHINE_mini:~/lab20$ file -i file1.txt
file1.txt: text/plain; charset=us-ascii
hackerman@WARMACHINE_mini:~/lab20$ bzip2 file1.txt
hackerman@WARMACHINE_mini:~/lab20$ ls
differ.diff    file2.txt  file4.txt
file1.txt.bz2  file3.txt
hackerman@WARMACHINE_mini:~/lab20$ file -z file1.txt.bz2
file1.txt.bz2: ASCII text (bzip2 compressed data, block size = 900k)
hackerman@WARMACHINE_mini:~/lab20$ ls
differ.diff    file2.txt  file4.txt
file1.txt.bz2  file3.txt
hackerman@WARMACHINE_mini:~/lab20$ touch file5.txt
hackerman@WARMACHINE_mini:~/lab20$ ls -l file5.txt
-rw-r--r-- 1 hackerman hackerman 0 Mar 11 16:52 file5.txt
hackerman@WARMACHINE_mini:~/lab20$ touch file5.txt
hackerman@WARMACHINE_mini:~/lab20$ ls -l file5.txt
-rw-r--r-- 1 hackerman hackerman 0 Mar 11 16:53 file5.txt
hackerman@WARMACHINE_mini:~/lab20$
hackerman@WARMACHINE_mini:~/lab20$ ls
babochka.png
babochka.png:Zone.Identifier
differ.diff
file1.txt.bz2
file2.txt
file3.txt
file4.txt
file5.txt
vozdushnyye-shary.png
vozdushnyye-shary.png:Zone.Identifier
hackerman@WARMACHINE_mini:~/lab20$ find . -name "*.png"
./babochka.png
./vozdushnyye-shary.png
hackerman@WARMACHINE_mini:~/lab20$ cd ~
hackerman@WARMACHINE_mini:~$ ls
'Untitled Document 1'
 a.out
 cw
 lab20
 lab_fundamentals_of_computer_science
 labs
 nam
 nam:Zone.Identifier
hackerman@WARMACHINE_mini:~$ find . -type d
.
./lab_fundamentals_of_computer_science
./lab_fundamentals_of_computer_science/Get-Started--With-Unix
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/branches
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/hooks
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects/pack
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects/1d
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects/info
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects/b1
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/objects/b9
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/info
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/refs
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/refs/tags
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/refs/remotes
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/refs/remotes/origin
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/refs/heads
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/logs
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/logs/refs
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/logs/refs/remotes
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/logs/refs/remotes/origin
./lab_fundamentals_of_computer_science/Get-Started--With-Unix/.git/logs/refs/heads
./.landscape
./.cache
./cw
./lab20
./.config
./.config/dconf
./.config/enchant
./.config/gedit
./.config/gtk-3.0
./.config/ibus
./.config/ibus/bus
./.ssh
./labs
./nam
./nam/__MACOSX
./.local
./.local/share
./.local/share/nano
./.local/share/gedit
./.dbus
./.dbus/session-bus
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 03.03.23 | 15:57 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы
Были изучены методы работы с файлами посредством утилит OC UNIX.

