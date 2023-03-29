#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char letra;
    int frequencia;
    struct node *next;
}node;

char* scan_string();
void print_string(char* string);
node* lista_frequencia(char* string);
void print_lista(node* list);

int main(void)
{
    char* string = scan_string();
    //print_string(string);
    node* list = lista_frequencia(string);
    print_lista(list);

}

char* scan_string()
{
    char* str = (char*) malloc(100 * sizeof(char));
    scanf("%[^\n]%*c", str);
    //while(scanf("%s\n", string) != EOF);
    return str;
}

void print_string(char* string)
{
    printf("%s\n", string);
}

node* lista_frequencia(char* string)
{
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;

    for(int asc = 0; asc < 256; asc++)
    {
        int freq = 0;
        for(int i = 0; i < strlen(string); i++)
        {
            if(string[i] == asc)
            {
                freq++;
            }
        }
        if(freq != 0)
        {
            node* new_node = (node*) malloc(sizeof(node));
            new_node->letra = asc;
            new_node->frequencia = freq;
            new_node->next = n;
            n = new_node;
        }
    }

    return n;
}

void print_lista(node* list)
{
    node* n = list;

    while (n != NULL)
    {
        printf("%c %d \n", n->letra, n->frequencia);
        n = n->next;
    }
}
