#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE* f  = NULL;
    int filas, columnas;
    char aux;
    char **matriz=NULL;
    int i, j;
    f = fopen("sopaletras.txt", "r");
    fscanf(f, "%d %d\n", &filas, &columnas);
    printf("%d %d\n", filas, columnas);
    matriz = (char **)malloc(sizeof(char*)*filas);

    for(i=0;i<filas;i++){
        matriz[i]= (char*)malloc(sizeof(char)*columnas);
    }

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            while (aux!=EOF){
            aux = fgetc(f);
            printf("%c",aux);
        }
            matriz[i][j]=aux;
            printf("%c ",matriz[i][j]);
        }
        //printf("\n");
    }
    
    
    return 0;
}