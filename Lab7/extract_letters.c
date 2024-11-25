#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    printf("Please enter a string:\n");
    char str[100];
    fgets(str, sizeof(str), stdin);
for (int i = 0; i < strlen(str); i++) {
    if (str[i] >= 65  && str[i]<=90) {
        printf("%c", str[i]);
    }
    else if (str[i] >= 97  && str[i]<=122) {
        printf("%c", str[i]);
    }
}
    return 0;
}
