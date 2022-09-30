#include<stdio.h>
#include<stdlib.h>

typedef struct lista{
    int clave;
    struct lista *sig;

}lista_t;


void recorridoRecu(lista_t *L, int *suma){
    if(L!=NULL){
        printf("%d, ", L->clave);
        *suma = *suma + L->clave;
        recorrer(L->sig, suma);
    }
}

int main(){

    lista_t *L;
    lista_t *p;
    L = NULL;
    int suma; 

    int i;
    for(i=4;i>=1;i--){
        p = (lista_t *) malloc(sizeof(lista_t));
        p->clave = i;
        p->sig = L;
        L = p;
    }

    p = L;
    suma = 0;
    while (p != NULL) {
        printf("%d, ", p->clave);
        suma = suma + p->clave;
        p = p->sig;
    }

    return 0;
}   