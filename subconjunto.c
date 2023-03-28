#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node* scan_list();
bool is_subconjunto(node* list1, node* list2);
bool is_in_list(int value, node* list);
void print_list(node* list);


int main(void)
{
    node* list1 = scan_list();
    node* list2 = scan_list();


    if (is_subconjunto(list2, list1))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }
}

node* scan_list()
{
    int size;

    scanf("%d", &size);

    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;

    for (int i = 0; i < size; i++)
    {
        int value;
        scanf("%d", &value);

        node* new_node = (node*) malloc(sizeof(node));
        new_node->value = value;
        new_node->next = n;
        n = new_node;
    }

    return n;
}

bool is_subconjunto(node* list1, node* list2)
{
    node* n = list1;

    while (n != NULL)
    {
        if (!is_in_list(n->value, list2))
        {
            return false;
        }

        n = n->next;
    }

    return true;
}

bool is_in_list(int value, node* list)
{
    node* n = list;

    while (n != NULL)
    {
        if (n->value == value)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

void print_list(node* list)
{
    node* n = list;

    while (n != NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }

    printf("\n");
}