#include <stdio.h>
#define limit 50

void lectura(char *cad , char *cad2 );

int main(){
    int vidas;
    char cadena[limit],cadena2[limit];
    printf("Bienvenido a El Ahorcado\n");
    lectura(cadena,cadena2);
    vidas=atoi(cadena2);
    printf("Usted tiene %d vidas\n",vidas);
    return 0;
}

void lectura(char *cad , char *cad2 ){
    FILE *archivo;
    archivo=fopen("Entrada.txt", "r");
    fgets (cad, limit , archivo);
    fgets(cad2, limit , archivo);
}