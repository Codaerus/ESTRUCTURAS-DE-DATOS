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

//Liberar toda la lista 
void liberarLista(struct Nodo** cabeza){
    if(*cabeza == NULL) return;
    struct Nodo* actual = *cabeza;
    struct Nodo* siguiente;
    do{
        siguiente = actual->s;
        free(actual);
        actual = siguiente;
    }while(actual != *cabeza);
    *cabeza = NULL;
}

int eliminaNodo(struct Nodo**cabeza, int dato){
    if(*cabeza == NULL) return 0;
    struct Nodo* actual = *cabeza;
    do{
        if(actual->dato == dato)
            {
                if(actual->s== actual && actual->a == actual){//único nodo
                    *cabeza = NULL;
                }
                else{
                    struct Nodo* anterior = actual->a;
                    struct Nodo* siguiente = actual->s;
                    anterior->s = siguiente;
                    siguiente->a = anterior;
                    if(actual == *cabeza){
                        *cabeza = siguiente;
                    }
                }
                free(actual);
                return 1;
            }
        actual = actual->s;

    }while(actual != *cabeza);
    return 0; //nodo no encontrado
}

int main()
{
	struct Nodo* cabeza = NULL;
	insertarInicio(&cabeza,10);
	insertarInicio(&cabeza,20);
	insertarInicio(&cabeza,30);
	mostrarAtras(cabeza);
	//mostrarAdelante(cabeza);
	printf("%d\n",buscarNodo(cabeza,10));
	//liberarLista(&cabeza);
	eliminaNodo(&cabeza,30);
	insertarInicio(&cabeza,26);
    mostrarAtras(cabeza);
	return 0;
}
