#include<stdio.h>
#include<stdlib.h>
void cuadrado(int a,int n);

int main(){
    int n,a=1;
    scanf("%d",&n);
    cuadrado(a,n);
    return 0;
}

void cuadrado(int a, int n){
    int cuadra;
    if (a<=n){
        cuadra=a*a;
        printf("%d\n",cuadra);
        a++;
        cuadrado(a,n);
    }
}