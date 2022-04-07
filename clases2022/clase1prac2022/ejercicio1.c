/*
Ejercicio 1: Realizar un programa que lea N números y calcule la media 
aritmética de ellos.
*/

#include <stdio.h>
int main(){
    printf("cuantos numeros quiere ingresar: ");
    int n,a,suma;
    float resultado;
    scanf("%d",&n);
    int lista[n];
    for(a=0;a<n;a++){
        printf("introdusca el numero: ");
        scanf("%d",&lista[a]);
        suma=suma+lista[a];
        resultado=suma/n;
    }
    printf("la nota final es %.2f", resultado);
    return 0;
}