#include<stdio.h>
#include<stdlib.h>

typedef struct nodo{
    int clave;
    struct nodo *next;
}NODO; 

NODO *crearlista(NODO *lista,int tamano);

void mostrar(NODO *lista);

void promedio(NODO *lista);
int randomInRange(int minimo, int maximo);

NODO *par(NODO *lista, NODO *listapar);

NODO *impar(NODO *lista, NODO *listaimpar);

void encontrar(NODO *lista);

void largo(NODO *lista);

int main(){
    NODO *lista=NULL, *listapar=NULL, *listaimpar=NULL;
    int tamano;
    srand(getpid());
    scanf("%d",&tamano);
    lista=crearlista(lista, tamano);
    promedio(lista);
    mostrar(lista);
    listapar=par(lista,listapar);
    mostrar(listapar);
    listaimpar=impar(lista,listaimpar);
    mostrar(listaimpar);
    encontrar(lista);
    largo(lista);
    return 0;
}

NODO *crearlista(NODO *lista, int tamano){
    NODO *aux= NULL;
    int i,valor;
    for(i=tamano;i>=1;i--){
        aux=(NODO *)malloc(sizeof(NODO));
        aux->clave= randomInRange(0,9);
        aux->next= lista;
        lista= aux;
    }
    return lista;
}

void mostrar(NODO *lista){
    while(lista!=NULL){
        printf("%d ",lista->clave);
        lista=lista->next;
    }
    printf("\n");
}

void promedio(NODO *lista){
    int suma,count=0;
    float prom;
    while(lista!=NULL){
        suma=suma+lista->clave;
        lista=lista->next;
        count++;
    }
    prom=(float)suma/(float)count;
    printf("\nel promedio de la lista es %f\n",prom);
}

int randomInRange(int minimo, int maximo){
    int numero=minimo+rand()/(RAND_MAX/(maximo - minimo + 1) + 1);
    return numero;
}

NODO *par(NODO *lista, NODO *listapar){
    NODO *aux= NULL;
    while(lista!=NULL){
        if ((lista->clave)%2==0){
            aux=(NODO *)malloc(sizeof(NODO));
            aux->clave= lista->clave;
            aux->next= listapar;
            listapar = aux;
        }
        lista=lista->next;
    }
    return listapar;
}

NODO *impar(NODO *lista, NODO *listaimpar){
    NODO *aux= NULL;
    while(lista!=NULL){
        if ((lista->clave)%2!=0){
            aux=(NODO *)malloc(sizeof(NODO));
            aux->clave= lista->clave;
            aux->next= listaimpar;
            listaimpar = aux;
        }
        lista=lista->next;
    }
    return listaimpar;
}

void encontrar(NODO *lista){
    
    int count=0,posicion;
    printf("\nque posicion quiere ver?\n");
    scanf("%d",&posicion);
    while (lista!=NULL){
        if (count==posicion){
            printf("El elemento que contiene la lista en la posicion %d es %d",posicion,lista->clave);
        }
        count++;
        lista=lista->next;
    }
}

void largo(NODO *lista){
    int contador=0;
    while(lista!=NULL){
        contador++;
        lista=lista->next;
    }
    printf("\nel largo de la lista es de %d\n", contador);
}