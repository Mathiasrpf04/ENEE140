#include <stdio.h>

int main(void) {
    printf("Give me 10 positive integers:\n");
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%i", &arr[i]);
    }
    printf("Give me a positive integer 1-10:");
    int k;
    scanf("%i", &k);
    if (1 > k || k > 10) {
        printf("Error: Number must be between 1 and 10");
    }
    printf("%i\n", arr[k - 1]);

    return 0;
}
