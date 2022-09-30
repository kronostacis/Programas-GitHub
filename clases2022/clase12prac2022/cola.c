#include<stdio.h>
#include<stdlib.h>

typedef struct info{
    char *name;
    char *numero;
    char *rut;
    struct info *next;
}Info;

Info *agregar(Info *cola, char *nombre, char *num, char *CI);
void mostrar(Info *cola);
Info *delete(Info *cola);

int main(){
    Info *cola =NULL;
    cola = agregar(cola, "benjamin","968316401","21046300-3");
    cola = agregar(cola, "jesus", "968538622","20532970-6");
    cola = agregar(cola, "esteban","9685446","21043545-0");
    cola = agregar(cola, "renato", "968538622","20532970-6");
    cola = agregar(cola, "seba","968316401","21046300-3");
    cola = agregar(cola, "diego","9685446","21043545-0");
    cola = delete(cola);
    return 0;
}

Info *agregar(Info *cola, char *nombre, char *num, char *CI){
    Info *aux= NULL;
    aux=(Info *)malloc(sizeof(Info));
    aux->name=nombre;
    aux->numero=num;
    aux->rut=CI;
    aux->next=cola;
    cola = aux;
    return cola;
}

void mostrar(Info *cola){
    while(cola!=NULL){
        printf("nombre: %s, numero: %s, rut: %s \n",cola->name,cola->numero,cola->rut);
        cola=cola->next;
    }
    printf("\n");
}
Info *delete(Info *cola){
    Info *aux=cola, *ayu=NULL;
    while((aux->next)->next!=NULL){
        aux=aux->next;
    }
    ayu=aux->next;
    printf("Persona que esta saliendo de la fila\nnombre: %s\nnumero:%s\nrut:%s\n",ayu->name,ayu->numero,ayu->rut);
    aux->next=NULL;
    free(ayu);
    return cola;    
}