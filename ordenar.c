#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node* scan_list();
void bubble_sort_list(node* list);
void print_list(node* list);

int main(void)
{
    node* list = scan_list();
    bubble_sort_list(list);
    print_list(list);
}

node* scan_list()
{
    node* head = NULL;

    int value;

    while(scanf("%d", &value) != EOF)
    {
        node* new_node = (node*) malloc(sizeof(node));
        new_node->value = value;
        new_node->next = head;
        head = new_node;
    }

    return head;
}

void print_list(node* list)
{
    node* n = list;

    while (n != NULL)
    {
        printf("%d ", n->value);
        n = n->next;
    }
}

void selection_sort_list(node* list)
{
    node* n = list;

    while (n != NULL)
    {
        int min = n->value;
        node* m = n->next;

        while (m != NULL)
        {
            if (m->value < min->value)
            {
                min = m;
            }

            m = m->next;
        }

        int temp = n->value;
        n->value = min->value;
        min->value = temp;

        n = n->next;
    }
}

