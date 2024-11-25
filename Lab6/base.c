#include <stdio.h>
#include <math.h>


void hexadecimal(int posint) {
    int result = posint; //stores the result of each division
    int remainder = 0; // stores the remainder of each division
    int div = 0; // stores how much to divide by each cycle
    int j = 0; // stores how many cycles
    int dexarray[100]; // stores remainders in an array
while (result != 0) {
    j++;
    div = (pow(16,j)); //calculates how much to divide by for result
    remainder = result % 16; //calculates remainder
    result = posint / div; // calculates result of division, truncating remainder
    dexarray[j] = remainder; //adds remainder to the array
    if (dexarray[j] > 9) { // turns 0-9 into ASCII equivalent
    dexarray[j] += 55;
    }
    else if (dexarray[j] < 10) { // turns 10-15 into ASCII equivalent of A-F
        dexarray[j] += 48;
    }
    else {
        printf("error");
    }
}
printf("Your number in 16bit is: ");
    for (int i = j; i >= 0; i--) { // runs through array backwards
        printf("%c", dexarray[i]);
    }
    printf("\n");
}

void octadecimal(int posint) { // Follows mostly the same pattern as hexadecimal, but divides by 8.
    int result = posint;
    int remainder = 0;
    int div = 0;
    int j = 0;
    int octaarray[100];
    while (result != 0) {
        j++;
        div = (pow(8,j));
        remainder = result % 8;
        result = posint / div;
        octaarray[j] = remainder;

        if (octaarray[j] < 10) {
            octaarray[j] += 48;
        }
        else {
            printf("error");
        }
    }
    printf("Your number in 8bit is: ");
    for (int i = j; i >= 0; i--) {
        printf("%c", octaarray[i]);
    }
printf("\n");
}


void binary(int posint) { //Follows mostly the same pattern as hexadecimal, but divides by 2.
    int result = posint;
    int remainder = 0;
    int div = 0;
    int j = 0;
    int binaarray[100];
    while (result != 0) {
        j++;
        div = (pow(2,j));
        remainder = result % 2;
        result = posint / div;
        binaarray[j] = remainder;
        if (binaarray[j] < 10) {
            binaarray[j] += 48;
        }
        else {
            printf("error");
        }
    }
    printf("Your number in 2bit is: ");
    for (int i = j; i >= 0; i--) {
        printf("%c", binaarray[i]);
    }
    printf("\n");
}

int main(void) {

    int posint;
    printf("Enter any positive integer:");
scanf("%d", &posint);
    hexadecimal(posint);
    octadecimal(posint);
    binary(posint);
    return 0;
}
