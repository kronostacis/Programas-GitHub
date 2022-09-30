#include<stdio.h>
#include<stdlib.h>

typedef struct Lista{
    int clave;
    struct Lista *next;
}Lista;

Lista *Crearlista(Lista *lista, int largo);
void mostrar(Lista *lista);
Lista *agregarenpos(Lista *lista,int posicion);
Lista *delete(Lista *lista,int posicion);


int main(){
    Lista *lista =NULL,*prueba=NULL;
    lista=Crearlista(lista,5);
    mostrar(lista);
    lista=delete(lista,3);
    //prueba=agregarenpos(lista,3);
    //mostrar(prueba);
    mostrar(lista);
    return 0;
}


Lista *Crearlista(Lista *lista, int largo){
    Lista *aux= NULL;
    int i,valor;
    for(i=0;i<largo;i++){
        scanf("%d",&valor);
        aux=(Lista *)malloc(sizeof(Lista));
        aux->clave=valor;
        aux->next=lista;
        lista=aux;
    }
    return lista;
}
void mostrar(Lista *lista){
    while(lista!=NULL){
        printf("%d",lista->clave);
        lista=lista->next;
    }
    printf("\n");
}

Lista *agregarenpos(Lista *lista,int posicion){
    Lista *aux= NULL, *rev=lista, *aux1=NULL,*xd=NULL,*aux2=NULL;
    int contador=0,valor;
    scanf("%d",&valor);
    while (rev!=NULL){
        if (contador!=posicion){
            aux1=(Lista *)malloc(sizeof(Lista));
            aux1->clave=rev->clave;
            aux1->next=xd;
            xd= aux1;

        }
        else if (posicion==contador){
            break;
        }
        contador++;
        rev=rev->next;
    }
    
    aux=(Lista *)malloc(sizeof(Lista));
    aux->clave=valor;
    aux->next=rev;
    return aux;
}

Lista *delete(Lista *lista,int posicion){
    int pos=0;
    Lista *aux=lista;
    while (pos<(posicion-1)){
        aux=aux->next;
        pos++;
    }
    Lista *a= NULL;
    a=aux->next;
    aux->next=a->next;
    free(a);
    return lista;
}
