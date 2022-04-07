/*
Ejercicio 2 (Conjetura de Collatz): Realice un programa que resuelva la 
conjetura de Collatz, métodos iterativo que, por medio de operaciones 
consecutivas, transforma un número a uno. Las reglas son las siguientes:
○ Si el número es par, se divide entre 2.
○ Si el número es impar, se multiplica por 3 y se le suma 1.

*/

#include <stdio.h>

int main(){
    float numero;
    printf("introduzca numero: ");
    scanf("%f",&numero);
    while ((int)numero !=1){
        if ((int)numero % 2 == 0){
            numero=numero/2;
            numero=(int)numero;
            printf("%f\n",numero);
        }    
        else{
            numero=(numero*3)+1;
            numero=(int)numero;
            printf("%f\n",numero);
        }
    }
    return 0;
}
