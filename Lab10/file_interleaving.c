#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    // Checks for correct number of arguments
    if (argc != 4){
        fprintf(stderr, "Correct Usage: %s <file1> <file2> <file3>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Opens file1.txt and file2.txt for reading
    FILE *file1 = fopen(argv[1], "r");
    if (file1 == NULL){
        perror("Error opening file1");
        exit(EXIT_FAILURE);
    }

    FILE *file2 = fopen(argv[2], "r");
    if (file2 == NULL){
        perror("Error opening file2");
        exit(EXIT_FAILURE);
    }

    //Writes to file3
    FILE *file3 = fopen(argv[3], "w");
    if (file3 == NULL){
        perror("Error opening file3");
        exit(EXIT_FAILURE);
    }

    char line1[512];
    char line2[512];

    while (feof(file1) != 1 || feof(file2) != 1) {
        // Reads one line from file1
        if (fgets(line1, sizeof(line1), file1) != NULL){
            fputs(line1, file3);  // Writes it to file3
        }

        // Reads one line from file2
        if (fgets(line2, sizeof(line2), file2) != NULL){
            fputs(line2, file3);  // Writes it to file3
        }
    }

    // Closes all files
    fclose(file1);
    fclose(file2);
    fclose(file3);

    printf("Output written to %s\n", argv[3]);
    return 0;
}

