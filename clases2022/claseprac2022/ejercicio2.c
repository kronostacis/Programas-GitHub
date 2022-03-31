/* 

Ejercicio 2: Realizar un programa donde se ingresen tres notas, se obtenga 
una nota final y se indique si el alumno pasó o no de curso.
○ La primera pondera 50% del total.
○ La segunda pondera 30% del total.
○ La tercera pondera 20% del total.

*/

#include <stdio.h>
int main(){
    float nota1,nota2,nota3,notafinal;
    printf("introduzca las notas en orden: ");
    scanf("%f %f %f", &nota1, &nota2, &nota3);
    notafinal=(nota1*0.5)+(nota2*0.3)+(nota3*0.2);
    printf("la nota final es %0.2f", notafinal);
    return 0;
}