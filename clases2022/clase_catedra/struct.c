#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
  int matricula;
  char name[100];
  int edad;
  int phone;
  int nota;
}hoja;
/*void comprobar(hoja);*/


int main(){
    FILE *f;
    int alumnos;
    int aux;
    hoja f1;
    printf("Bienvenido a mi primera estructura de Datos\n");
    printf("¿Cuantos alumnos son?\n");
    scanf("%d",&alumnos);
    for(aux=0;aux<alumnos;aux++){

        printf("Podrias darme tu numero de matricula\n");
        scanf("%d",&f1.matricula);
        printf("Dame tu nombre porfavor\n");
        scanf("%s",f1.name);
        printf("Dame tu edad\n ");
        scanf("%d",&f1.edad);
        printf("Numero de telefono porfavor\n");
        scanf("%d",&f1.phone);
        printf("Nota final de programacion\n");
        scanf("%d",&f1.nota);
        f=fopen("salida.txt","a");
        fprintf(f,"Matricula: %d\nNombre: %s\nEdad: %d\nTelefono: %d\nNota final: %d\n ------------------------------------------------\n",f1.matricula,f1.name,f1.edad,f1.phone,f1.nota);

    }
    return 0;
}
