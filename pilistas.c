#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 256

typedef struct node
{
    int data;
    struct node *next;
} 
node;

typedef struct stack 
{
    int current_size;
    node* items[MAX_STACK_SIZE];
}
stack;


void push(stack *s, node *item);
node* pop(stack *s);
bool is_empty(stack *s);
void insert(node *list, int data);
void scan_list(node* list);
void print_list(node* list);
node* initialize_list();


int main(void)
{
    char* comando = malloc(sizeof(char) * 4); //POP ou PUSH

    stack stack;
    stack.current_size = 0;

    int i = 0;
    while(scanf("%s", comando) && i < 5)
    {
        if (strcmp(comando, "POP") == 0)
        {
            print_list(pop(&stack));
        }
        else if (strcmp(comando, "PUSH") == 0)
        {
            node* list = initialize_list();
            scan_list(list);
            push(&stack, list);
        }
        i++;
    }
}

void push(stack *s, node *item)
{
    if (s->current_size == MAX_STACK_SIZE)
    {
        printf("Stack overflow!");
        return;
    }
    s->items[s->current_size] = item;
    s->current_size++;
}

node* pop(stack *s)
{
    if (s->current_size == 0)
    {
        printf("Stack underflow!");
        return NULL;
    }
    node *item = s->items[s->current_size - 1];
    s->current_size--;
    return item;
}

bool is_empty(stack *s)
{
    return s->current_size == 0;
}

node* initialize_list()
{
    node *list = (node*) malloc(sizeof(node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void insert(node *list, int data)
{
    node *new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (list == NULL)
    {
        list = new_node;
        return;
    }

    node *current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void scan_list(node* list)
{
    int buffer;
    while(scanf("%d", &buffer) != EOF)
    {
        insert(list, buffer);
    }
}

void print_list(node* list)
{
    node *current = list;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
