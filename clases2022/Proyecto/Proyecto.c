/*Se pide un código que vaya sacando a n guardias formados en circulos donde dos encargados
los van distribuyendo seleccionando en k y m cada uno respectivamente, sacandolos del circulo y repitiendo
Código creado por Diego Muñoz (21.205.889-0) y Benjamín Villablanca (21.046.300-3)
11 de Julio de 2022*/

#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

//Lista circular
typedef struct Listacir{
    int clave;
    struct Listacir *next;
    struct Listacir *prev;
}Lista;

//Lista enlazada
typedef struct ListaNormal{
    int clave;
    struct ListaNormal *next;
}Lista_elems;

Lista *rellenarciculo(Lista *list, int n);
void mostrarhorario(Lista *lis);
void mostrarantihorario(Lista *lis);
Lista *delete(Lista *lista,Lista *borrar);
Lista_elems *append(Lista_elems *Lista_base, int agregar);
void imprimir_lista(Lista_elems *lista_p);
Lista *delete_down(Lista *lista,int posicion);

int main(){
    Lista *list=NULL;
    //Se guardara en listas los diferentes valores de n, k y m que vienen en el archivo de salida
    Lista_elems *n = NULL, *k = NULL, *m = NULL,*n_actual, *k_actual, *m_actual;
    FILE *archivo = NULL, *salida = NULL;
    bool pause = false; 
    char *nombrear = "guardias.in";
    char *nombresalida = "guardias.out";
    archivo = fopen(nombrear,"r");
    if (archivo == NULL){
        printf("Error al abrir el archivo\n");
        return 1;
    }
    do{
        //Se escanea cada termino y se añaden a las listas
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

    //controlan el elemento en el que va de n,k y m
    n_actual = n;
    k_actual = k;
    m_actual = m;

    //Recorre por elemento de las listas de n hasta que no queden elementos
    while (n_actual != NULL)
    {
        Lista *circulo = NULL,*guardia_k,*guardia_m,*borrar_k,*borrar_m;
        //se genera el circulo de guardias
        circulo = rellenarciculo(circulo,n_actual->clave);
        //se asigna de donde parten escogiendo
        guardia_k = circulo;
        guardia_m = circulo->prev;
        //se repite hasta que no hayan guardias en el circulo
        while(circulo != NULL){
            int i,kvalor,mvalor;
            //se asigna el guardia que sale
            for(i=1;i<(k_actual->clave);i++){
                guardia_k = guardia_k->next;
            }
            for(i=1;i<(m_actual->clave);i++){
                guardia_m = guardia_m->prev;
            }
            //numero seleccionado
            kvalor = guardia_k->clave;
            mvalor = guardia_m->clave;
            //valor que se va a borrar
            borrar_k = guardia_k;
            borrar_m = guardia_m;
            //punto de partida siguiente
            guardia_k = guardia_k->next;
            guardia_m = guardia_m->prev;

            //Si es que se solapan el borrado de m con el siguiente de k y viceversa
            if(guardia_k == borrar_m){
                guardia_k = guardia_k->next;
                guardia_m = guardia_m->prev;
            }
            //Se selecciona uno
            if (borrar_k==borrar_m){
                if((circulo->prev)==circulo){
                    fprintf(salida,"%d",kvalor);
                }else{
                    fprintf(salida,"%d,",kvalor);
                }
                circulo = delete(circulo,borrar_k);
                }
            //se seleccionan 2
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
    fclose(salida);
    printf("Codigo ejecutado correctamente, revisar el archivo guardias.out\n");
    return 0;
}

//rellena el circulo con numeros de 1 a n
Lista *rellenarciculo(Lista *list, int n){
    Lista *aux= NULL;
    int n1;
    for(n1=1;n1<=n;n1++){
        // Inserta el primer elemento del circulo
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

//imprime la lista doblemente enlazada
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

//Borra un elemento de la lista doblemente enlazada
Lista *delete(Lista *lista,Lista *borrar){
    Lista *devolver = lista;
    if((devolver->prev)==devolver){
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

//Añade un elemento al final de la lista enlazada
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

//imprime la lista enlazada
void imprimir_lista(Lista_elems *lista_p){
    Lista_elems *actual;
    actual = lista_p;

    while (actual != NULL){
        printf("%d,",actual->clave);
        actual = actual->next;
    }
    printf("\n");
}