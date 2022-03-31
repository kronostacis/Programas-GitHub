/* 
Ejemplo 1: Dadas dos variables numéricas var1 y var2, que el usuario debe 
ingresar, se solicita realizar un algoritmo que intercambie los valores de 
ambas variables y muestre cuánto valen finalmente.
 */

#include<stdio.h>

int main(){
    int a,b,c;
    printf("introduzca 2 numeros porfavor\n");
    scanf("%d %d"  ,&a,&b );
    c=a;
    a=b;
    b=c;
    printf("la variable a es %d y la variable b es %d: ", a,b);
    return 0;
}