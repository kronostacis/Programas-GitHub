/* 
Ejercicio 1 (Distribución de segundos): Realice un programa que solicite al 
usuario una cantidad de segundos y los distribuya en horas, minutos y 
segundos, por ejemplo: “3725 segundos son: 1 hora con 2 minutos y 5 
segundos”.
*/
#include <stdio.h>
int main(){
    int segundos,horas,min,seg;
    printf("Introduzca una cantidad de segundos.\n");
    scanf("%d",&segundos);
    horas=segundos/3600;
    min=(segundos%3600)/60;
    seg=(segundos%3600)%60;

    printf("es %d hora con %d minutos y %d segundos",horas,min, seg);
    return 0;
}