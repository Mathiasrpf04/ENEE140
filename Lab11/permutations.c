#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int randy;
    int list[10];
    int calls = 0;
srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        random:
        randy = rand() % 10 + 1;
        calls++;
        for (int j = 0; j < 10; j++) {
            if (list[j] == randy) {
                goto random;
            }
        }
        list[i] = randy;
    }


    for (int i = 0; i < 10; i++) {
        printf("%d  ", list[i]);
    }
    printf("\nrand() was called %d times", calls);

    return 0;
}
