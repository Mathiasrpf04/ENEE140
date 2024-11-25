#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Compiled in GRACE using: gcc -o enee140_gen_rnd -std=c99 -lm enee140_gen_rnd.c

unsigned X; // Current Value of RNG
unsigned m; // Modulus exponent M = 2^m
unsigned A; // Multiplier
unsigned B; // Increment

void seed_rnd (unsigned seed, int algorithm){ // Generates values from given seed and algorithm
if (algorithm==1) {
    m = 32;
    A = 214013;
    B = 2531011;
}
    else if (algorithm==2) {
        m = 32;
        A = 1103515245;
        B = 12345;
    }
    else if (algorithm==3) {
        m = 31;
        A = 1103515245;
        B = 12345;
    }
    else{
        printf("Error!");
    }
    X = seed;
}


void get_rnd_max() { // Prints out the max value of the Random Generator based off of the algorithm and seed
    double rndmax = pow(2,m) - 1;
    printf("RND_MAX = %.0lf\n", rndmax);
}


unsigned gen_rnd() { // Generates the random number using the formula given

    if (m == 32) {
        X = (X * A ) + B;
    }
    else {
            int M = pow(2,m);
            X = (X * A + B) % M;
    }
return X;

}

unsigned gen_rnd_limit(unsigned limit) { //Adjusts random number generated to be under the limit specified
gen_rnd();

    if (limit < X) { //Adjusts random number so it will at most be the limit specified
        X = X % limit;
    }

    return X;
}

int gen_rnd_range(int min_gen, int max_gen) { //Adjusts random number so it will be within the specified range
    gen_rnd();
    X = (X % (max_gen - min_gen + 1)) + min_gen;
    return X;
}

float gen_rnd_float(float min_gen, float max_gen) { //Adjusts random number so it will be a float within the range given
    gen_rnd();
    float XF = min_gen + (X /((float)((pow(2,m) - 1)/(max_gen-min_gen))));
    return XF;
}

float gen_rnd_exp(float mean) { //Generates Random Numbers using exponential-distribution formula
float XF = gen_rnd_float(0, 1); //Generates Floats between 0 and 1 for formula
    if (XF == 0) { // Makes the number 0.5 for the special case where you generate 0, as 0 doesn't work with log
        XF = 0.5;
    }
    float Xi = (-mean)*log(XF); //Applies formula to get exponentially-distributed floats
return Xi;
}

int main(void) {

//Main Menu Text, different print statements so each one can be individually edited
printf("Welcome to the ENEE140 pseudorandom number generator!\n");
printf("1: Print RND_MAX\n");
printf("2: Generate uniformly-distributed positive integers\n");
printf("3: Generate uniformly-distributed positive integers, up to a given limit\n");
printf("4: Generate uniformly-distributed integers, from a given range\n");
printf("5: Generate uniformly-distributed floats, from a given range\n");
printf("6: Generate exponentially-distributed float\n");
printf("Enter your choice (1-6):");

char menuchoice; //Which part of the menu they select
int menuchoicefail = 0; // Counts incorrect inputs
scanf(" %c",&menuchoice); // reads input
while((menuchoice < 49)  || (menuchoice>54)) { //Checks if choice is valid and if it is not 3 times, then it exits
    ++menuchoicefail; //adds to fail counter
    if(menuchoicefail == 3) {
        printf("You have entered 3 invalid options. Goodbye!");
        exit(1);
    }

    printf("Sorry, that is not a valid option\nEnter your choice (1-6):");
    scanf(" %c",&menuchoice);
}

printf("\n");
//Algorithm Selection Code
printf("Select your algorith to use.\nEnter your choice (1-3):");
char algchoice; //Which part of the menu they select
int algchoicefail = 0; // Counts incorrect inputs
scanf(" %c",&algchoice); // reads input
while((algchoice < 49)  || (algchoice>51)) { //Checks if choice is valid and if it is not 3 times, then it exits
    algchoicefail++;
    if(algchoicefail == 3) {
        printf("You have entered 3 invalid options. Goodbye!");
        exit(1);
    }
    printf("Sorry, that is not a valid option\nEnter your choice (1-3):");
    scanf(" %c",&algchoice);

}

    printf("\n");

    //Seed Selection Code
printf("Select the seed for the random number generator:");
int seed;
scanf("%i",&seed);
    printf("\n");

int algorithm = algchoice - 48; //Turns algchoice's ASCII value into actual number value
seed_rnd(seed, algorithm);

    int menu = menuchoice - 48; //Turns menuchoice's ASCII value into actual number value

if(menu == 1) { //Prints out RND_MAX then prompts another choice from the menu
    get_rnd_max();
    printf("2: Generate uniformly-distributed positive integers\n");
    printf("3: Generate uniformly-distributed positive integers, up to a given limit\n");
    printf("4: Generate uniformly-distributed integers, from a given range\n");
    printf("5: Generate uniformly-distributed floats, from a given range\n");
    printf("6: Generate exponentially-distributed float\n");
    printf("Enter your choice (2-6):");

    scanf(" %c",&menuchoice); // reads input

    while((menuchoice < 49)  || (menuchoice>54)) { //Checks if choice is valid and if it is not 3 times, then it exits
        ++menuchoicefail; //adds to fail counter
        if(menuchoicefail == 3) {
            printf("You have entered 3 invalid options. Goodbye!");
            exit(1);
        }

        printf("Sorry, that is not a valid option\nEnter your choice (1-6):");
        scanf(" %c",&menuchoice);
    }
    printf("\n");
    menu = menuchoice - 48; //Turns ASCII value into appropriate number value
}

if(menu == 2) { //Generates Random Numbers
printf("How many numbers should I generate:");
        int length;
        scanf("%i",&length);
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("%u ", gen_rnd());
        }
    }

    else if(menu == 3) { //Prints Random Numbers up to a limit
        int length;
        int limit;
        printf("How many numbers should I generate:");
        scanf("%i",&length);
        printf("Enter the maximum number to generate:");
        scanf("%i",&limit);
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("%u ", gen_rnd_limit(limit));
        }
    }

    else if(menu == 4) { //Prints Random Numbers between min and max given by user
        int length;
        int min;
        int max;
        printf("How many numbers should I generate:");
        scanf("%i",&length);
        printf("Enter the minimum number to generate:");
        scanf("%i",&min);
        printf("Enter the maximum number to generate:");
        scanf("%i",&max);
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("%i ", gen_rnd_range(min,max));
        }
    }

    else if(menu == 5) { //Prints Floats between min and max given by user
        int length;
        float min;
        float max;
        printf("How many numbers should I generate:");
        scanf("%i",&length);
        printf("Enter the minimum number to generate:");
        scanf("%f",&min);
        printf("Enter the maximum number to generate:");
        scanf("%f",&max);
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("%f ", gen_rnd_float(min,max));

        }
    }

    else if(menu == 6) { //Prints exponentially-distributed floats using mean given by user
        int length;
        float mean;
        printf("How many numbers should I generate:");
        scanf("%i",&length);
        printf("Enter the mean of the distribution:");
        scanf("%f",&mean);
        while(mean < 0) {
            printf("Error: the mean must be a positive number.\n");
            printf("Enter the mean of the distribution:");
            scanf("%f",&mean);
        }
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("%f ", gen_rnd_exp(mean));
        }
    }

    return 0;
}
