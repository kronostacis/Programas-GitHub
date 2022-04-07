/*
Ejemplo 1 (Año bisiesto): Realizar un algoritmo que, dado un año, este 
indique si es un año bisiesto o no. Las condiciones son las siguientes:
○ Si es divisible por 4 y no divisible por 100, es bisiesto.
○ Si un año es divisible entre 100 y además es divisible entre 400, también 
resulta bisiesto.
 */
#include <stdio.h>
int main(){
    int anio;
    printf("introduzca un año para v er si es bisiesto\n");
    scanf("%d",&anio);

    
    if (anio%4==0 && (anio%100!=0)){
        printf("El año %d es bisiesto\n",anio);
    }
    else if (anio%100==0 && (anio%400==0)){
        printf("El año %d es bisiesto\n",anio);
    }
    else{
        printf("el año %d no es bisiesto\n",anio);
    }
    return 0;
}