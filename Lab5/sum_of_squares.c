#include <stdio.h>

void sumofsquares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int num = i * i;
        sum += num;
        if (i < n) {
            printf("%i + ", num);
        }

        if (i == n) {
            printf("%i = ", num);
        }
    }
    printf("%i \n", sum);
}

int main(void) {
printf("Please input a positive integer:");
    int n;

    scanf("%i", &n);
    sumofsquares(n);

    return 0;
}
