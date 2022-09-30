#include <stdio.h>

int function(int n);

int main(){
    int n;
    scanf("%d",&n);
    return 0;
}

int function(int n){
    if (n == 1){
        printf("Fin de recursividad");
    }
    else if (n>0){
        printf("%d",n);
        return (2*function(n-1)+1);
    }

}
