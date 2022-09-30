#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lectura(int *filas, int *columnas, int *vidas,char **matriz);
void imprimir(int filas, int columnas, char  **matriz);
int main(){
    int i,j;
    char player1="player1.txt", player2="player2.txt";
    int filas,columnas,vidas;
    char **matrizp1=NULL, **matrizp2=NULL;
    lectura(&filas,&columnas,&vidas,matrizp1);
    printf("%d %d %d \n", filas, columnas,vidas);
    imprimir(filas, columnas,matrizp1);
  

    return 0;
}

void lectura(int *filas, int *columnas, int *vidas ,char **matriz){
    FILE* f  = NULL;
    
    int fil,col,vid;
    int i,j;
    char aux;
    f = fopen("player1.txt", "r");
    fscanf(f, "%d %d\n", &fil, &col);
    fscanf(f, "%d\n", &vid);
    printf("%d %d %d\n",fil,col,vid);
    *filas=fil;
    *columnas=col;
    *vidas=vid;
    char cadena[col];
    //printf("%d %d \n%d \n", filas, columnas, vidas);
    matriz = (char **)malloc(sizeof(char*)*(fil));
    for(i=0;i<fil;i++){
        *(matriz+i)= (char*)malloc(sizeof(char)*col);
    }

    for(i=0;i<fil;i++){
        fscanf(f,"%s\0",cadena);
        for(j=0;j<col;j++){
            *(*(matriz + i) + j)=cadena[j];    
        }
    }
}

void imprimir(int filas, int columnas, char  **matriz){
    int i,j;
    for(i=0;i<filas;i++){
        printf("|");
        for(j=0;j<columnas;j++){
            printf(" %c |",*(*(matriz + i) + j));
        }
        printf("\n-------------\n");
    }
    printf("\n\n");

}