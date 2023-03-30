#include <stdio.h>
#include <stdlib.h>
#define ITEM char
#define TAM 50

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

int palindromo(char s[]) 
{
    TPilha pil;

    create(&pil);

    for(int i = 0; s[i] != '\0'; i++) // empilha as letras enquanto não chegar no fim da string
    {
        push(&pil, s[i]);
    }

    for(int i = 0; s[i] != '\0'; i++) // desempilha as letras e compara com a string original
    {
        if(pop(&pil) != s[i])
        {
            return 0;
        }
    }

    return 1; // se chegou até aqui, é palíndromo
}

int main(void) {
    char palavra[TAM];

    scanf("%s", palavra);
    printf(palindromo(palavra) ? "sim" : "nao");

    return 0;
}
