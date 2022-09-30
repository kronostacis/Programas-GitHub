#include<stdio.h>
#include<stdlib.h>

typedef struct Pila{
    int clave;
    struct Pila *next;
}Pila;

Pila *apilar(Pila *pila, int largo);
void mostrar(Pila *pila);
int primo(int N);
Pila *eliminar(Pila *pila);


int main(){
    Pila *pila=NULL;
    int largo;
    printf("introduzca el largo de la pila porfavor\n");
    scanf("%d",&largo);
    pila=apilar(pila,largo);
    mostrar(pila);
    pila=eliminar(pila);
    mostrar(pila);
    return 0;
}

Pila *apilar(Pila *pila, int largo){
    Pila *aux = NULL;
    int i=0,c=2,valor;
    while(i<largo){
        aux=(Pila *)malloc(sizeof(Pila));
        valor=primo(c);
        if (valor!=0){
            aux->clave=valor;
            aux->next=pila;
            pila=aux;
            i++;
        }
        c++;
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

int primo(int N){
    int c;
    for (c=1;c<N;c++){
        if ((N%c==0) && (c!=N) && (c!=1)){
            return 0;
        }
    } 
    return N;  
}

Pila *eliminar(Pila *pila){
    pila=pila->next;
    return pila;
}