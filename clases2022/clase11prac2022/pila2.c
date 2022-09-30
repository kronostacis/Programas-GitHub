#include<stdio.h>
#include<stdlib.h>

typedef struct Pila{
    int clave;
    struct Pila *next;
}Pila;

Pila *apilar(Pila *pila,int largo);
void mostrar(Pila *pila);
Pila *desapilar(Pila *pila);


int main(){
    Pila *pila=NULL;
    int largo,i;
    printf("introduzca el largo de la pila porfavor\n");
    scanf("%d",&largo);
    pila=apilar(pila,largo);
    mostrar(pila);
    pila = desapilar(pila);
    mostrar(pila);
    return 0;
}

Pila *apilar(Pila *pila, int largo){
    Pila *aux = NULL;
    int i=0,valor;
    for ( i = 0; i < largo; i++){
        scanf("%d",&valor);
        if (pila==NULL){
            aux=(Pila *)malloc(sizeof(Pila));
            aux->clave=valor;
            aux->next=pila;
            pila=aux;
        }
        else{
            if (valor > (pila->clave)){
                aux=(Pila *)malloc(sizeof(Pila));
                aux->clave=valor;
                aux->next=pila;
                pila=aux;
            }
            else{
                printf("El valor del elemento dado es menor que el ultimo ingresado");
                break;
            }
        }
    }
    return pila;
}

void mostrar(Pila *pila){
    while(pila!=NULL){
        printf("%d ",pila->clave);
        pila=pila->next;
    }
    printf("\n");
}

Pila *desapilar(Pila *pila){
    pila=pila->next;
    return pila;
}