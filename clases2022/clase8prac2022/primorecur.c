#include <stdio.h>
void primos(int N,int a );

int main(){
    int n;
    scanf("%d",&n);
    primos(n,2);
    return 0;
}
void primos(int N,int a){
    int c,ver=0;
    if (a<=N){
        for (c=1;c<a;c++){
            if ((a%c==0) && (c!=a) && (c!=1)){
                ver=1;
            }
        }
        if (ver==0){
            printf("%d Es primo\n",a);
        }
        else if (ver==1){
            printf("%d No es primo\n",a);
        }
        a++;
    }
    primos(N,a);
}