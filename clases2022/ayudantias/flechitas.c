#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int clave;
    float clave2;
    char *name;
    struct Nodo *next;
}Nodo;

int main(){
    Nodo *lista=NULL, *lista2=NULL;
    lista=(Nodo*)malloc(sizeof(Nodo));
    lista2=(Nodo*)malloc(sizeof(Nodo));
    lista->clave=13;
    lista->clave2=3.14;
    lista->name="benjamin";
    lista2->clave=13;
    lista2->clave2=3.14;
    lista2->name="nicolas";
    lista2->next=NULL;
    lista->next=lista2;
    Nodo *aux=lista;
    while(aux!=NULL){   
        printf("%d\n%f\n%s",aux->clave,aux->clave2,aux->name);
        aux=aux->next;
    }
    return 0;
}