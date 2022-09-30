/*
Ejercicio 4 (Deducción de contraseñas): se solicita un programa de deducir 
contraseñas, basadas en un arreglo que contiene los primeros 20 números 
primos. Las contraseñas a deducir son:
○ Pedro: su contraseña es una concatenación de los primeros 5 números primos 
que se encuentran en posiciones impares ordenados de manera decreciente.
○ Juan: su contraseña es una concatenación de los primeros 5 números primos que 
se encuentran en posiciones pares ordenados de manera creciente.
○ Diego: su contraseña es una concatenación de los primeros 5 números primos 
que se encuentran en posiciones primas ordenados de manera creciente.
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

int listaprim(int Num, int persona);
int listaprim(int Num, int persona){
    int x,y=0,z;
    int c=0;
    int i=0;
    int lista[Num];
    for (c=2;c<Num;c++){
        if (primo(c)!=0){
            lista[y]=primo(c);
            i++;
            y++;
            //printf("%d\n",i);
        }    
    }
    if (persona==1){
        for(z=4;z>=0;z--){
            printf("%d",lista[z]);
        }
    }
    if (persona==2){
        for (z=0;z<5;z++){
            printf("%d",lista[((2*z)+2)]);
        }
    }
    if (persona==3){
        for (z=0;z<5;z++){
            printf("%d",lista[lista[z]]);
        }
    }
    printf("\n");
}

int main(){
    printf("%d", listaprim(40 , 3));
    return 0;
}