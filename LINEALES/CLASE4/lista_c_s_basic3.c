#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

void insertarInicio(struct Nodo** cabeza, int nuevoDato);
void insertarFinal(struct Nodo** cabeza, int nuevoDato);
void imprimirLista(struct Nodo* cabeza);
void vaciarLista(struct Nodo** cabeza);



void vaciarLista(struct Nodo** cabeza){
    if(*cabeza == NULL){
        return;
    }
    struct Nodo *actual = *cabeza;
    struct Nodo *temp;
    do{
        temp = actual;
        actual = actual->siguiente;
        free(temp);
    }while(actual != *cabeza);
}

int main() {
    struct Nodo* cabeza = NULL;

    // Insertar elementos
    insertarFinal(&cabeza, 10);
    insertarFinal(&cabeza, 20);
    insertarInicio(&cabeza, 5);
    insertarFinal(&cabeza, 30);

    // Imprimir la lista
    imprimirLista(cabeza);
    // Vaciar la lista
    vaciarLista(&cabeza);
    // Imprimir la lista
    imprimirLista(cabeza);
    return 0;
}





void imprimirLista(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    struct Nodo* actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(circular)\n");
}


void insertarFinal(struct Nodo** cabeza, int nuevoDato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;

    if (*cabeza == NULL) { // Lista vacía
        nuevoNodo->siguiente = nuevoNodo; // El nodo apunta a sí mismo
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != *cabeza) { // Encontrar el último nodo
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo; // Último nodo apunta al nuevo nodo
        nuevoNodo->siguiente = *cabeza; // Nuevo nodo apunta a la cabeza
    }
}

void insertarInicio(struct Nodo** cabeza, int nuevoDato) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;

    if (*cabeza == NULL) { // Lista vacía
        nuevoNodo->siguiente = nuevoNodo; // El nodo apunta a sí mismo
        *cabeza = nuevoNodo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != *cabeza) { // Encontrar el último nodo
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = *cabeza; // Nuevo nodo apunta a la antigua cabeza
        actual->siguiente = nuevoNodo; // Último nodo apunta al nuevo nodo
        *cabeza = nuevoNodo;           // Actualizar la cabeza
    }
}
