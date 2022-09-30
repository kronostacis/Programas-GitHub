/* codigo realizado por Sebastian Ramos Bustos - Cristobal Artus Scheel/
/ Rut: 	  21.273.736-4    -     20.532.970-6  */

#include <stdio.h>
#include <stdlib.h>

// Estructura tipo nodo para enlazar listas doble Circular
typedef struct nd{
	int dato;
	struct nd *siguiente;
	struct nd *atras;
} nodo;

// Estructura para enlazar listas simples
typedef struct ls{
	int dato;
	struct ls *sig;
}l_simple;

void imprimirlistaAH(nodo* lista);
void imprimirlistaH(nodo* lista);
l_simple *insertarlistasimple(l_simple *lista, int dato);
nodo *insertarNodo(nodo *lista, int N);
int buscarNodo(nodo *ElegidosH, nodo *ElegidosA, nodo *circle, int indicador);
nodo *eliminarNodo(nodo *Elegidos, nodo *circle, int indicador);

int main(){
	
	l_simple* lguardias = NULL;
	l_simple* horario = NULL;
	l_simple* antihor = NULL;
	nodo* circle=NULL;
	FILE* archivo = NULL;
	int N, k, m,indicador;
	archivo = fopen("guardias.in","r");
	if (archivo==NULL){
		printf("error de lectura\n");
	}
	else {
		printf("su archivo fue leido correctamente\n");
	}
	do{
		fscanf(archivo,"%d %d %d",&N,&k,&m);
		if(N<=0||N>=1000){
			break;
			if (N<0||N>999 ){
				printf("parametros ingresados no validos, revisar guardias.in");
			}
		}
		lguardias=insertarlistasimple(lguardias,N);
		horario=insertarlistasimple(horario,k);
		antihor=insertarlistasimple(antihor,m);
	}
	while(N>=0||N<=1000);
	
	fclose(archivo); // Cierra archivo "guardias.in"
	FILE* exit=fopen("guardias.out","w"); // Abre un archivo de salida "guardias.out"
	while(lguardias!=NULL){
		
		nodo *auxhor=NULL;
		nodo *auxant=NULL;
		nodo *ElegidosH= NULL;
		nodo *ElegidosA= NULL;
		int g;
		for(g=1; g<=lguardias->dato;g++){
			circle=insertarNodo(circle,g);
		}
		auxhor=circle;
		auxant=circle->atras;
		
		// Pasamos los datos de las listas simples a las variables N, k, m 
		N=lguardias->dato;
		k=horario->dato;
		m=antihor->dato;
		
		/* Aqui se usan listas circulares auxiliares,
		la recorre y si encuentra el nodo buscado se elimina */
		while(circle!=NULL){ 
			
			int x,z;
			int o,p;
			for(o=1;o<k;o++){
				auxhor=auxhor->siguiente;
			}
			x=auxhor->dato;
			ElegidosH=auxhor;
			
			for(p=1;p<m;p++) {
				auxant=auxant->atras;
			}
			z=auxant->dato;
			ElegidosA=auxant;
			auxhor=auxhor->siguiente;
			auxant=auxant->atras;
			
			if(auxhor==ElegidosA){
				auxhor=auxhor->siguiente;
				auxant=auxant->atras;
			}
			if(x==z){
				if(auxant==auxhor){
					fprintf(exit,"%d,",x);
				}
				else{
					fprintf(exit,"%d,",x);
				}
				indicador=buscarNodo(ElegidosH,ElegidosA,circle,indicador);
				circle=eliminarNodo(ElegidosH,circle,indicador);	
			}
			else{
				
				if(auxant==(circle->siguiente)){
					fprintf(exit,"%d %d,",x,z);
				}
				else {
					fprintf(exit,"%d %d,",x,z);
				}
				indicador=buscarNodo(ElegidosH,ElegidosA,circle,indicador);
				circle=eliminarNodo(ElegidosH,circle,indicador);
				circle=eliminarNodo(ElegidosA,circle,indicador);
			}
		}
		fprintf(exit,"\n"); 
		
		// Una vez terminado el ciclo itera los datos de las listas simples
		lguardias=lguardias->sig;
		horario=horario->sig;
		antihor=antihor->sig;
	}
	printf("revise texto de salida");
	fclose(exit);
	return 0;
}

