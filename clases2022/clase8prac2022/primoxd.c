#include <stdio.h>
int primos(int c, int a );

int main(){
    int c=2,a,ver;
    scanf("%d",&a);
    ver=primos(c,a);
    if (ver==0){
        printf("%d Es primo\n",a);
    }
    else if (ver==1){
        printf("%d No es primo\n",a);
    }
    return 0;
}
int primos(int c,int a){
    int ver=0;
    if (a==c){
        return ver;
    }
    else if (a%c==0){
        ver=1;
        return ver;
    }
    return primos(c+1,a);
}