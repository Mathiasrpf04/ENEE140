#include <stdio.h>

main() {
    int a = 0;
    int c = 0;
    while ((a = getchar()) != 10) { // Runs until user inputs next line, or enter
        c++; // adds 1 count to character count
    }
printf("%d\n", c); // prints character count
}

/* Generic code if you want EOF to be different
main() {
    int a = 0;
    int c = 0;
    while ((a = getchar()) != EOF) { // Runs until user inputs EOF
        c++; // adds 1 count to character count
    }
printf("%d\n", c); // prints character count
}
*/