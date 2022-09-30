#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *next;
}NODO;

NODO *crearnodo(int dato);
int insertarinit(NODO **cabeza, int dato);
int insertfin(NODO **cabeza, int dato);
void imprimir(NODO *cabeza);
void *Promedio(NODO *cabeza);
void maximo(NODO *cabeza);

int main(){
    NODO *cabeza=NULL;
    int i;
    insertarinit(&cabeza,0);
    for (i=1; i<10; i++){
        insertfin(&cabeza,i);
    }     
    imprimir(cabeza);
    Promedio(cabeza);
    maximo(cabeza);
    return 0;
}

NODO *crearnodo(int dato){
    NODO *new=NULL;
    new= (NODO*)malloc(sizeof(NODO));
    if (new!=NULL){
        new->dato=dato;
        new->next=NULL;
    }
    return new;
}

int insertarinit(NODO **cabeza, int dato){
    NODO *new=NULL;
    new=crearnodo(dato);
    if (new != NULL){
        new->next=*cabeza;
        *cabeza=new;
        return 1;
    }
    return 0;

}

void imprimir(NODO *cabeza){
    NODO *nAUX=cabeza;
    while (nAUX!=NULL){
        printf("%d ", nAUX->dato);
        nAUX=nAUX->next;
    }
}

int insertfin(NODO **cabeza, int dato){
    NODO *new=NULL, *nAUX=*cabeza;
    new=crearnodo(dato);
    if (new!=NULL){
        while (nAUX->next != NULL){
            nAUX=nAUX->next;
        }
        nAUX->next=new;
        return 1;
    }
    return 0;
}
void *Promedio(NODO *cabeza){
    int suma=0,count=0;
    NODO *nAUX=cabeza;
    while (nAUX!=NULL){
        suma=suma+nAUX->dato;
        count++;
        nAUX=nAUX->next;
    }
    printf("\nel promedio de la lista es de %.3f",(float)suma/(float)count);
}

void maximo(NODO *cabeza){
    NODO *nAUX=cabeza;
    int max=0, datos;
    while (nAUX!=NULL){
        if ((nAUX->dato)>=max){
            datos=nAUX->dato;
            max=datos;
        }
        nAUX=nAUX->next;
    }
    printf("\nel numero max de la lista es %d",max);
}