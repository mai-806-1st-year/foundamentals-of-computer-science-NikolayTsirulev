#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isOct(char x) {
    return ((x - '0') >= 0 && (x - '0') <= 7);
}
typedef enum {
    OUT,
    IN_DIGIT,
    SPACE
} state;

int number_of_octal(){
    state state = OUT;
    int res = 0;
    int num = 0;
    int space = 0;
    int sign = 1;
    int i = 0;
    for (char a = getchar(); a != EOF; a = getchar()) {
        if (i == 0) i = 1; else i = 2;
        switch (state) {
            case OUT:
                if (isOct(a)) state = IN_DIGIT;
                else if (a == ' ' || a == '\n') {
                    state = SPACE;
                } else {
                    if (a == '-' && space == 1) sign = -1;
                    num = 0;
                    state = OUT;
                    break;
                }
            case IN_DIGIT:
                if (isOct(a)) {
                    if (space == 1 || i == 1) {
                        if (a == '0') num = num*8; else
                            num = num*8 + a - '0';
                        space = 0;
                        state = OUT;
                        break;
                    } else if (space == 0 && num != 0) {
                        if (a == '0') num = num*8; else
                            num = num*8 + a - '0';
                        state = OUT;
                        break;
                    } else if (space == 0 && num == 0) {
                        num = 0;
                        state = OUT;
                        break;
                    }
                }
            case SPACE:
                if (num*sign < 1000 && num*sign > 10) {
                    res++;
                }
                sign = 1;
                space = 1;
                num = 0;
                state = OUT;
                break;
        }
    }
    if (num*sign < 1000 && num*sign > 10) {
        res++;
    }
    return res;
}

int main()
{
    printf("%d", number_of_octal());
    return 0;
}
