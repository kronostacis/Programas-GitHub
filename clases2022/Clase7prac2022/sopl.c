#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    FILE* f  = NULL;
    int filas, columnas;
    int i,j,k,l;
    char cadena[40],aux;
    char **matriz=NULL;
    int numPalabras;
    int tamano, contador;

    //Apertura del archivo
    char* nombreAr = "sopaletras.txt";
    f = fopen(nombreAr,"r");
    if(f==NULL){
        printf("No se ha podido abrir el archivo\n");
        return -1;
    }
    else{
        printf("Archivo abierto correctamente\n");
    }

    //Lectura de las dimensiones de la sopa
    fscanf(f,"%d %d",&filas,&columnas);
    printf("Las dimensiones de mi sopa son: %d filas y %d columnas\n", filas, columnas);


    //Una vez que tengo las dimensiones, pido memoria para mi matriz de char
    matriz = (char **)malloc(sizeof(char*)*filas);
    for(i=0;i<filas;i++){
        matriz[i]= (char*)malloc(sizeof(char)*columnas);
    }

    for(i=0;i<filas;i++){
        fscanf(f," %[^\n]",&cadena); //Mejorable: cadena podr�a utilizarse con memoria din�mica
        //printf("%s\n",cadena);
        for(j=0;j<columnas;j++){
            matriz[i][j]=cadena[j];
        }
    }

    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%c",matriz[i][j]);
        }
        printf("\n");
    }
}