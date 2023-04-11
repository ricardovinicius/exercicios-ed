/*Implementation of a Open Addresing Hash Table ADT
in C*/

#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 11

/*Element that composes the ADT Hash Table*/
typedef struct element
{
    int key;
    int value;
}
element;

/*Hash Table ADT*/
typedef struct hash_table 
{
    element *table[HASH_SIZE];
}
hash_table;

hash_table* create_hash_table();
void put(hash_table *ht, int key, int value);
int get(hash_table *ht, int key);
void remove(hash_table *ht, int key);

int main(void)
{
        
}

/*Function that creates a hash table, returning
a pointer to a hash_table ADT.*/
hash_table* create_hash_table()
{
    /*Allocate memory space to the hash table*/
    hash_table *new_hash_table = 
        (hash_table*) malloc(sizeof(hash_table));

    /*Points each block in the table to NULL*/
    for(int i = 0; i < HASH_SIZE; i++)
    {
        new_hash_table->table[i] = NULL;
    }   
    
    /*Returns the pointer of the hash table that was created*/
    return new_hash_table;
}

/*Put a VALUE in the hash table HT in the position KEY++.*/
void put(hash_table *ht, int key, int value)
{
    int h = key % HASH_SIZE; //extracts the modulus to dont exceed the bounds
    
    while(ht->table[h] != NULL) //if founds a collision of elements in the same key
    {                               //try to found a free bucket right after
        if (ht->table[h]->key == key)
        {
            ht->table[h]->value = value;
            break;
        }
        h = (h + 1) % HASH_SIZE;
    }

    /*When find a free bucket, input the element inside
    the table.*/
    if(ht->table[h] == NULL)
    {
        /*element buffer*/
        element *new_element = 
            (element*) malloc(sizeof(element));

        new_element->key = key;
        new_element->value = value;
        ht->table[h] = new_element;
    }
}

/*Get the element in the hash table HT with the KEY*/
int get(hash_table *ht, int key)
{
    int h = key % HASH_SIZE;
    while(ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            return ht->table[h]->value;
        }
        h = (h + 1) % HASH_SIZE;
    }
    return -100; // if cannot find the element, returns a flag 
}

/*Removes a element in the hash table HT with the KEY.*/
void remove(hash_table *ht, int key)
{
    int h = key % HASH_SIZE;
    while (ht->table[h] != NULL)
    {
        if (ht->table[h]->key == key)
        {
            ht->table[h]->key = -1;
        }
        h = (h + 1) % HASH_SIZE;
    }
}