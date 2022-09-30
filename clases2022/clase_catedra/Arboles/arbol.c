#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol{
    char clave;
    struct Arbol *right ,*left;
}arbol;
 int numnodos=0;
void preorden(arbol *ar);
void inorden(arbol *ar);
void posorden(arbol *ar);
void visitar(arbol *ar);
void cant_nodos(arbol *ar, int n);
int cant_hojas(arbol *ar);
int igualarbol(arbol *ar, arbol *ar2);
int main(){
    int alt, cant_hoja, cantnodo, igual;
    arbol *raiz1, *raiz2, *h, *m, *z, *k, *c, *j, *a, *i;
    arbol *n, *p, *y, *b, *e, *d, *x, *l;
    h=(arbol*)malloc(sizeof(arbol));
    m=(arbol*)malloc(sizeof(arbol));
    z=(arbol*)malloc(sizeof(arbol));
    k=(arbol*)malloc(sizeof(arbol));
    c=(arbol*)malloc(sizeof(arbol));
    j=(arbol*)malloc(sizeof(arbol));
    a=(arbol*)malloc(sizeof(arbol));
    i=(arbol*)malloc(sizeof(arbol));
    n=(arbol*)malloc(sizeof(arbol));
    p=(arbol*)malloc(sizeof(arbol));
    y=(arbol*)malloc(sizeof(arbol));
    b=(arbol*)malloc(sizeof(arbol));
    e=(arbol*)malloc(sizeof(arbol));
    d=(arbol*)malloc(sizeof(arbol));
    x=(arbol*)malloc(sizeof(arbol));
    l=(arbol*)malloc(sizeof(arbol));
    h->clave='h'; h->left=m; h->right=z;
    m->clave='m'; m->left=k; m->right=NULL;
    z->clave='z'; z->left=c; z->right=j;
    k->clave='k'; k->left=a; k->right=i;
    c->clave='c'; c->left=NULL; c->right=NULL;
    j->clave='j'; j->left=n; j->right=p;
    a->clave='a'; a->left=NULL; a->right=NULL;
    i->clave='i'; i->left=NULL; i->right=y;
    n->clave='n'; n->left=NULL; n->right=NULL;
    p->clave='p'; p->left=b; p->right=e;
    y->clave='y'; y->left=NULL; y->right=NULL;
    b->clave='b'; b->left=NULL; b->right=NULL;
    e->clave='e'; e->left=d; e->right=x;
    d->clave='d'; d->left=NULL; d->right=l;
    x->clave='x'; x->left=NULL; x->right=NULL;
    l->clave='l'; l->left=NULL; l->right=NULL;
    raiz1=h;
    raiz2=h;
    cant_nodos(raiz1,0);
    printf("%d\n",numnodos);
    cant_hoja=cant_hojas(raiz1);
    printf("%d\n",cant_hoja);
    igual=igualarbol(raiz1,raiz2);
    if (igual==0){
        printf("los arboles son distintos");
        }
    else{
        printf("los arboles son iguales");
    }
    return 0;
}

void visitar(arbol *ar){
    printf("%c",ar->clave);

}
void preorden(arbol *ar){
    if (ar!= NULL){
        visitar(ar);
        preorden(ar->left);
        preorden(ar->right);
    }
}

void inorden(arbol *ar){
    if (ar!= NULL){
        
        preorden(ar->left);
        visitar(ar);
        preorden(ar->right);
    }
}

void posorden(arbol *ar){
    if (ar!= NULL){
        preorden(ar->left);
        preorden(ar->right);
        visitar(ar);
    }
}

void cant_nodos(arbol *ar,int n){
    int count;
    if (ar== NULL){
        return;
    }
    cant_nodos(ar->left,n+1);
    numnodos++;
    cant_nodos(ar->right,n+1);
    
}

int cant_hojas(arbol *ar){
    if (ar == NULL){
        return 0;
    }
    if ((ar->right == NULL) && (ar->left == NULL)){
        return 1;
    }
    else {
        return cant_hojas(ar->left) + cant_hojas(ar->right);
    }
}

int igualarbol(arbol *ar, arbol *ar2){
    if (ar == NULL || ar2 == NULL){
        return 0;
    }
    igualarbol(ar->left,ar2->left);
    igualarbol(ar->right,ar2->right);
    if (ar->clave!=ar2->clave){
        return 0;
        }
    else{
        return 1;
    }
}