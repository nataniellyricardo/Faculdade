#include <stdio.h>
#include <stdlib.h>

typedef struct cabeca {
    int valor;
    struct cabeca *prox;
} cabeca;

void imprimirLista ( cabeca* lista )
{
    while ( lista != NULL )
    {
        printf ( " %d ", lista -> valor );
        lista = lista -> prox;
    }
    printf ( " \n " );
}

void liberarLista ( cabeca* lista )
{
    cabeca* aux;
    while ( lista != NULL )
    {
        aux = lista;
        lista = lista -> prox;
        free ( aux );
    }
}

void reorderList ( cabeca* lista )
{
    if ( lista == NULL || lista->prox == NULL )
        return;

    int tamanho = 0;
    cabeca* aux = lista;
    while ( aux != NULL )
    {
        tamanho++;
        aux = aux -> prox;
    }

    cabeca* vetor [ tamanho ];  //cria um vetor que guarda ponteiros

    aux = lista;
    int i = 0;
    while ( aux != NULL )
    {
        vetor [ i ] = aux;
        aux = aux -> prox;
        i++;
    }

    int esquerda = 0;
    int direita = tamanho - 1;

    while ( esquerda < direita )
    {
        vetor [ esquerda ] -> prox = vetor [ direita ];
        esquerda++;

        if ( esquerda == direita )
            break;

        vetor [ direita ] -> prox = vetor [ esquerda ];
        direita--;
    }

    vetor [ esquerda ] -> prox = NULL;
}

int main()
{
    int x[] = {1, 2, 3, 4, 5};
    int n = 5;

    cabeca* lista = NULL;
    cabeca* fim = NULL;

    for ( int i = 0; i < n; i++ ) {
        cabeca* novo = ( cabeca* ) malloc ( sizeof ( cabeca ) );
        novo -> valor = x [ i ];
        novo -> prox = NULL;

        if ( lista == NULL ) {
            lista = novo;
            fim = novo;
        } else {
            fim -> prox = novo;
            fim = novo;
        }
    }

    printf ( "1:\n" );
    imprimirLista ( lista );

    reorderList ( lista );

    printf ( "2:\n" );
    imprimirLista ( lista );

    liberarLista ( lista );  //liberar

    return 0;
}
