#include <stdio.h>
#include <stdlib.h>

typedef struct cabeca {
    int valor;
    struct cabeca *dir, *esq;
} cabeca;


cabeca* insere ( cabeca* estr, int valor ) {
    if ( estr == NULL ) {
        cabeca* novo = ( cabeca * ) malloc ( sizeof ( cabeca ) );
        novo -> valor = valor;				////novo vai apontar para o valor e no final vai ser 5
        novo -> esq = novo -> dir = NULL;
        

        printf ( " %d ", valor ); 
        
        return novo;
    }

    if ( valor < estr -> valor) {
        estr -> esq = insere ( estr -> esq, valor );
    } else {
        estr -> dir = insere ( estr -> dir, valor );
    }
    
    return estr;
}

void liberamemoria ( cabeca* estr ) {
if ( estr != NULL ){
    liberamemoria ( estr -> esq );
    liberamemoria ( estr -> dir );
    free(estr);
    }
}

int main() {
    int x[] = {4, 2, 7, 1, 3};
    cabeca* estr = NULL; 			////tem um ponteiro chamado estrutura que guarda o endereço da cabeca

    printf ( "saida:  ");
    

    for ( int i = 0; i < 5; i++ ) {
        estr = insere(estr, x[i]);
    }

    estr = insere ( estr, 5 );
    liberamemoria(estr); 
    estr = NULL;

    return 0;
}