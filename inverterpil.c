#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 100

typedef struct pilha {
    ITEM vet[TAM];
    int topo;
} TPilha;

void create(TPilha *p) {
    p->topo = -1;
}

void destroy(TPilha *p) {
    p->topo = -1;
}

int isfull(TPilha *p) {
    return p->topo == TAM;
}

int isempty(TPilha *p) {
    return p->topo == -1;
}

void push(TPilha *p, ITEM x) {
    if( isfull(p) ) {
        puts("overflow");
        abort();
    }
    p->topo++;
    p->vet[p->topo] = x;
}

ITEM pop(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    ITEM x = p->vet[p->topo];
    p->topo--;
    return x;
}

ITEM top(TPilha *p) {
    if( isempty(p) ) {
        puts("underflow");
        abort();
    }
    return p->vet[p->topo];
}

void inverte_palavras_frase(char frase[]) 
{
    TPilha* pil = malloc(sizeof(TPilha));

    create(pil);

    int j = 0;
    for(int i = 0; frase[i] != '\0'; i++) 
    {
        if(frase[i] != ' ') 
        {
            push(pil, frase[i]);
        } 
        else 
        {
            while(!isempty(pil)) 
            {
                frase[j] = pop(pil);
                j++;
            }
            frase[j] = ' ';
            j++;
        }
    }

    while(!isempty(pil)) 
    {
        frase[j] = pop(pil);
        j++;
    }

    frase[j] = '\0';

    destroy(pil);
    free(pil);
}



int main(void) {
    char frase[TAM];

    gets(frase);
    printf("original = %s\n", frase);
    inverte_palavras_frase(frase);
    printf("invertida = %s\n", frase);
    
    return 0;
}
