#include <stdio.h>
#include <stdlib.h>

typedef struct num 
{
    int dado;
    struct num* prox, *ant;
} num;

void imprimirLista(num* ini) {
    num* atual = ini;
    while (atual != NULL) {
        printf("%d\n", atual->dado);
        atual = atual->prox;
    }
}

num* outraLista(num* ini) 
{
    num* ant = NULL;
    num* atual = ini;
    num* prox = NULL;

    while (atual != NULL) {
        prox = atual->prox;   
        atual->prox = ant;  
        ant = atual;           
        atual = prox;           
    }

    return ant; 
}

int main() 
{
    
    num* num1 = (num*) malloc(sizeof(num));
    num* num2 = (num*) malloc(sizeof(num));
    num* num3 = (num*) malloc(sizeof(num));

    
    num1->dado = 1;
    num1->prox = num2;

    num2->dado = 2;
    num2->prox = num3;

    num3->dado = 3;
    num3->prox = NULL;

    printf("Primeira lista:\n");
    imprimirLista(num1);

    
    num* segundaLista = outraLista(num1);

    printf("\nSegunda lista:\n");
    imprimirLista(segundaLista);

    
    free(num3);
    free(num2);
    free(num1);

    return 0;
}


