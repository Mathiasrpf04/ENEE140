#include <stdio.h>

int main(void) {

//Prints out multiplication table
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            printf("%dx%d=%2d\t", i, j, i * j);
        }
        printf("\n");
    }
    printf("\n");


//Prints out rotated table
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            printf("%dx%d=%2d\t", j, i, i * j);
        }
        printf("\n");
    }
    printf("\n");

//Prints out Lower Triangle Half of table
    for(int i = 1; i <= 9; i++) {
        int j=1;
        while(j<=i) {
            printf("%dx%d=%2d\t", i, j, i * j);
            j++;
        }
        printf("\n");
    }
    printf("\n");

//Prints out Upper Triangle Half of table
    for(int i = 1; i <= 9; i++) {
        int j=1;
        int k=9;
        while(k>=i) {
            printf("%dx%d=%2d\t", i, j, i * j);
            k--;
            j++;
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
