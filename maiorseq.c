#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char value;
    struct node* next;
} node;

node* scan_list();
void print_list(node* list);
void check_zero_seq(node* list);


int main(void)
{
    node* list = scan_list();
    print_list(list);
    check_zero_seq(list);
    return 0;
}

node* scan_list()
{
    char* value = malloc(sizeof(char) * 100);
    node* head = NULL;
    node* tail = NULL;

    while(scanf("%s", value) != EOF && strcmp("0", value) != 0)
    {
        for(int i = 0; i < strlen(value); i++)
        {
            node* n = (node*)malloc(sizeof(node));
            n->value = value[i];
            n->next = NULL;

            if(head == NULL)
            {
                head = n;
                tail = n;
            }
            else
            {
                tail->next = n;
                tail = n;
            }
        }
    }
    return head;
}

void print_list(node* list)
{
    node* n = list;
    while(n != NULL)
    {
        printf("%c", n->value);
        n = n->next;
    }
    printf("\n");
}

void check_zero_seq(node* list)
{
    node* n = list;
    int begin = 0;
    int end = 0;
    int current = 0;
    int zero_seq = 0;

    while(n != NULL)
    {
        if(n->value == '0')
        {
            begin = current;
            while(n->value == '0')
            {
                end = current;
                n = n->next;
                current++;
            }
            if(end - begin > zero_seq)
            {
                zero_seq = end - begin;
            }
        }
    }
    
    printf("%d %d\n", begin, end);     
}