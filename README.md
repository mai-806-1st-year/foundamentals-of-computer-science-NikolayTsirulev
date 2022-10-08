# Отчёт по лабораторной работе №3 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирочвич, № по списку 23</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «8» <ins>октября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «8» <ins>октября</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Операционная среда OC UNIX
## 2. Цель работы
Изучение различных команд для взаимодействия с удалённой машиной.
## 3. Задание (вариант № —)
Изучить и применить на практике команды для установки соединения с удалённой машиной, а так же команды для обмена файлами между локальной машиной и сервером.
### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 8192 MiB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
1. Пдключиться к удаленной машине.
2. Создать файл ти директорию и и переместить их с одной машины на другую.
3. Архивировать и разархивировать папку.
4. Перекодировать файл.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
ssh hackerman@172.23.24.180
mkdir dir1
touch file.txt
logout
scp hackerman@172.23.24.180:~/file.txt
scp -r hackerman@172.23.24.180:dir1
mkdir dir2
mv file.txt dir2
tar -cf file_archive.tar dir2
ls
tar -xf file_archive.tar
nano file.txt
iconv -f gb2312 -t utf-8 file.txt
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя</b> ________________
## 8. Распечатка протокола 
```
nikolay@nikolay-VirtualBox:~$ ssh hackerman@172.23.24.180
The authenticity of host '172.23.24.180 (172.23.24.180)' can't be established.
ECDSA key fingerprint is SHA256:yGKWvpuMZokteD9NW3Q5Iy+ofR8tzxHJxv34BFFnNWw.
Are you sure you want to continue connecting (yes/no/[fingerprint])? y
Please type 'yes', 'no' or the fingerprint: yes
Warning: Permanently added '172.23.24.180' (ECDSA) to the list of known hosts.
hackerman@172.23.24.180's password: 
Welcome to Ubuntu 20.04 LTS (GNU/Linux 5.10.16.3-microsoft-standard-WSL2 x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Sat Oct  8 10:37:57 MSK 2022

  System load:  0.0                Processes:             18
  Usage of /:   0.8% of 250.98GB   Users logged in:       0
  Memory usage: 8%                 IPv4 address for eth0: 172.23.24.180
  Swap usage:   0%


499 updates can be installed immediately.
312 of these updates are security updates.
To see these additional updates run: apt list --upgradable

New release '22.04.1 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


Last login: Sat Oct  8 10:26:57 2022 from 127.0.0.1
hackerman@WARMACHINE_mini:~$ mkdir dir1
hackerman@WARMACHINE_mini:~$ touch file.txt
hackerman@WARMACHINE_mini:~$ logout
Connection to 172.23.24.180 closed.
nikolay@nikolay-VirtualBox:~$ scp WARMACHINE_mini: /home/hackerman/file.txt .
ssh: Could not resolve hostname warmachine_mini: Temporary failure in name resolution
cp: не удалось выполнить stat для '/home/hackerman/file.txt': Нет такого файла или каталога
nikolay@nikolay-VirtualBox:~$ touch f
nikolay@nikolay-VirtualBox:~$ ls
 f       Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
nikolay@nikolay-VirtualBox:~$ scp f warmachine_mini:
ssh: Could not resolve hostname warmachine_mini: Temporary failure in name resolution
lost connection
nikolay@nikolay-VirtualBox:~$ scp f WARMACHINE_mini:
ssh: Could not resolve hostname warmachine_mini: Temporary failure in name resolution
lost connection
nikolay@nikolay-VirtualBox:~$ ssh hackerman@WARMACHINE_mini
ssh: Could not resolve hostname warmachine_mini: Temporary failure in name resolution
nikolay@nikolay-VirtualBox:~$ ssh hackerman@172.23.24.180
hackerman@172.23.24.180's password: 
Welcome to Ubuntu 20.04 LTS (GNU/Linux 5.10.16.3-microsoft-standard-WSL2 x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Sat Oct  8 11:24:31 MSK 2022

  System load:  0.0                Processes:             18
  Usage of /:   0.8% of 250.98GB   Users logged in:       0
  Memory usage: 8%                 IPv4 address for eth0: 172.23.24.180
  Swap usage:   0%


499 updates can be installed immediately.
312 of these updates are security updates.
To see these additional updates run: apt list --upgradable

New release '22.04.1 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


Last login: Sat Oct  8 10:37:57 2022 from 172.23.16.1
hackerman@WARMACHINE_mini:~$ logout
Connection to 172.23.24.180 closed.
nikolay@nikolay-VirtualBox:~$ mkdir dir11
nikolay@nikolay-VirtualBox:~$ scp hackerman@172.23.24.180: f
hackerman@172.23.24.180's password: 
scp: .: not a regular file
nikolay@nikolay-VirtualBox:~$ scp hackerman@172.23.24.180: /home/hackerman/file.txt /home/nikolay
hackerman@172.23.24.180's password: 
scp: .: not a regular file
cp: не удалось выполнить stat для '/home/hackerman/file.txt': Нет такого файла или каталога
nikolay@nikolay-VirtualBox:~$ scp hackerman@172.23.24.180: file  /home/nikolay
hackerman@172.23.24.180's password: 
scp: .: not a regular file
cp: не удалось выполнить stat для 'file': Нет такого файла или каталога
nikolay@nikolay-VirtualBox:~$ scp hackerman@172.23.24.180:~/file.txt .
hackerman@172.23.24.180's password: 
file.txt                                     100%    0     0.0KB/s   00:00    
nikolay@nikolay-VirtualBox:~$ scp -r hackerman@172.23.24.180:dir1
usage: scp [-346BCpqrTv] [-c cipher] [-F ssh_config] [-i identity_file]
            [-J destination] [-l limit] [-o ssh_option] [-P port]
            [-S program] source ... target
nikolay@nikolay-VirtualBox:~$ ls
 dir11   file.txt   Документы   Изображения   Общедоступные   Шаблоны
 f       Видео      Загрузки    Музыка       'Рабочий стол'
nikolay@nikolay-VirtualBox:~$ scp -r hackerman@172.23.24.180:dir1
usage: scp [-346BCpqrTv] [-c cipher] [-F ssh_config] [-i identity_file]
            [-J destination] [-l limit] [-o ssh_option] [-P port]
            [-S program] source ... target
nikolay@nikolay-VirtualBox:~$ mkdir dir2
nikolay@nikolay-VirtualBox:~$ mv file.txt dir2
nikolay@nikolay-VirtualBox:~$ tar -cf file_archive.tar dir2
nikolay@nikolay-VirtualBox:~$ ls
 dir11   file_archive.tar   Загрузки      Общедоступные
 dir2    Видео              Изображения  'Рабочий стол'
 f       Документы          Музыка        Шаблоны
nikolay@nikolay-VirtualBox:~$ tar -xf file_archive.tar
nikolay@nikolay-VirtualBox:~$ ls
 dir11   file_archive.tar   Загрузки      Общедоступные
 dir2    Видео              Изображения  'Рабочий стол'
 f       Документы          Музыка        Шаблоны
nikolay@nikolay-VirtualBox:~$ nano file.txt
nikolay@nikolay-VirtualBox:~$ iconv -f gb2312 -t utf-8 file.txt
1234567fnerbvef
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 08.10.22 | 12:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы 
## 11. Выводы
Было выяснено, что в OC UNIX есть множество полезных утилит, которые облегчают работу в этой системе. Были изучены некоторые из них. Освоены навигация в файловой системе, создание, удаление файлов и директорий. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
