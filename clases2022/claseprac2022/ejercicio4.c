/*
Ejercicio 3: Una tienda realiza un descuento del 13% sobre la compra si son 
realizadas en los meses de marzo, abril o mayo. Haga un algoritmo que 
reciba el precio y el mes de la compra. Muestre el precio total por pantalla, 
haciendo mención al descuento si corresponde
*/

#include <stdio.h>
int main(){
    float precio;
    char mes[15];
    printf("introduzca el mes:\n ");
    scanf("%c", &mes);
    printf("introduzca el precio:\n");
    scanf("%f", &precio);
    
    if(mes=="marzo" || mes=="abril" || mes=="mayo"){
        precio=precio-(precio*0.13);
        printf("El precio final es %f", precio);
    }
    return 0;
}