// Se usan auxiliares para agregar datos a una lista simple enlazada
l_simple *insertarlistasimple(l_simple *lista, int dato){

	l_simple* aux = lista;
	l_simple* nuevo_nodo = (l_simple*) malloc(sizeof(l_simple));
	if(lista==NULL){
		nuevo_nodo->dato=dato;
		nuevo_nodo->sig=NULL;
		lista=nuevo_nodo;
	}
	else {
		nuevo_nodo->dato=dato;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
	}
	return lista;
}

// Usan auxiliares tipo lista circular doble enlazada para agregar datos tipo int 
nodo *insertarNodo(nodo *lista, int N){

		nodo* ultimo=NULL;
		nodo* nuevo_nodo = (nodo*) malloc(sizeof(nodo));
		if(lista==NULL){
			nuevo_nodo->dato = N;
			nuevo_nodo->siguiente=nuevo_nodo;
			nuevo_nodo->atras=nuevo_nodo;
			lista=nuevo_nodo;
		}
		else{
			ultimo = lista->atras;
			nuevo_nodo->dato=N;
			ultimo->siguiente = nuevo_nodo;
			nuevo_nodo->atras = ultimo;
			nuevo_nodo->siguiente = lista;
			lista->atras = nuevo_nodo;
		}
		return lista;
}

// Busca un nodo en especifico, si lo encuentra retorna una variable tipo int
int buscarNodo(nodo *ElegidosH, nodo *ElegidosA, nodo *circle, int indicador){
	
	nodo*pro=circle;
	int nuevo;
	if((pro->atras)==pro){		
		nuevo=2;
		return nuevo;
	}
	else if((circle == ElegidosA||circle == ElegidosH)){
		nuevo=1;
		return nuevo;
	}
	else{
		nuevo=3;
		return nuevo;
	}	
}

//Dependiendo del indicador eliminamos de cierta forma los nodos
nodo *eliminarNodo(nodo *Elegidos, nodo *circle, int indicador){
	
	nodo *distinto = circle;
	// Este caso es cuando se elimina el primer nodo
	if(indicador==1){
		distinto=distinto->siguiente;
		(Elegidos->atras)->siguiente=Elegidos->siguiente;
		(Elegidos->siguiente)->atras=Elegidos->atras;
		free(Elegidos);
		return distinto;
	}
	// Cuando queda solo un nodo 
	else if(indicador==2){
		distinto=NULL;
		return distinto;
	}
	// Para cualquier otro caso
	else if(indicador==3){
		(Elegidos->atras)->siguiente=Elegidos->siguiente;
		(Elegidos->siguiente)->atras=Elegidos->atras;
		free(Elegidos);
		return distinto;
	}	
}

// Lista circular horaria
void imprimirlistaH(nodo* lista){
	
	nodo* actual = NULL;
	actual = lista;
	if(lista!=NULL){
		printf("||");
		do{
			printf("%d,", actual->dato);
			actual = actual->siguiente;
		}while(lista != actual);
		printf("||\n");
	}else{
		printf("\n La Lista se encuentra vacia\n\n");
	}
}

// Lista circular antihoraria
void imprimirlistaAH(nodo* lista){
    
    nodo* actual = NULL;
    actual = lista->atras;
    if(lista!=NULL){
        printf("||");
        do{
            printf("%d,", actual->dato);
            actual = actual->atras;
        }while(actual != lista->atras);
        printf("||\n\n");
    }else{
        printf("\n La Lista se encuentra vacia\n\n");
    }
}
