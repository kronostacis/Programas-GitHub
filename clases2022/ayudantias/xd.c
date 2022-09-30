#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *archi;
    int n,m,k;
    archi = fopen("entrada.txt","r");
    fscanf(archi,"%d %d %d",&n,&m,&k);
    printf("%d %d %d",n,m,k);
    return 0;
}