#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}
node;

node* scan_list();
void print_list(node* list);
void sort_list(node* list);

int main(void)
{
    node* list = scan_list();
    sort_list(list);
    print_list(list);
}

node* scan_list()
{
    node* n = NULL;
    int buffer;

    while(scanf("%d", &buffer) != EOF)
    {
        node* new_node = (node*)malloc(sizeof(node));
        new_node->data = buffer;
        new_node->next = n;
        n = new_node;
    }

    return n;
}

void print_list(node* list)
{
    node* n = list;

    while(n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }

    printf("\n");

    return;
}

void sort_list(node* list)
{
    //node* selector;
    node* cursor;
    node* n = list;
    node* low;

    while(n != NULL)
    {
        low = n;
        cursor = n->next;

        while(cursor != NULL)
        {
            if(cursor->data < low->data)
            {
                low = cursor;
            }
            cursor = cursor->next;
        }
        int tmp = n->data;
        n->data = low->data;
        low->data = tmp;

        n = n->next;
    }

}