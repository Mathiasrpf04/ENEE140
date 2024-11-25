#include <stdio.h>
#include <string.h>



int main(void) {

    printf("Input your name: \n");
    char name[50];
    fgets(name, sizeof(name), stdin);
    char *newname = name;

    for (int i=0; i<=strlen(name); i++) { //Shifts either UP or LOW case letters with wrapping around
        int s=3; //Amount to shift by
        if(name[i] >= 65 && name[i] <= 90) { //If you have an upper case character shifts that
            int U_lim=90;
            int L_lim=65;
            newname[i]=L_lim + ((name[i]+s-L_lim) % (U_lim-L_lim));
        }
        else if(name[i] >= 97 && name[i] <= 122) { //If you have a lower case character shifts that
            int U_lim=122;
            int L_lim=97;
            newname[i]=L_lim + ((name[i]+s-L_lim) % (U_lim-L_lim));
        }
    }
    printf("Here is your name shifted using a Caesar Cipher: %s \n", newname);

    return 0;
}
