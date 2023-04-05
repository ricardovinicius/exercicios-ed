#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STACK_SIZE 256

typedef struct stack 
{
    int current_size;
    int items[MAX_STACK_SIZE];
}
stack;

stack* create_stack();
void push(stack *s, int item);
int pop(stack *s);
bool is_empty(stack *s);
bool is_balanced(char *str);

int main(void)
{
    int vezes_a_repetir;
    scanf("%d ", &vezes_a_repetir);

    for(int i = 0; i < vezes_a_repetir; i++)
    {   
        char str[256];
        /*lê a string até ter um enter*/
        fgets(str, 256, stdin);

        if (is_balanced(str))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}

stack* create_stack()
{
    stack *new_stack = (stack*) malloc(sizeof(stack));
    new_stack->current_size = 0;
    return new_stack;
}

void push(stack *s, int item)
{
    if (s->current_size == MAX_STACK_SIZE)
    {
        printf("Stack overflow!");
        return;
    }
    s->items[s->current_size] = item;
    s->current_size++;
}

int pop(stack *s)
{
    if (s->current_size == 0)
    {
        printf("Stack underflow!");
        return -1;
    }
    s->current_size--;
    return s->items[s->current_size];
}

bool is_empty(stack *s)
{
    return s->current_size == 0;
}

/* Função que retorna verdadeiro caso os parênteses/colchetes abertos estejam todos fechados*/
bool is_balanced(char *str)
{
    //printf("%s\n", str);
    stack *s = create_stack();
    int flag_empty = 0;
    int i = 0;

    /*for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] != ' ')
        {
            flag_empty = 1;
        }
    }

    if(flag_empty == 0)
    {
        return true;
    }*/

    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[')
        {
            push(s, str[i]);
        }
        else if (str[i] == ')')
        {
            if (is_empty(s) || pop(s) != '(')
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (is_empty(s) || pop(s) != '[')
            {
                return false;
            }
        }
        i++;
    }
    return is_empty(s);
}



