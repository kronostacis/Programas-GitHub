/* 
Ejemplo 3: Realizar un programa que resuelva el cuadrado de los N 
primeros números naturales
 */

#include <stdio.h>
int main(){
    printf("dame la cantidad de naturales que quieras al cuadrado\n");
    int a,i;
    scanf("%d",&a);
    for(i=1;i<a;i=i+1){
        int cuadrado=i*i;
        printf("el cuadrado de %d es %d\n",i,cuadrado);
    }
    return 0;
}