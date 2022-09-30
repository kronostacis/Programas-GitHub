#include <stdio.h>
#include <stdlib.h>

typedef struct Arbolito{
    int clave;
    struct Arbolito *left,*right;
} Arbolito;

void preorden(Arbolito *ar);
void inorden(Arbolito *ar);
void postorden(Arbolito *ar);
void visitar(Arbolito *ar);
//Arbolito *insertar(Arbolito *ar, int elem);
void insertar(Arbolito **ar, int elem);

int main(){
    Arbolito *ar = NULL;
    insertar(&ar,40);
    insertar(&ar,30);
    insertar(&ar,60);
    insertar(&ar,15);
    insertar(&ar,32);
    insertar(&ar,50);
    insertar(&ar,80);
    insertar(&ar,8);
    insertar(&ar,17);
    insertar(&ar,35);
    insertar(&ar,45);
    insertar(&ar,51);
    insertar(&ar,74);
    insertar(&ar,82);
    insertar(&ar,7);
    insertar(&ar,10);
    insertar(&ar,42);
    insertar(&ar,48);
    insertar(&ar,71);
    insertar(&ar,76);
    insertar(&ar,9);
    insertar(&ar,13);
    insertar(&ar,46);
    insertar(&ar,49);
    insertar(&ar,12);
    insertar(&ar,14);
    insertar(&ar,11);
    preorden(ar);
    printf("\n");
    inorden(ar);
    printf("\n");
    postorden(ar);
    return 0;
}

void preorden(Arbolito *ar){
    if (ar!= NULL){
        visitar(ar);
        preorden(ar->left);
        preorden(ar->right);
    }
}

void inorden(Arbolito *ar){
    if (ar!= NULL){
    inorden(ar->left);
    visitar(ar);
    inorden(ar->right);
    }
}

void postorden(Arbolito *ar){
    if (ar!= NULL){
    postorden(ar->left);
    postorden(ar->right);
    visitar(ar);
    }
}

void visitar(Arbolito *ar){
    printf("%d ", ar->clave);
}
/*
Arbolito *insertar(Arbolito *ar, int elem){
    Arbolito *aux = (Arbolito *)malloc(sizeof(Arbolito));
    
    if (ar==NULL){
        aux->clave = elem;
        aux->left=aux->right=NULL;
        
    }
    else if (elem > ar->clave){
        insertar(ar->right,elem);
    }
    else if (elem < ar->clave){
        insertar(ar->left,elem);
    }
    return ar;
}*/

void insertar(Arbolito **ar, int elem){
    if (*ar == NULL) {
        *ar = (Arbolito *) malloc(sizeof(Arbolito));
        (*ar)->clave = elem;
        (*ar)->left = (*ar)->right = NULL;
    }
    else if ((*ar)->clave < elem) insertar(&(*ar)->right, elem); 
    
    else if ((*ar)->clave > elem) insertar(&(*ar)->left, elem);
}
