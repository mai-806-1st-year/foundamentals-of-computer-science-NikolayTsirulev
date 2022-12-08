# Отчёт по лабораторной работе №13 по курсу “Фундаментальная информатика”

<b>Студент группы:</b> <ins>М80-108Б-22 Цирулев Николай Владимирович, № по списку 23</ins> 

<b>Контакты e-mail:</b> <ins>mrcirniko@gmail.com</ins>

<b>Работа выполнена:</b> «3» <ins>декабря</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins> </ins>

<b>Отчет сдан</b> «3» <ins>декабря</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> </ins>

<b>Подпись преподавателя:</b> ________________

### 1. Тема
__Множества.__

### 2. Цель работы
__Научиться составлять программы по обработке множества слов.__

### 3. Задание (Вариант 22)
__Проверить, есть ли слово, содержащее ровно одну согласную.__

### 4. Оборудование
___Прицессор___: AMD Ryzen 5 5500U with Radeon Graphics 2.10 GHz \
___ОП___: 8192 MiB \
___SSD___: 220GB

### 5. Программное обеспечение
___Операционная система семейства___ UNIX, ___наименование___ Ubuntu, ___версия___  20.04 LTS
___Интерпретатор команд___ bash, ___версия___ 5.0.11(1)-release
___Редактор текстов___ nano, ___версия___ 4.8

### 6. Идея, метод, алгоритм решения
__Создадим множество гласных букв и будем проверять каждый символ на принадлежность к этому множеству. Если не принадлежит, то считаем. В конце слова проверяем счетчик__


### 7. Сценарий выполнения работы
1) Создадим множество```VOWELS```, которое будет содержать гласные буквы.
2) Создадим функцию  ```charToSet```, которая будет получать на вход char а получать на выходе множество.
3) Создадим булеву функцию ```isThereOneConsonant```, которая будет отвечать на вопрос задачи.

 Тесты:
|  Ввод  | Вывод |
|:------------- | -------------:|
| aba aa aa bbb | yes, there is a word here containing one consonant |
| abc ooo ddd dcd | no, there are no words containing one consonant |
| a b c | yes, there is a word here containing one consonant |


### 8. Распечатка протокола

```С
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define VOWELS ( \
    1U << ('a' - 'a') | \
    1U << ('e' - 'a') | \
    1U << ('i' - 'a') | \
    1U << ('o' - 'a') | \
    1U << ('u' - 'a') \
)

typedef enum{
    OUT_OF_WORD,
    IN_WORD
} State;

unsigned int charToSet(char c) {
    c = tolower(c);
    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1u << (c-'a');
     }
}
bool isThereOneConsonant(){
    State state = OUT_OF_WORD;
    char a;
    unsigned int set = 0;
    int counter = 0;
    while ((a = getchar()) != EOF){
        a = tolower(a);
        switch (state) {
        case OUT_OF_WORD:
            set = 0;
            if (isspace(a) || a == '\n') {
                if (counter == 1) return 1;
                counter = 0;
                break;
            }else if (isalpha(a)) state = IN_WORD;
        case IN_WORD:
            if (charToSet(a) & VOWELS) {
                state = OUT_OF_WORD;
                break;
            }
            else {
                counter++;
                state = OUT_OF_WORD;
                break;
            }
        }
    }
    if (a == EOF) {
        if (counter == 1) return 1;
    }
    return 0;
}
int main(){
    if(isThereOneConsonant() == 1){
        printf("yes, there is a word here containing one consonant\n");
    } else printf("no, there are no words containing one consonant\n");
}
```


### 9. Дневник отладки

|  Дата    | Время | Событие  | Действие по исправлению |
|:------------- |:---------------:|:---------------:| -------------:|
| 3.12.22 | 15:34 | Выполнение лабораторной работы | |

### 10. Замечания автора по существу работы

### 11. Выводы
Были изучены методы обработки множеств и работы с ними на языке программирования С.

