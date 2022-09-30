/*
● Realice un programa recursivo que resuelva la conjetura de Collatz, método
iterativo que, por medio de operaciones consecutivas, hace converger un
número natural a 1.
● Las reglas son las siguientes:
○ Si el número es par, se divide entre 2.
○ Si el número es impar, se multiplica por 3 y se le suma 1.
*/
#include<stdio.h>

void collatz(int i);
int main(){
    int i;
    scanf("%d",&i);
    collatz(i);
    return 0;
}

void collatz(int i){
    int result;
    if (i==1){
        printf("conjetura completada");
    }
    else{
        if (i%2==0){
            result =i/2;
            printf("%d\n",result);
            collatz(result);
        }

        else{
            result=(3*i)+1;
            printf("%d\n",result);
            collatz(result);
        }
    }
}