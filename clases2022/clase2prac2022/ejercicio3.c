/*
Ejercicio 3 (Ingreso de número menor a 1000): Hacer un algoritmo que lea 
un número menor a 1000:
○ Si el número tiene un dígito, elevarlo al cuadrado y mostrar su resultado.
○ Si el número es de dos dígitos, multiplicarlo por dos y mostrar su resultado.
○ Si el número es de tres dígitos, restarle cien y mostrar el resultado.
○ Si el número es cero, negativo o mayor a tres dígitos, mostrar “Número no 
válido”.

*/

#include <stdio.h>

int main(){
    int numero, cociente, divisor, contador;
    cociente = 0;
    divisor = 1;
    contador = 0;

    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    while (cociente !=1){
        contador++;
        divisor = divisor * 10;
        cociente = numero / divisor;

        if (cociente == 1){
            printf("El numero tiene %d digitos\n", contador + 1);
            contador=contador + 1;
        }//fin if

        if (cociente < 1){
            printf("El numero tiene %d digitos\n", contador);
            cociente = 1;
        }//fin if

        if (numero < 10){
            printf("Solo tiene un digito\n");
        }//fin if
    }//fin while
    if (contador==1){
        printf("%d", numero*numero);
    }
    else if (contador==2){
        printf("%d", numero*2);    
    }
    else if (contador==3){
        printf("%d", numero-100);

    }
    else {
        printf("numero no valido");
    }
    return 0;
}
