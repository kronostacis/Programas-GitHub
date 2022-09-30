#include<stdio.h>
#include<stdlib.h>

typedef struct cola{
   int clave;
   struct cola *sig;

}cola_t;

void crearCola(cola_t **cola);
int esVacia(cola_t *cola);
void encolar(cola_t **cola, int elem);
void desencolar(cola_t **cola, int *elem);
void mostrar(cola_t *cola);


int main(){
    cola_t *cola;
    int elem=3;

    crearCola(&cola);
    if(esVacia(cola)){
        printf("Cola vacia!\n");
    }
    encolar(&cola, 3);
    encolar(&cola, 4);
    mostrar(cola);
    desencolar(&cola,&elem);
    mostrar(cola);
    return 0;
}

void crearCola(cola_t **cola){
    *cola = NULL;
}

int esVacia(cola_t *cola){
    return (cola==NULL);
}

void encolar(cola_t **cola, int elem){
    cola_t *nuevo;
    nuevo = (cola_t *)malloc(sizeof(cola_t));
    nuevo->clave = elem;
    if(*cola == NULL){
        *cola=nuevo;
        nuevo->sig = NULL;
    }
    else{
        nuevo->sig = (*cola);
        (*cola)->sig = NULL;
        (*cola) = nuevo;
    }
    
}

void desencolar(cola_t **cola, int *elem){
    cola_t *aux;

    *elem = (*cola)->sig->clave;
    if((*cola) == (*cola)->sig){
        free(*cola);
        *cola = NULL;
    }
    else{
        aux = (*cola)->sig;
        (*cola)->sig = aux->sig;
        free(aux);
    }
}

void mostrar(cola_t *cola){
    while(cola!=NULL){
        printf("%d",cola->clave);
        cola = cola->sig;
    }
    printf("\n");
}