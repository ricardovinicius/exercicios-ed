#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int value;
    struct node* next;
} node;

node* scan_list();
node* find_intersection(node* list1, node* list2);
bool is_in_list(int value, node* list);
void print_list(node* list);

int main(void)
{
    node* list1 = scan_list();
    node* list2 = scan_list();


    node* intersection = find_intersection(list1, list2);

    print_list(intersection);
    printf("\n");

    return 0;
}

node* scan_list()
{
    int size = 20;

    node* head = NULL;
    node* tail = NULL;

    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);

        node* new_node = (node*)malloc(sizeof(node));
        new_node->value = value;
        new_node->next = NULL;

        if (tail == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

node* find_intersection(node* list1, node* list2)
{
    node* n = list1;
    node* intersection = NULL;

    while (n != NULL) {
        if (is_in_list(n->value, list2)) {
            node* new_node = (node*)malloc(sizeof(node));
            new_node->value = n->value;
            new_node->next = intersection;
            intersection = new_node;
        }
        n = n->next;
    }

    return intersection;
}

bool is_in_list(int value, node* list)
{
    node* n = list;

    while (n != NULL) {
        if (n->value == value) {
            return true;
        }
        n = n->next;
    }

    return false;
}

void print_list(node* list)
{
    node* n = list;
    int arr[20];
    int i = 0;

    if(n == NULL) {
        printf("VAZIO");
        return -1;
    }

    while (n != NULL && i < 20) {
        arr[i] = n->value;
        n = n->next;
        i++;
    }

    int size = i;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int previous = arr[0];
    printf("%d\n", previous);

    for (int i = 1; i < size; i++) 
    {
        while (i < size && arr[i] == previous) 
        {
            i++;
        }
        if (i < size) {
            printf("%d\n", arr[i]);
            previous = arr[i];
        }
    }

}



