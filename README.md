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
hackerman@WARMACHINE_mini:~$ scp WARMACHINE_mini: ~/file.txt /home/nikolay/file1.txt
/home/nikolay/file1.txt: No such file or directory
hackerman@WARMACHINE_mini:~$ ^C
hackerman@WARMACHINE_mini:~$ scp WARMACHINE_mini: /home/hackerman/file.txt .
The authenticity of host 'warmachine_mini (127.0.1.1)' can't be established.
ECDSA key fingerprint is SHA256:yGKWvpuMZokteD9NW3Q5Iy+ofR8tzxHJxv34BFFnNWw.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added 'warmachine_mini' (ECDSA) to the list of known hosts.
hackerman@warmachine_mini's password: 
scp: .: not a regular file
cp: '/home/hackerman/file.txt' and './file.txt' are the same file
hackerman@WARMACHINE_mini:~$ scp WARMACHINE_mini: /home/hackerman/file.txt nikolay/file2.txt
nikolay/file2.txt: No such file or directory
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
nikolay@nikolay-VirtualBox:~$ scp hackerman@172.23.24.180: file.txt  /home/nikolay
hackerman@172.23.24.180's password: 
scp: .: not a regular file
cp: не удалось выполнить stat для 'file.txt': Нет такого файла или каталога
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
nikolay@nikolay-VirtualBox:~$ move file.txt dir2

Команда «move» не найдена. Возможно, вы имели в виду:

  command 'movx' from snap movx (2.0.1)
  command 'mote' from snap mote (2.0.5)
  command 'love' from snap love (11.2+pkg-d332)
  command 'mmove' from deb mtools (4.0.24-1)
  command 'love' from deb love (11.3-1)
  command 'lmove' from deb suck (4.3.4-1)
  command 'fmove' from deb embassy-phylip (3.69.660-3)
  command 'more' from deb util-linux (2.34-0.1ubuntu9.3)
  command 'jove' from deb jove (4.17.2.7-1)

See 'snap info <snapname>' for additional versions.

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
