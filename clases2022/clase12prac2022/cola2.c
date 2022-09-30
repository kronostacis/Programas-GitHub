#include <stdio.h>
#include<stdlib.h>

typedef struct Cola{
    int clave;
    struct Cola *next;
}Cola;
 
Cola * encolar(Cola *cola , int elem);
Cola * desencolar(Cola *cola);
void mostrar(Cola *cola);

int main(){
    Cola *cola=NULL;
    cola=encolar(cola,1);
    cola=encolar(cola,2);
    cola=encolar(cola,3);
    mostrar(cola);
    cola=desencolar(cola);
    mostrar(cola);
    return 0;
}

Cola * encolar(Cola *cola , int elem){
    Cola *aux = NULL, *temp=cola;
    aux=(Cola *)malloc(sizeof(Cola));
    aux->clave=elem;
    if (cola==NULL) {
        cola=aux;
        aux->next=NULL;
    }
    else {
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next=aux;
        aux->next=NULL;
    }
    return cola;
}

Cola * desencolar(Cola *cola){
    Cola *aux=cola;
    if (cola==NULL){
        return NULL;
    }
    else{
        printf("el wn que esta saliendo tiene el numero %d\n",aux->clave);
        cola=cola->next;
    }
    return cola;
}

void mostrar(Cola *cola){
    while(cola!=NULL){
        printf("%d ",cola->clave);
        cola = cola->next;
    }
    printf("\n");
}
