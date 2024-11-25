#include <stdio.h>

int main(void) {
    int arr[] = {20, 5, 11, -3, 0, 34, -12, 9, 100, 4};
    int N = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < N; i++) {
        printf(" %4d", arr[i]);
    }

    for (int k = 1; k < N; k++) {

        int temp = arr[k];
        int j = k-1;

       while (j >= 0 && arr[j] > temp) {
           arr[j+1] = arr[j];
           j = j-1;
       }
        arr[j+1] = temp;
    }


    printf("\nSorted array:   ");
    for (int i = 0; i < N; i++) {
        printf(" %4d", arr[i]);
    }
}
