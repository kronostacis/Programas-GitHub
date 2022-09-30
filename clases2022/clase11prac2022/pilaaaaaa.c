#include<stdio.h>
#include<stdlib.h>

typedef struct Pila{
    int clave;
    struct Pila *next;
}Pila;

Pila *apilar(Pila *pila, int elem);
Pila *desapilar(Pila *pila);
void mostrar(Pila *pila);


int main(){
    Pila *pila=NULL;
    pila=apilar(pila, 1);
    pila=apilar(pila, 2);
    pila=apilar(pila, 3);
    pila=apilar(pila, 4);
    pila=apilar(pila, 5);

    mostrar(pila);
    pila = desapilar(pila);
    pila = desapilar(pila);
    mostrar(pila);
    return 0;
}

Pila *apilar(Pila *pila, int elem){
    Pila *aux = NULL;
    aux = (Pila *)malloc(sizeof(Pila));
    aux->clave= elem;
    
    if (pila == NULL){
        pila = aux;
        aux -> next= NULL;
    }
    else{
        aux->next= pila;
        pila=aux;
    }
    return pila;
}

Pila *desapilar(Pila *pila){
    if (pila == NULL){
        return NULL;
    }
    else{
        pila=pila ->next;
    }
    return pila;
}

void mostrar(Pila *pila){
    while(pila!=NULL){
        printf("%d ",pila->clave);
        pila = pila->next;
    }
    printf("\n");
}