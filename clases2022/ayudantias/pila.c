#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int clave;
    struct nodo *next;
}nodo;

nodo *crear(nodo *p);
int isempty(nodo *p);
nodo *push(nodo *p, int n);
nodo *pop(nodo *p);
int top(nodo *p);
int tam(nodo *p, int n);

int main(){
    nodo *p;
    int profundidad;
    p=crear(p);
    p=push(p,1);
    p=push(p,2);
    p=push(p,3);
    p=push(p,4);
    p=pop(p);
    profundidad = tam(p, 0);
    printf("%d ", profundidad);
    return 0;
}

nodo *crear(nodo *p){
    p = NULL;
    return p;
}

int isempty(nodo *p){
    if(p == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

nodo *push(nodo *p, int n){
    
    nodo *pila;
    pila=(nodo *)malloc(sizeof(nodo));
    pila->clave=n;
    if(isempty(p)==1){
        pila->next=NULL;
        p=pila;
    }
    else{
        pila->next=p;
        p=pila;
    }
    return p;
}

nodo *pop(nodo *p){

    if (isempty(p)==1){
        return p;
    }
    else{
        p=p->next;
        return p;
    }
}
int top(nodo *p){
    
    return p->clave;
}

int tam(nodo *p, int n){
    
    if (isempty(p)==1){
        return n;
    }
    return tam(p->next,n+1);
}