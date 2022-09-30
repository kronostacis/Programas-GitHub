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
void mostrarhorario(Lista *lis);
void mostrarantihorario(Lista *lis);
Lista *delete(Lista *lista,Lista *borrar);
Lista_elems *append(Lista_elems *Lista_base, int agregar);
void imprimir_lista(Lista_elems *lista_p);
Lista *delete_down(Lista *lista,int posicion);

int main(){
    Lista *list=NULL;
    Lista_elems *n = NULL, *k = NULL, *m = NULL,*n_actual, *k_actual, *m_actual;
    FILE *archivo = NULL, *salida = NULL;
    bool pause = false; 
    char *nombrear = "guardias.in";
    char *nombresalida = "guardias.out";
    archivo = fopen(nombrear,"r");
    if (archivo == NULL){
        printf("Error al abrir el archivo");
    }
    do{
        int num1,num2,num3;
        fscanf(archivo,"%d %d %d",&num1,&num2,&num3);
        if ((num1 == 0) && (num2 == 0) && (num3 == 0)){
            pause = true;
        }
        else{
            n = append(n,num1);
            k = append(k,num2);
            m = append(m,num3);
        }
    }while (pause == false);
    fclose(archivo);

    salida = fopen(nombresalida,"w");

    n_actual = n;
    k_actual = k;
    m_actual = m;

    while (n_actual != NULL)
    {
        Lista *circulo = NULL,*guardia_k,*guardia_m,*borrar_k,*borrar_m;
        circulo = insertarelem(circulo,n_actual->clave);
        guardia_k = circulo;
        guardia_m = circulo->prev;
        while(circulo != NULL){
            int i,kvalor,mvalor;
            for(i=1;i<(k_actual->clave);i++){
                guardia_k = guardia_k->next;
            }
            for(i=1;i<(m_actual->clave);i++){
                guardia_m = guardia_m->prev;
            }
            kvalor = guardia_k->clave;
            mvalor = guardia_m->clave;
            borrar_k = guardia_k;
            borrar_m = guardia_m;
            guardia_k = guardia_k->next;
            guardia_m = guardia_m->prev;

            if(guardia_k == borrar_m){
                guardia_k = guardia_k->next;
                guardia_m = guardia_m->prev;
            }
            if (borrar_k==borrar_m){
                if((circulo->prev)==circulo){
                    fprintf(salida,"%d",kvalor);
                }else{
                    fprintf(salida,"%d,",kvalor);
                }
                circulo = delete(circulo,borrar_k);
                }
            else{
                if((circulo->prev)==(circulo->next)){
                    fprintf(salida,"%d %d",kvalor,mvalor);                 
                } else{
                    fprintf(salida,"%d %d,",kvalor,mvalor);
                }
                circulo = delete(circulo,borrar_k);
                circulo = delete(circulo,borrar_m);
            }
        }
        fprintf(salida,"\n");
        n_actual = n_actual->next;
        k_actual = k_actual->next;
        m_actual = m_actual->next;
    }
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

    Lista *primero=lis;
    Lista *aux=lis;
    do
    {
        aux=aux->prev;
        printf("%d ",aux->clave);

    } while (aux!=primero);
    printf("\n");
}

Lista *delete(Lista *lista,Lista *borrar){
    Lista *devolver = lista;
    if(((devolver->prev)==devolver)&&((devolver->next)==devolver)){
        return NULL;
    }
    else if (lista == borrar){
        devolver = devolver->next;
        (borrar->prev)->next = borrar->next;
        (borrar->next)->prev = borrar->prev;
        free(borrar);
        return devolver;
    }
    else{
        (borrar->prev)->next = borrar->next;
        (borrar->next)->prev = borrar->prev;
        free(borrar);
        return devolver;
    }
}

Lista_elems *append(Lista_elems *Lista_base, int agregar){
    Lista_elems *nuevalista, *aux;
    nuevalista = (Lista_elems*)malloc(sizeof(Lista_elems));
    nuevalista->clave = agregar;
    nuevalista->next = NULL;
    if (Lista_base == NULL){
        Lista_base = nuevalista;
    } else{
        aux = Lista_base;
        while(aux->next != NULL){
            aux = aux->next;
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