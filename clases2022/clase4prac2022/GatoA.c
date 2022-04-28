#include<stdio.h>
#include<time.h>
#include<stdlib.h> //permite incluir rand y RAND_MAX
#include<unistd.h>



void imprimeGato(char(*arr)[3]);
void ingresaEntrada(char(*arr)[3], int jugador);
int randomInRange(int minimo, int maximo);

int main(){
    int i,j, jugador;
    char matriz[3][3];
    int nAleatorio;
    srand(getpid());


    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            matriz[i][j]=' ';
        }
    }
    imprimeGato(matriz);
    nAleatorio=randomInRange(0,1);
    int opcion;
    printf("Bienvenido al menu de Gato\n");
    printf("1) Player vs Player\n ");
    printf("2) Contra la maquina\n ");
    printf("3) Contra maquina inteligente\n");
    scanf("%d",&opcion);
    while (opcion == 1){
        if (nAleatorio==0){
            printf("Turno del jugador %d\n",nAleatorio);
            ingresaEntrada(matriz,nAleatorio);
            imprimeGato(matriz);
            nAleatorio=1;
        }
        else if(nAleatorio==1){
            printf("Turno del jugador %d\n",nAleatorio);
            ingresaEntrada(matriz , nAleatorio);
            imprimeGato(matriz);
            nAleatorio=0;
        }
    }
    imprimeGato(matriz);
    return 0;
}


void imprimeGato(char(*arr)[3]){
    int i,j;
    for(i=0;i<3;i++){
        printf("|");
        for(j=0;j<3;j++){
            printf(" %c |",*(*(arr + i) + j));
        }
        printf("\n-------------\n");
    }
    printf("\n\n");
}

void ingresaEntrada(char(*arr)[3], int jugador){
    int fila, columna;
    int repetir=0;
    while (repetir ==0){
        if (jugador==0){
            printf ("introduzca fila y columna:\n");
            scanf("%d %d",&fila,&columna);
            if (*(*(arr + fila) + columna)==' '){
                *(*(arr + fila) + columna)='X';
                repetir=1;
            }
            else{
            printf("esa posicion esta ocupada\n");
            }
        }

        else if (jugador==1){
            printf ("introduzca fila y columna:\n");
            scanf("%d %d",&fila,&columna);
            if (*(*(arr + fila) + columna)==' '){
                *(*(arr + fila) + columna)='Y';
                repetir=1;
            }
            else{
            printf("esa posicion esta ocupada\n");
            }
        }
    }
}

int randomInRange(int minimo, int maximo){

    int numero=minimo+rand()/(RAND_MAX/(maximo - minimo + 1) + 1);
    return numero;
}