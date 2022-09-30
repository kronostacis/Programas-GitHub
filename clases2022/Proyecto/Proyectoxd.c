// Programa creado por Diego Muñoz y Benjamin Villablanca

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct Listacir{
    int clave;
    struct Listacir *next;
    struct Listacir *prev;
}Lista;

typedef struct ListaNormal{
    int clave;
    struct ListaNormal *next;
}Lista_elems;

Lista *insertarelem(Lista *list, int n);
void imprimirCirculo(Lista *list);
void mostrarhorario(Lista *lis);
void mostrarantihorario(Lista *lis);
Lista *delete(Lista *lista,int posicion);
Lista_elems *append(Lista_elems *Lista_base, int agregar);
void imprimir_lista(Lista_elems *lista_p);

int main(){
    Lista *list=NULL;
    Lista_elems *n = NULL, *k = NULL, *m = NULL;
    
    
    list=insertarelem(list,10);
    mostrarhorario(list);
    mostrarantihorario(list);
    list=delete(list,0);
    list=delete(list,0);
    list=delete(list,0);
    mostrarhorario(list);
    mostrarantihorario(list);
    return 0;
}

Lista *insertarelem(Lista *list, int n){
    Lista *aux= NULL;
    int n1;
    for(n1=1;n1<=n;n1++){
        if (list == NULL){
            aux=(Lista *)malloc(sizeof(Lista));
            aux->clave=n1;
            aux->next=aux->prev= aux;
            list = aux;
        }
        else{
            Lista *ultimo=list->prev;
            aux=(Lista *)malloc(sizeof(Lista));
            aux->clave=n1;
            aux->next=list;
            list->prev=aux;
            aux->prev=ultimo;
            ultimo->next=aux;
        }
    }
    return list;
}

void imprimirCirculo(Lista *list){
    Lista *aux;
    int primero;
    bool pause = 'F';
    aux = list;
    while (pause == 'F')
    {
        if (aux->clave == primero){
            pause = 'V';
        }
        else{
            printf("%d\n",aux->clave);
            aux = aux->next;
        }
    }
}

void mostrarhorario(Lista *lis){
    Lista *ultimo=lis->prev;
    while(lis!=ultimo){
        printf("%d ",lis->clave);
        lis=lis->next;
    }
    printf("%d",ultimo->clave);
    printf("\n");
}

void mostrarantihorario(Lista *lis){
    /*Lista *primero=lis;
    Lista *aux=lis;
    while(aux!=primero){
        aux=aux->prev;
        printf("%d",aux->clave);
    }
    printf("%d",primero->clave);*/

    Lista *primero=lis;
    Lista *aux=lis;
    do
    {
        aux=aux->prev;
        printf("%d ",aux->clave);

    } while (aux!=primero);
    printf("\n");
}

Lista *delete(Lista *lista,int posicion){
    int pos=0;
    Lista *a= NULL, *b=NULL, *c=NULL;
    Lista *aux=lista, *ultimo=lista->prev;
    
    if (posicion==0){
        a=aux->next;
        b=aux->prev;
        b->next=a;
        a->prev=b;
        lista=lista->next;
        free(aux);
    }
    else{
        while (pos<(posicion-1)){
        aux=aux->next;
        pos++;
        }
        if (aux==ultimo){
            a=aux->next;
            b=aux->prev;
            b->next=a;
            a->prev=b;
            free(aux);
        }
        else{
            a=aux->next;
            aux->next=a->next;
            aux=aux->next;
            b=aux->prev;
            aux->prev=b->prev;
            free(b);
        }
    }
    return lista;
}

Lista_elems *append(Lista_elems *Lista_base, int agregar){
    Lista_elems *nuevalista, *aux;
    nuevalista = (Lista_elems*)malloc(sizeof(Lista_elems));
    nuevalista->clave = agregar;
    nuevalista->next = NULL;
    if (Lista_base == NULL){
        Lista_base = nuevalista;
        printf("%d,",Lista_base->clave);
    } else{
        aux = Lista_base;
        while(aux->next != NULL){
            aux = aux->next;
            //aux->next = nuevalista;
        }
        aux->next=nuevalista;
    }
    return Lista_base;
}

void imprimir_lista(Lista_elems *lista_p){
    Lista_elems *actual;
    actual = lista_p;

    while (actual != NULL){
        printf("%d,",actual->clave);
        actual = actual->next;
    }
    printf("\n");
}