#include <stdio.h>
#include <stdlib.h>
struct Nodo {
	int dato;
	struct Nodo* s;
	struct Nodo* a;
};

void insertarInicio(struct Nodo** cabeza, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	if(*cabeza == NULL) {
		*cabeza = nuevoNodo;
		nuevoNodo->s = nuevoNodo->a = nuevoNodo;
	} else {
		struct Nodo* ultimo = (*cabeza)->a;
		nuevoNodo->s = *cabeza;
		nuevoNodo->a = ultimo;
		ultimo->s = nuevoNodo;
		(*cabeza)->a = nuevoNodo;
		*cabeza = nuevoNodo;
	}
}

void mostrarAdelante(struct Nodo* cabeza) {
	if(cabeza == NULL) {
		printf("Lista vacía\n");
		return;
	}
	struct Nodo* actual = cabeza;
	do {
		printf("%d -> ", actual->dato);
		actual = actual->s;
	} while(actual != cabeza);
	printf("[Vuelta completada]\n");
    
}

void mostrarAtras(struct Nodo* cabeza){
    if(cabeza == NULL) {
		printf("Lista vacía\n");
		return;
	}
	struct Nodo* ultimo = cabeza->a;
	struct Nodo* actual = ultimo;
	do{
	    printf("%d -> ", actual->dato);
	    actual = actual->a;
	}while(actual != ultimo);
	printf("[Vuelta completada]\n");
}

int buscarNodo(struct Nodo* cabeza, int dato){
    if(cabeza == NULL) return 0; //lista vacía
    struct Nodo* actual = cabeza;
    do{
        if(actual->dato == dato) return 1; //elemento encontrado
        actual = actual->s;
    }while(actual != cabeza);
    return 0; //no existe el elemento
}

int main()
{
	struct Nodo* cabeza = NULL;
	insertarInicio(&cabeza,10);
	insertarInicio(&cabeza,20);
	insertarInicio(&cabeza,30);
	mostrarAtras(cabeza);
	mostrarAdelante(cabeza);
	printf("%d",buscarNodo(cabeza,12));

	return 0;
}
