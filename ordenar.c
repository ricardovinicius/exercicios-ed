#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
}node;

node* scan_list();

int main(void)
{

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


