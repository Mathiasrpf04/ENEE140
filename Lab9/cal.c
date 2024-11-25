#include <stdio.h>

int main(void) {

    printf("     April 2023\n");
    printf("Su Mo Tu We Th Fr Sa\n                  ");


    for(int i = 1; i <= 30; i++) {
        if((i+6)%7 != 0) {
            printf("%2d ", i);
        }
        else if((i+6)%7 == 0) {
            printf("%2d\n", i);
        }
    }

    return 0;
}
