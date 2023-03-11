# Отчёт по лабораторной работе №20 по курсу “Алгоритмы и структуры данных”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 21</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «3» <ins>марта</ins> <ins>2023</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «4» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins> </ins>

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
| dd | dd if=<путь_к_файлy> of=<куда_копировать> [другие_параметры] |bs - указывает сколько байт читать и записывать за один раз; count - скопировать указанное количество блоков, размер одного блока указывается в параметре bs; conv - применить фильтры к потоку данных; ibs - читать указанное количество байт за раз; obs - записывать указанное количество байт за раз; seek - пропустить указанное количество байт в начале устройства для чтения; skip - пропустить указанное количество байт в начале устройства вывода; | Команда служит для копирования, конвертации файлов, а так же для чтения данных |
| tar | tar [опции] <архив>.tar <файлы_для_архивации> | -A 	(--concatenate) 	присоединить существующий архив к другому; -c 	(--create) создать новый архив; -d 	(--diff --delete) 	проверить различие между архивам, удалить из существующего архива файл; -r 	(--append) 	присоединить файлы к концу архива; -t 	(--list) 	сформировать список содержимого архива; -u 	(--update) 	обновить архив более новыми файлами с тем же именем; -x 	(--extract) 	извлечь файлы из архива | Архиватор |


### 7. Сценарий выполнения работы

1. ```cmp``` – сравнивает два файла и, если они различаются, сообщает о первом байте и строке, где было обнаружено различие
2. ```comm``` – читает файл1 и файл2, которые должны быть предварительно лексически отсортированы, и генерирует вывод, состоящий из трёх колонок текста: строки, найденные только в файле файл1; строки, найденные только в файле файл2; и строки, общие для обоих файлов
3. ```wc``` – вывод числа переводов строк, слов и байт для каждого указанного файла и итоговую строку, если было задано несколько файлов
4. ```dd``` – копирование и конвертация файлов
5. ```diff``` – утилита сравнения файлов, выводящая разницу между двумя файлами
6. ```grep``` – утилита для поиска наборов данных в виде обычного текста строк, соответствующих регулярному выражению
7. ```join``` – объединение строк двух упорядоченных текстовых файлов на основе наличия общего поля
8. ```sort``` – вывод сортированного слияния указанных файлов на стандартный вывод с использованием установленной в среде локали
9. ```tail``` – вывод нескольких (по умолчанию 10) последних строк из файла
10. ```tee``` – выводит на экран, или же перенаправляет выходной поток команды и копирует его содержимое в файл или в переменную
11. ```tr``` – утилита для преобразования символов
12. ```uniq``` – вывод или отфильтр повторяющиеся строки в отсортированном файле
13. ```od``` – вывод дампа файла
14. ```sum``` - вывод контрольной суммы каждого файла, а также количество блоков, которые эти файлы занимают на запоминающем устройстве
15. ```cut``` – извлечени разделов из каждой строки ввода
16. ```nroff``` – программа форматирования текста
17. ```vim``` – текстовый редактор
18. ```mc``` –  файловый менеджер с текстовым интерфейсом
19. ```tar``` – создание и упаковка архива
20. ```gzip``` – утилита сжатия и декомпрессии файлов
21. ```ed``` – текстовый редактор
22. ```awk``` – си-подобный сценарный язык построчного разбора и обработки входного потока (например, текстового файла) по заданным шаблонам (регулярным выражениям)
23. ```sed``` – потоковый текстовый редактор (а также язык программирования), применяющий различные предопределённые текстовые преобразования к последовательному потоку текстовых данных
24. ```bzip2``` – сжатие, распаковка данных
25. ```head``` – вывод первых n строк из файла
26. ```icnov``` – преобразует текст из одной кодировки в другую
27. ```patch``` – утилита для переноса правок между разными версиями текстовых файлов
28. ```md5sum``` – подсчет и проверка контрольных сумм файлов в соответствии со 128-битным алгоритмом MD5
29. ```du``` – оценка занимаемого файлового пространства
30. ```file``` – определяет тип файла
31. ```touch``` – создание пустого файла, если его нет. Если файл есть, то команда установит дату обращения в текущий момент времени 
32. ```find``` – утилита поиска файлов по имени и другим свойствам
33. ```xargs``` – утилита для формирования списка аргументов и выполнения команды
34. ```df``` – оказывает список всех файловых систем по именам устройств, сообщает их размер, занятое и свободное пространство и точки монтирования
35. ```paste``` – утилита командной, которая используется для горизонтального соединения файлов (параллельное слияние) путем вывода строк, состоящих из последовательно соответствующих строк каждого указанного файла, разделенных символами табуляции, на стандартный вывод
36. ```cpp``` – препроцессор C
37. ```indent``` –  утилита, которая переформатирует код C и C++ в определяемый пользователем стиль отступа и стиль кодирования
38. ```split``` – разделение компьютерного файла на два или более файлов меньшего размера
39. ```mktemp``` – создает уникальное временное имя файлу                      

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
 ```

### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 03.03.23 | 15:57 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы
Были изучены методы работы с файлами посредством утилит OC UNIX.

