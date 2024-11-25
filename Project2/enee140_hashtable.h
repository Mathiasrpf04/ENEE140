/*
* enee140_hashtable.h
*
* Header file for a hash table library.
*/

#ifndef ENEE140_HASHTABLE_H_
#define ENEE140_HASHTABLE_H_

/*
* Define the parameters of a hashtable that will store English words.
* Provision the capacity of the hashtable considering the fact that
* Shakespeare's works include about 30,000 unique words and that the
* lookup performance tends to decrease with a load factor > 0.7.
*/

#define NBUCKETS 50021 // prime number, for better hash uniformity
#define MAX_STRING 80

/* Function prototypes for the public hashtable API. */
void hash_initialize();

float hash_load_factor();

int hash_put(char key[], int value);

int hash_get(char key[]);

int hash_lookup(char key[]);

float collision_stats_average(); //Extra-credit: Collision chain statistics

int collision_stats_max(); //Extra-credit: Collision chain statistics

void print_hash(); //Used to print hash out, for debugging

#endif /* ENEE140_HASHTABLE_H_ */

/* Some notes:
 * Compiled all 3 using:
 * gcc -o enee140_pr2 -std=c99
 * -I/home/ENEE140/Lab/Project_2/enee140_hashtable.h enee140_hashtable.c enee140_lookup.c
 *
 * Ran that output by using:
 * ./enee140_pr2 shakespeare.txt
 *
 * When debugging I added in print_hash to print out the hash and output it all into a text file using:
 * ./enee140_pr2 shakespeare.txt > words_and_count.txt
 *
 * I then cross-referenced the hash using the command we were given:
 *  cat shakespeare.txt | tr '[:space:]' '\n' | tr '[:punct:]' '\n' | tr '[:upper:]' '[:lower:]' | grep -c '^have$'
 *  where have is just any word that you want to check the number of in the text.
 *  I found them to provide consistent answers between each other, suggesting the program works correctly.
 */