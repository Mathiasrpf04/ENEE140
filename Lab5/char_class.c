#include <stdio.h>

int main(void) {
    int gc; //Character to be grabbed

    printf("Please enter one character:");
    scanf("%c", &gc);
//Each if statement checks if the int value of the character matches the ASCII code for a digit, lower case, or upper case character.
    if((gc >= 47)  && (gc<=57)) {
    printf("%c is a digit.\n", gc);
    }

    else if ((gc >= 65)  && (gc<=90)) {
        printf("%c is an upper case letter.\n", gc);
    }

    else if ((gc >= 97)  && (gc<=122)) {
        printf("%c is a lower case letter.\n", gc);
    }

    else {
        printf("%c is not a letter or digit.\n", gc);
    }

    return 0;
}
