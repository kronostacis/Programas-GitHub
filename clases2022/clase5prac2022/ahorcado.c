#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define limit 50

void lectura(char *cad , char *cad2);
void imprimir(char *cad, char *noenc, int *cantletras);
void ahorcado(char *cad, char *noenc, int vidas , int *cantl);
int main(){
    int vidas, cantletras=0;
    char cadena[limit],cadena2[limit],noencontrada[limit];
    printf("Bienvenido a El Ahorcado\n");
    lectura(cadena,cadena2);
    vidas=atoi(cadena2);
    printf("Usted tiene %d vidas\n",vidas);
    imprimir(cadena, noencontrada, &cantletras);
    ahorcado(cadena, noencontrada,vidas,&cantletras);
    return 0;
} 

void lectura(char *cad , char *cad2 ){
    FILE *archivo;
    archivo=fopen("Entrada.txt", "r");
    fgets (cad, limit , archivo);
    fgets(cad2, limit , archivo);
}
void imprimir(char *cad, char *noenc, int *cantletras){
    int  i, len=strlen(cad)-1;
    for (i=0; i<len; i++){
        if (*(cad+i)!=' '){
            *(noenc+i)='_';
            cantletras++;
        }
        else{
            *(noenc+i)=' ';
        }
    }
}
void ahorcado(char *cad, char *noenc, int vidas, int *cantl){
    int len=strlen(cad)-1,i;
    char letra;
    
    while (vidas > 0 && cantl>0){
        printf("intodusca la letra: \n");
        scanf("%c", &letra);
        for (i=0;i<len;i++){
            if (letra==*(cad+i)){
                *(noenc+i)=letra;
                cantl--;
                printf("%s\n",noenc);
            }
        }
    }
}