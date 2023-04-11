/*Implementation of a closed addressing (separate chaining) Hash Table ADT
in C*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_HASH_SIZE 200

/*Linked List ADT*/
typedef struct node
{
    int data;
    struct node* next;
}
node;

/*Element that composes the ADT Hash Table*/
typedef struct element
{
    int key;
    node* data;
}
element;

/*Hash Table ADT*/
typedef struct hash_table 
{
    element *table[MAX_HASH_SIZE];
}
hash_table;

node* add(node *head, int data);
hash_table* create_hash_table(int size);
void put(hash_table *ht, int key, int value);
node* get(hash_table *ht, int key);
int hash(int value, int ht_size);
void print_hash_table(hash_table *ht, int ht_size);

int main(void)
{
    int test_cases;
    scanf("%d", &test_cases);

    for(int i = 0; i < test_cases; i++)
    {
        int address_amount;
        scanf("%d", &address_amount);

        int key_amount;
        scanf("%d", &key_amount);

        hash_table *ht = create_hash_table(address_amount);

        for(int j = 0; j < key_amount; j++)
        {
            int value_buffer;
            scanf("%d", &value_buffer);

            int key_buffer = hash(value_buffer, address_amount);

            put(ht, key_buffer, value_buffer);
        }

        print_hash_table(ht, address_amount);
    }
}

/*Function that adds a DATA in the end of a Linked List*/
node* add(node *head, int data)
{
    node *tmp = head;

    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if(tmp == NULL)
    {
        return new_node;
    }
    else
    {
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        return head;
    }  
}

/*Function that creates a hash table with SIZE, returning
a pointer to a hash_table ADT.*/
hash_table* create_hash_table(int size)
{
    /*Allocate memory space to the hash table*/
    hash_table *new_hash_table = 
        (hash_table*) malloc(sizeof(hash_table)); 
    
    /*Returns the pointer of the hash table that was created*/
    return new_hash_table;
}

/*Put a VALUE in the hash table HT in the position KEY.*/
void put(hash_table *ht, int key, int value)
{
    // TODO: Create a function that put a value in the linked list of the key pos of the HT

    if(ht->table[key] == NULL)
    {
        element *new_element = 
            (element*) malloc(sizeof(element));

        ht->table[key] = new_element;
    }

    ht->table[key]->key = key;
    ht->table[key]->data = add(ht->table[key]->data, value);
}

/*Get the list in the hash table HT with the KEY*/
node* get(hash_table *ht, int key)
{
    if(ht->table[key] == NULL)
    {
        return NULL;
    }

    return ht->table[key]->data;
}

/*Hashs a value, returning a key*/
/*Uses the hash function 'x mod ht_size'*/
int hash(int value, int ht_size)
{
    return value % ht_size;
}

void print_linked_list(node* head)
{
    node *tmp = head;
    
    while(tmp != NULL)
    {
        printf("-> %d ", tmp->data);
        tmp = tmp->next;
    }
    printf("-> \\");
}

/*Prints in the screen the hash table HT*/
void print_hash_table(hash_table *ht, int ht_size)
{   
    for(int i = 0; i < ht_size; i++)
    {
        printf("%d ", i);
        if(ht->table[i] != NULL)
        {
            print_linked_list(ht->table[i]->data);
        }
        else
        {
            printf("-> \\");
        }
        printf("\n");
    }
    printf("\n");
}






