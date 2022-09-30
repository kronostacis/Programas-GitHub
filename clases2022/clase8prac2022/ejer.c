/*
Escriba un procedimiento que convierta recursivamente un entero dado en un string que
contenga todos sus dígitos. Determine la complejidad de su algoritmo.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void cambstr(int n, int i);

int main(){
    int n,var,contador,i=0;
    printf("introduzca un entero \n");
    scanf("%d",&n);
    while (var==1){
        if (n<pow(10,i)){
            i--;
            break;
        }
        else{
            i++;
        }
    }
    cambstr(n);
    return 0;
}
void cambstr(int n){
    int var=1;
    while (var==1){
        var=0;
    }
}