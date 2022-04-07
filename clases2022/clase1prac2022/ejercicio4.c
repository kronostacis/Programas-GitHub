/*
Ejercicio 3: Una tienda realiza un descuento del 13% sobre la compra si son 
realizadas en los meses de marzo, abril o mayo. Haga un algoritmo que 
reciba el precio y el mes de la compra. Muestre el precio total por pantalla, 
haciendo mención al descuento si corresponde
*/

#include <stdio.h>
int main(){
    float precio, preciofinal;
    int mes;
    printf("introduzca el mes:\n ");
    scanf("%i", &mes);
    printf("introduzca el precio:\n");
    scanf("%f", &precio);
    
    if(mes==3 || mes==4 || mes==5){
        preciofinal=precio-(precio*0.13);
        printf("El precio final es %.2f", preciofinal);
    }
    return 0;
}