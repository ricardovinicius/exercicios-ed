#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1024

typedef struct node
{
    char data;
    struct node* next;
}
node;

int scan_string(char buffer[MAX_NUM]);
node* parse_list(char* string);
void print_list(node* list);
void bigseq(node* list);

int main(void)
{
    char sequences[MAX_NUM];
    //scan_string(sequences);
    //printf("%s\n", sequences);
    
    //print_list(list);
    
    while(scan_string(sequences) != -1)
    {
        node* list = NULL;
        list = parse_list(sequences);
        bigseq(list);
    }

}

int scan_string(char buffer[MAX_NUM]) //returns -1 if the input was a unic zero
{
    scanf("%s", buffer);

    if(strcmp(buffer, "0") == 0)
    {
        return -1;
    }
    
    return 0;
}

node* parse_list(char* string)
{
    if (strlen(string) == 0) {
        return NULL;
    }

    node* head = NULL;
    node* tail = NULL;

    for(int i = 0; i < strlen(string); i++)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = string[i];
        new_node->next = NULL;

        if(tail == NULL)
        {
            head = new_node;
            tail = new_node;  
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}


void print_list(node* list)
{
    node* n = list;

    while(n != NULL)
    {
        printf("%c ", n->data);
        n = n->next;
    }

    printf("\n");

    return;
}

void bigseq(node* list)
{
    int current_cursor = 0;
    int max_seq = 0;
    int current_seq = 0;
    int end_of_seq = 0;

    node* n = list;

    while(n != NULL)
    {
        if(n->data == '0')
        {
            while(n != NULL && n->data == '0')
            {
                current_seq++;
                n = n->next;
                current_cursor++;
            }

            if(current_seq > max_seq)
            {
                max_seq = current_seq;
                end_of_seq = current_cursor;
            }

            current_seq = 0;
        } 

        if(n != NULL)
        {
            n = n->next;
            current_cursor++;
        }     
    }

    printf("%d %d\n", (end_of_seq - max_seq), (end_of_seq - 1));
}