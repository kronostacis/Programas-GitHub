#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol{
    int clave;
    struct Arbol *right ,*left;
}arbol;


int numnodos=0;


void preorden(arbol *ar);
void inorden(arbol *ar);
void posorden(arbol *ar);
void visitar(arbol *ar);
void cant_nodos(arbol *ar);
int cant_hojas(arbol *ar);
int igualarbol(arbol *ar, arbol *ar2);
int es_bin(arbol *ar);

int main(){
    int alt, cant_hoja, cantnodo, igual, esbin;
    arbol *raiz1, *raiz2, *a, *b, *c, *d,*e, *f, *g, *h, *i, *j, *k, *l, *m, *n,*o, *p, *q, *r, *s,*t, *u, *v;
    a=(arbol*)malloc(sizeof(arbol));
    b=(arbol*)malloc(sizeof(arbol));
    c=(arbol*)malloc(sizeof(arbol));
    d=(arbol*)malloc(sizeof(arbol));
    e=(arbol*)malloc(sizeof(arbol));
    f=(arbol*)malloc(sizeof(arbol));
    g=(arbol*)malloc(sizeof(arbol));
    h=(arbol*)malloc(sizeof(arbol));
    i=(arbol*)malloc(sizeof(arbol));
    j=(arbol*)malloc(sizeof(arbol));
    k=(arbol*)malloc(sizeof(arbol));
    l=(arbol*)malloc(sizeof(arbol));
    m=(arbol*)malloc(sizeof(arbol));
    n=(arbol*)malloc(sizeof(arbol));
    o=(arbol*)malloc(sizeof(arbol));
    p=(arbol*)malloc(sizeof(arbol));
    q=(arbol*)malloc(sizeof(arbol));
    r=(arbol*)malloc(sizeof(arbol));
    s=(arbol*)malloc(sizeof(arbol));
    t=(arbol*)malloc(sizeof(arbol));
    u=(arbol*)malloc(sizeof(arbol));
    v=(arbol*)malloc(sizeof(arbol));

    


    a->clave=1; a->left=b; a->right=c;
    b->clave=5; b->left=d; b->right=e;
    c->clave=2; c->left=f; c->right=g;
    d->clave=6; d->left=h; d->right=i;
    e->clave=7; e->left=NULL; e->right=j;
    f->clave=3; f->left=NULL; f->right=NULL;
    g->clave=4; g->left=NULL; g->right=k;
    h->clave= 8; h->left=NULL; h->right=NULL;
    i->clave=9; i->left=l; i->right=m;
    j->clave=13; j->left=NULL; j->right=n;
    k->clave=15; k->left=o; k->right=NULL;
    l->clave=10; l->left=NULL; l->right= NULL;
    m->clave=12; m->left=NULL; m->right=NULL;
    n->clave=14; n->left=p; n->right=NULL;
    o->clave=16; o->left=q; o->right=r;
    p->clave=23; p->right=NULL; p->left=NULL;
    q->clave=18; q->left=s; q->right=t;
    r->clave=17; r->right=NULL; r->left=NULL;
    s->clave=22; s->left=NULL; s->right=NULL;
    t->clave=19; t->right=u; t->left=NULL;
    u->clave=20; u->left=v; u->right=NULL;
    v->clave=21; v->right=NULL; v->left=NULL;

    raiz1=a;
    raiz2=b;
    cant_nodos(raiz1);
    printf("%d\n",numnodos);
    cant_hoja=cant_hojas(raiz1);
    printf("%d\n",cant_hoja);
    igual=igualarbol(raiz1,raiz2);
    if (igual==0){
        printf("los arboles son distintos");
        }
    else{
        printf("los arboles son iguales\n");
    }
    printf("\n");   
    preorden(raiz1);
    printf("\n");
    inorden(raiz1);
    printf("\n");
    posorden(raiz1);

    return 0;
}

void visitar(arbol *ar){
    printf("%d ",ar->clave);

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
        
        inorden(ar->left);
        visitar(ar);
        inorden(ar->right);
    }
}

void posorden(arbol *ar){
    if (ar!= NULL){
        posorden(ar->left);
        posorden(ar->right);
        visitar(ar);
    }
}

void cant_nodos(arbol *ar){
    if (ar== NULL){
        return;
    }
    cant_nodos(ar->left);
    numnodos++;
    cant_nodos(ar->right);
    
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

int es_bin(arbol *ar){
    if (ar == NULL){
        return;
    }
    es_bin(ar->left);
    es_bin(ar->right);
    if ((ar->right)->clave > ar->clave && (ar->left)->clave < ar->clave)
        return 1;
    else{
        return 0;
    }
}