/* 
Ejemplo 2 (Números primos): Realizar un programa que calcule los 
primeros N números primos, el valor de N se debe ingresar por teclado

*/

#include <stdio.h>

int primo(int N);
int primo(int N){
    int c;
    for (c=1;c<N;c++){
        if ((N%c==0) && (c!=N) && (c!=1)){
            return 0;
        }
    }  
    return N;  
}

int listaprim(int Num);
int listaprim(int Num){
    int c=0;
    for (c=2;c<Num;c++){
        int lista[Num];
        if (primo(c)!=0){
            lista[c]=primo(c);
            printf("%d\n",lista[c]);
        }
    }
}


int main(){
    printf("%d", listaprim(33));

    return 0;
}