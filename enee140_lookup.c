/*
* enee140_lookup.c
*
* Read the input line‐by‐line, store the words in a
* hash table, and allow the user to look up several words.
*/
#include "enee140_hashtable.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LINE 1000

char old_line[MAX_LINE] = "Hello world!"; //Holds the last line looked at
int old_count = 0; //Holds the counted characters within that last line

int next_word(const char line[], char word[], int size) {
memset(word, '\0', size); //Resets word

 if (strcmp(old_line, line) == 0) { //If the line is the same, copy a word after where we ended
 int i = old_count; //Puts where we go in the line to where we ended before in the line on the last loop

  //Jumps in the line to where the next non whitespace, or punctuation value is.
   while (isspace(line[i]) || ispunct(line[i])) {
            i++;
        }

  int j = 0; //Where in word to copy from line's char.

  //Runs until the next whitespace, or punctuation value, or the end of the line, or until the word size is capped out.
  while (!isspace(line[i]) && !ispunct(line[i]) && line[i] != '\0' && j < size - 1) {
   word[j++] = line[i++];
  }

  old_count = i; //Updates our count of where in the line we were.

  //If nothing was copied to word and if we hit the end of the line, then signal we finished that line.
  if (word[0] == '\0' && line[i] == '\0') {
   return 0;
  }
}

 else { //If the line isn't the same, copy a word from the beginning
  int i = 0; //Since we are on a new line, we start from the beginning of it.

  //Jumps in the line to where the next non whitespace, or punctuation value is.
  while (isspace(line[i]) || ispunct(line[i])) {
   i++;
  }

  int j = 0; //Where in word to copy from line's char.

  //Runs until the next whitespace, or punctuation value, or the end of the line, or until the word size is capped out.
  while (!isspace(line[i]) && !ispunct(line[i]) && line[i] != '\0' && j < size - 1) {
   word[j++] = line[i++];
  }

  old_count = i; //Updates our count of where in the line we were.
  strcpy(old_line, line); //Updates the line we were at, so we can check if it's the same next loop.

  //If nothing was copied to word and if we hit the end of the line, then signal we finished that line.
  if (word[0] == '\0' && line[i] == '\0') {
   return 0;
  }
 }

 //If word was updated at all, signal that we haven't finished that line yet.
 if (word[0] != '\0') {
  return 1;
 }

return 0;
}

//Gives the menu options and prompts for a choice
int prompt_and_check() {
 printf("1. Print hash table statistics\n");
 printf("2. Look up a word\n");
 printf("3. Exit\n");

 char menu_choice;
 scanf(" %c", &menu_choice); //Grabs user input for menu choice.
 while ((menu_choice < 49) || (menu_choice > 51)) { //If input is not 1-3, then asks again
  printf("Sorry, that is not a valid option\nEnter your choice (1-3):");
  scanf(" %c", &menu_choice);
 }

 int menu = menu_choice - 48; //Turns ASCII value into actual int value
 return menu;
}

//Used to turn characters lowercase. Used to ignore case matching.
void lowercase_string(char word[]) {
 for (int i = 0; i < strlen(word); i++) {
  word[i] = tolower(word[i]);
 }
}


int main(int argc, char *argv[]){
char word[MAX_STRING], line[MAX_LINE];

FILE *file;

// Check command‐line arguments
if (argc < 2) { //Checks that we actually have at least 2 command line arguments
fprintf(stderr, "Usage: %s filename \n", argv[0]);
return -1;
}

file = fopen(argv[1], "r");

if (file == NULL) {
printf ("Could not open the %s file.\n", argv[1]);
exit (-1);
}

// Initialize the hashtable
hash_initialize();

// Read file line‐by‐line
while (fgets(line, MAX_LINE, file) != NULL) {
// Extract each word from line and add it to the hash table
 while (next_word(line, word, MAX_STRING)) {
  lowercase_string(word); //Ignores case matching
  int value = hash_get(word); //Grabs the current value of the key in the hash
  if (value == 0) { //If we have a new key, input 1 as the value
   hash_put(word, 1);
  }
  else{ //If it is not a new key then update the value by 1.
   ++value;
   hash_put(word, value);
  }
 }
}

// Print menu and implement project functionality
printf("Welcome to the ENEE140 work lookup program!\n");
 int menu = prompt_and_check();

while(menu == 1 || menu == 2) {//Keeps prompting for choices until user decides to exit by inputting 3.

 if (menu == 1) {
  printf("The load factor is: %f\n\n", hash_load_factor());
  printf("The maximum collision chain is: %i\n\n", collision_stats_max());
  printf("The average collision chain is: %f\n\n", collision_stats_average());
 }

 else if (menu == 2) {
  printf("Enter a word:\n");
  char given_word[MAX_STRING];
  scanf("%s", given_word);
  lowercase_string(given_word);
  if (hash_get(given_word) != 0) {
   printf("That word was found %i times.\n\n", hash_get(given_word));
  }

  if (hash_get(given_word) == 0) {
   printf("That word was not found.\n\n");
  }
 }

 menu = prompt_and_check(); // prompts user for menu choice.
}

if (menu == 3) {
exit(0);
}

return 0;
}
