#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cabeca {
    int valor;
    struct cabeca *prox;
} cabeca;


int compara( int a, int b )
{
    char x[30], y[30];

    sprintf ( x, "%d%d", a, b );
    sprintf ( y, "%d%d", b, a );

    return strcmp ( x, y );
}


cabeca* insere ( cabeca* lista, int novoValor )
{
    cabeca *novo = ( cabeca* ) malloc ( sizeof ( cabeca ) );
    novo -> valor = novoValor;
    novo -> prox = NULL;

    if (lista == NULL || compara ( novoValor, lista -> valor ) > 0 )
    {
        novo -> prox = lista;
        return novo;
    }

    cabeca *aux = lista;

    while ( aux -> prox != NULL && compara ( novoValor, aux-> prox-> valor ) <= 0 )
    {
        aux = aux -> prox;
    }

    novo -> prox = aux -> prox;
    aux -> prox = novo;

    return lista;
}


char* imprimir ( cabeca* lista )
{
    char *resultado = malloc ( 100 );
    resultado [ 0 ] = '\0';

    while ( lista != NULL )
    {
        char teste [ 20 ];
        sprintf ( teste, "%d", lista -> valor );
        strcat ( resultado, teste );

        lista = lista -> prox;
    }

    return resultado;
}


void liberamemoria ( cabeca* lista )
{
    cabeca* aux;
    while ( lista != NULL )
    {
        aux = lista;
        lista = lista -> prox;
        free ( aux );
    }
}


int main ( )
{
    int v[] = {2, 10};

    cabeca* lista = NULL;

    for ( int i = 0; i < 2; i++ )
        lista = insere ( lista, v[i] );

    char *convert = imprimir ( lista );

    printf ( "%s\n", convert );

    free(convert);
    liberamemoria ( lista );

    return 0;
}
