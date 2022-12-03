 Тесты:
|  Ввод  | Вывод |
|:------------- | -------------:|
| aba aa aa bbb | yes, there is a word here containing one consonant |
| abc ooo ddd dcd | no, there are no words containing one consonant |
| a b c | yes, there is a word here containing one consonant |


```
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
