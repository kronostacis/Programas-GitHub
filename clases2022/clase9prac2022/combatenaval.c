#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void batalla(int filas, int columnas, char **matriz1, char **matriz2, int *vidas1, int *vidas2,int jugador);
int randomInRange(int minimo, int maximo);

int main(){

    FILE* miArchivo1  = NULL;
    FILE* miArchivo2  = NULL;
    int filas1, columnas1,vidas1;
    int filas2, columnas2,vidas2;

    int i, j;

    char *cadena1=NULL;
    char *cadena2=NULL;
    char **matriz1=NULL;
    char **matriz2=NULL;

    //Apertura del archivo
    char* nombreAr1 = "player1.txt";
    miArchivo1 = fopen(nombreAr1,"r");
    if(miArchivo1==NULL){
        printf("No se ha podido abrir el archivo\n");
        return -1;
    }
    else{
        printf("Archivo abierto correctamente\n");
    }

    //Primera lectura de dimensiones y vida
    fscanf(miArchivo1,"%d %d",&filas1,&columnas1);
    fscanf(miArchivo1,"%d",&vidas1);

    cadena1= malloc(sizeof(char)*columnas1);

    matriz1 = (char **)malloc(sizeof(char*)*filas1);
    for(i=0;i<filas1;i++){
        matriz1[i]= (char*)malloc(sizeof(char)*columnas1);
    }

    for(i=0;i<filas1;i++){
        fscanf(miArchivo1,"%s\0",cadena1);
        //printf("%s",cadena1);
        for(j=0;j<columnas1;j++){
            matriz1[i][j]=cadena1[j];
        }
    }
    fclose(miArchivo1);
    for(i=0;i<filas1;i++){
        for(j=0;j<columnas1;j++){
            printf("%c",matriz1[i][j]);
        }
        printf("\n");
    }

// segunda lectura de archivos 
    char* nombreAr2 = "player2.txt";
    miArchivo2 = fopen(nombreAr2,"r");
    if(miArchivo2==NULL){
        printf("No se ha podido abrir el archivo\n");
        return -1;
    }
    else{
        printf("Archivo abierto correctamente\n");
    }

    //Primera lectura de dimensiones y vida
    fscanf(miArchivo2,"%d %d",&filas2,&columnas2);
    fscanf(miArchivo2,"%d",&vidas2);

    cadena2= malloc(sizeof(char)*columnas2);

    matriz2 = (char **)malloc(sizeof(char*)*filas2);
    for(i=0;i<filas2;i++){
        matriz2[i]= (char*)malloc(sizeof(char)*columnas2);
    }

    for(i=0;i<filas2;i++){
        fscanf(miArchivo2,"%s\0",cadena2);
        //printf("%s",cadena1);
        for(j=0;j<columnas2;j++){
            matriz2[i][j]=cadena2[j];
        }
    }



    for(i=0;i<filas2;i++){
        for(j=0;j<columnas2;j++){
            printf("%c",matriz2[i][j]);
        }
        printf("\n");
    }

    srand(getpid());
    int nAleatorio=randomInRange(0,1);
    while (vidas1>0 || vidas2>0){

    
    if (nAleatorio==0){
            printf("Turno del jugador %d\n",nAleatorio+1);
            batalla(filas1,columnas1,matriz1,matriz2,&vidas1,&vidas2,nAleatorio);
            nAleatorio=1;
        }
        else if(nAleatorio==1){
            printf("Turno del jugador %d\n",nAleatorio+1);
            batalla(filas1,columnas1,matriz1,matriz2,&vidas1,&vidas2,nAleatorio);
            nAleatorio=0;
        }
    }
    return 0;
}

void batalla(int filas, int columnas, char **matriz1, char **matriz2, int *vidas1, int *vidas2,int jugador){
    int repetir=0;
    while (repetir ==0){
        if (jugador==0){
            printf ("introduzca fila y columna:\n");
            scanf("%d %d",&filas,&columnas);
            if (*(*(matriz2 + filas) + columnas)=='1'){
                *(*(matriz2 + filas) + columnas)='X';
                printf("nave abatida\n");
                vidas2=*vidas2-1;
                printf("al jugador 2 le quedan %d vidas\n",vidas2);
                repetir=1;
            }
            else if (*(*(matriz2 + filas) + columnas)=='0'){
                printf("Ninguna nave fue abatida\n");
                vidas1=*vidas1-1;
                repetir=1;
            }

            else if (*(*(matriz2 + filas) + columnas)=='X'){
            printf("Esa zona ya fue abatida\nRepita porfavor\n");
            repetir=0;
            }
        }
        else if (jugador==1){
            printf ("introduzca fila y columna:\n");
            scanf("%d %d",&filas,&columnas);
            if (*(*(matriz1 + filas) + columnas)=='1'){
                *(*(matriz1 + filas) + columnas)='X';
                printf("nave abatida\n");
                
                vidas1=*vidas1-1;
                printf("al jugador 1 le quedan %d vidas\n",vidas1);
                repetir=1;
            }
            else if (*(*(matriz1 + filas) + columnas)=='0'){
                printf("Ninguna nave fue abatida\n");
                vidas2=*vidas2-1;
                repetir=1;
            }

            else if (*(*(matriz1 + filas) + columnas)=='X'){
            printf("Esa zona ya fue abatida\n Repita porfavor\n");
            repetir=0;
            }
        }
    }
}

int randomInRange(int minimo, int maximo){

    int numero=minimo+rand()/(RAND_MAX/(maximo - minimo + 1) + 1);
    return numero;
}