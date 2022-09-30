#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define limit 30
void lectura(int *filas, int *columnas);

int main(){
    int i,filas,columnas,len;
    lectura(&filas, &columnas);
    printf("%d %d",filas,columnas);
    
    return 0;
}

void lectura(int *filas, int *columnas){
    FILE *archivo;
    int i;
    archivo=fopen("sopaletras.txt", "r");
    fscanf(archivo, "%d %d",filas, columnas);
}
