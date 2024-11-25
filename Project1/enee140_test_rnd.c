#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Compiled in GRACE using: gcc -o enee140_test_rnd -std=c99 -lm enee140_test_rnd.c

int main() {
    int length; //length of the array storing numbers provided
    scanf("%d",&length);
    int num; //Just a temporary variable to store in scanf to see if it returns a number
    int arr[length]; //Our array of inputted numbers set to the length provided
    int count = 0; //Counts the number of numbers actually given

    for (int i = 0; i < length; i++) { //Sets all numbers to -1, as you don't get -1 from the rnd_gen
    arr[i] = -1;
}

    while(scanf("%d",&num) == 1){ //While scanf reads a number, it stores that number in the array
        if(num > 99 || num < 0) { //If that number is outside the array, then you exit
            printf("%d is not in the [0, 99] range.\n", num);
            exit(1);
        }
        arr[count] = num; //Stores that number in the array
        if (count == length-1) { //Breaks while loop if the number of numbers read reaches the length of the array
            break;
        }
        count++; //Adds 1 to the count of numbers read
    }

    if (arr[length - 1] == -1) { //If array isn't filled, then the last number will be -1 and code will exit
        printf("%d numbers are required, but only %d were provided.\n", length, count);
        exit(1);
    }

    int observed[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //Each 0 is a different bin for the formula
    float expected = length/10.0; //Sets the expected number of values for each bin

    for (int i = 0; i < length; i++) { //Checks whether each number in the array goes to each bin
        if (arr[i] >=0 && arr[i] <= 9) {
        observed[0] = observed[0] + 1; // If it does, it will add 1 to that bin's count in the observed array
        }
        else if (arr[i] >=10 && arr[i] <= 19) {
            observed[1] = observed[1] + 1;
        }
        else if (arr[i] >=20 && arr[i] <= 29) {
            observed[2] = observed[2] + 1;
        }
        else if (arr[i] >=30 && arr[i] <= 39) {
            observed[3] = observed[3] + 1;
        }
        else if (arr[i] >=40 && arr[i] <= 49) {
            observed[4] = observed[4] + 1;
        }
        else if (arr[i] >=50 && arr[i] <= 59) {
            observed[5] = observed[5] + 1;
        }
        else if (arr[i] >=60 && arr[i] <= 69) {
            observed[6] = observed[6] + 1;
        }
        else if (arr[i] >=70 && arr[i] <= 79) {
            observed[7] = observed[7] + 1;
        }
        else if (arr[i] >=80 && arr[i] <= 89) {
            observed[8] = observed[8] + 1;
        }
        else if (arr[i] >=90 && arr[i] <= 99) {
            observed[9] = observed[9] + 1;
        }
    }
//In theory, you could plop the above for loop in the while loop and check each number as it comes, instead
//of storing them all in an array and checking, but I feel this is easier to read and in theory could be good
//if you wanted to run other tests that involved checking the numbers in the array.


    float D = 0.0; //Chi-squared value of input by the end
    float temp; //Temporary number to store the value of the formula so it can be added to the total, D

    for (int i = 0; i < 10; i++) {
        temp = (pow((observed[i] - expected),2)) / expected; //Enacts exponential distribution formula
        D = D + temp; //Adds above to D, the sum of each bin's addition to Chi-square value
    }

    if (D <= 14.684) {
        printf("The sequence is consistent with the uniform distribution (D = %.2f)\n",D);

    }
    else if (D > 14.684 && D <= 21.666) {
        printf("The sequence is suspicious (D = %.2f)\n",D);

    }
    else if (D > 21.666) {
        printf("The sequence is unlikely to come from a uniform distribution (D = %.2f)\n",D);

    }


    return 0;
}
