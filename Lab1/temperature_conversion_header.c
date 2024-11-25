/*
 * temperature_conversion.c
 *
 *   K&R Exercise 1.4
 *   Print Celsius-Fahrenheit table
 *   for celsius = -100, -90, ... 0, 10, ... 100.
 *
 */


#include <stdio.h>


#define LOWER   -100
#define UPPER   100
#define STEP    10


int
main()
{
    int         celsius;
    float       fahr;

    celsius = LOWER;
    printf("Celsius  Fahrenheit \n");
    while (celsius <= UPPER) {
        fahr = ((9.0/5) * celsius) + 32;
        printf(" %6d  %10.1f\n", celsius, fahr);
        celsius = celsius + STEP;
    }
    return 0;
}