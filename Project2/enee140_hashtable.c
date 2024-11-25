/*
* enee140_hashtable.c
*
* Implementation of the hash table operations.
*/
#include "enee140_hashtable.h"

#include <stdio.h>
#include <string.h>

/*
* Define the bucket and hashtable data types.
*/
typedef struct _bucket {
char key[MAX_STRING];
int value;
} Bucket;
typedef Bucket Hashtable[NBUCKETS];

/*
* Hashtable main storage
*/
static Hashtable my_hash_table;
static int used_buckets;

/*
* Internal library functions
*/
unsigned hash_function(char s[]){ //Grabs a pseudo-random location for key in hash
unsigned hashval, i;
for (hashval=0, i=0; s[i] != '\0'; i++) {
hashval += s[i] + 31*hashval;
}
return hashval % NBUCKETS;
}

/*
* Main hashtable API
*/
float hash_load_factor(){ //Returns the ratio of used to unused buckets in the hash.
return (float)used_buckets / (float)NBUCKETS;
}
/*
* Initialize the hash table by clearing its content.
*/
void hash_initialize(){
for (int i = 0; i < NBUCKETS; i++) { //Resets all the keys to NULL character
    my_hash_table[i].key[0] = '\0';
}
    used_buckets = 0; //Resets the number of used buckets to 0
}

int is_bucket_empty(int bucket) { //Tells us whether the bucket provided is empty or not.
    if (my_hash_table[bucket].value == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
* Insert a <key, value> pair in the hash table.
* Return 1 if the insert was successful, and 0 if
* the key could not be inserted because the hash
* table if full.
*/
int collision_chain_max; //Stores the maximum collision chain
int collision_total; //Stores the total number of collisions

float collision_stats_average() {
    return (float)collision_total / (float)used_buckets;
}

int collision_stats_max() {
    return collision_chain_max;
}

int hash_put(char key[], int value) {
    int bucket = hash_function(key); //Picks a bucket based off of the key
    int original_bucket = bucket; // Saves original position to find if we went in a full loop
    int new_collision_chain =  0;

    if (is_bucket_empty(bucket) == 1) { //If this bucket is empty then it places the key and the value
        my_hash_table[bucket].value = value;
        strcpy(my_hash_table[bucket].key,key);
        used_buckets++; //updates number of used buckets
        return 1;
    }

        while (is_bucket_empty(bucket) != 1) { //Runs until we find an empty bucket or the matching one

            if (strcmp(my_hash_table[bucket].key, key) == 0) { //Checks if given key matches key of this bucket
                my_hash_table[bucket].value = value;

                if(new_collision_chain > collision_chain_max) { //Sets a new collision chain max if collision is larger
                    collision_chain_max = new_collision_chain;
                }

                collision_total += new_collision_chain; //Adds onto total collisions

                return 1;
            }

            ++bucket; //Runs through the next bucket
            ++new_collision_chain; //Since we had to go to the next bucket, we know the collision chain has increased by 1

            if (bucket == NBUCKETS) { // Resets bucket if we've hit the end of the hash
                bucket = 0;
            }

            if (bucket == original_bucket) { // We looped through the entire table, push an error msg.
                perror("Hash table is full\n");
                return 0;
            }

            if (is_bucket_empty(bucket) == 1) { //If this bucket is empty then it places the key and updates the value
                my_hash_table[bucket].value = value;
                strcpy(my_hash_table[bucket].key,key);
                used_buckets++; //updates number of used buckets

                if(new_collision_chain > collision_chain_max) { //Sets a new collision chain max if collision is larger
                    collision_chain_max = new_collision_chain;
                }

                collision_total += new_collision_chain;//Adds onto total collisions

                return 1;
            }
        }
    return 0;
}
/*
* If key is stored in the hashtable, return the corresponding
* value. Otherwise, return 0.
*/
int hash_get(char key[]){
    int bucket = hash_function(key); //Picks a bucket based off of the key
    int original_bucket = bucket; // Saves original position to find if we went in a full loop

    if (strcmp(my_hash_table[bucket].key, key) == 0) { //Checks if given key matches key of this bucket
        return my_hash_table[bucket].value;
    }

    while (strcmp(my_hash_table[bucket].key, key) != 0) { //Runs until we find a matching key
        ++bucket; //Runs through the next bucket

        if (bucket == NBUCKETS) { // Resets bucket if we've hit the end of the hash
            bucket = 0;
        }

        if(bucket == original_bucket) { // If we loop through the whole hash without finding the word we return 0
            return 0;
        }

        if (my_hash_table[bucket].key == 0) { //If a bucket is empty then key isn't in hash
            return 0;
        }

        if (strcmp(my_hash_table[bucket].key, key) == 0) { //Checks if given key matches key of this bucket
            return my_hash_table[bucket].value;
        }
    }
    return 0;
}
/*
* Returns 1 if key is stored in the hashtable, and 0 otherwise.
*/
int hash_lookup(char key[]) {
    int bucket = hash_function(key); //Picks a bucket based off of the key
    int full = 0; // Used to check if we've looped through all buckets

    if (strcmp(my_hash_table[bucket].key, key) == 0) { //Checks if given key matches key of this bucket
        return 1;
    }

    while (strcmp(my_hash_table[bucket].key, key) != 0) { //Runs until we find a matching key
        if(full == NBUCKETS) { // If we loop through without finding one we return an error
            return 0;
        }

        ++bucket; //Runs through the next bucket
        if (bucket == NBUCKETS) { // Resets bucket if we've hit the end of the hash
            bucket = 0;
        }

        if (my_hash_table[bucket].key == 0) { //If a bucket is empty then key isn't in hash
            return 0;
        }

        if (strcmp(my_hash_table[bucket].key, key) == 0) { //Checks if given key matches key of this bucket
            return 1;
        }
        full++;
    }
    return 0;
}

void print_hash(){ //Used for debugging, just prints the hash table out
for (int i = 0; i < NBUCKETS; i++) {
printf("%s = %d\n", my_hash_table[i].key, my_hash_table[i].value);
}
}


