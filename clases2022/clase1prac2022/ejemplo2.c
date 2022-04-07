/* 
Ejemplo 2: Realice un programa que lea dos números e indique cual es 
mayor o si son iguales
*/
#include <stdio.h>

int main(){
    printf("Introduzca dos numeros: ");
    int a,b;
    scanf("%d %d",&a,&b);
    if (a>b){
        printf("el numero %d es mayor que %d\n",a,b);
    }
    if (b>a){
        printf("el numero %d es mayor que %d\n",b,a);
    }
    if (a==b){
        printf("el numero a es igual al b o sea %d = %d",a,b);
    }
    return 0;
}
