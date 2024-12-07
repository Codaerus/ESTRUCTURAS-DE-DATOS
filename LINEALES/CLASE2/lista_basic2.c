#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para insertar un nuevo nodo al final de la lista
void insertarNodo(struct Nodo** cabeza, int nuevoDato) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo será la cabeza
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
        return;
    }

    // Recorrer hasta el último nodo
    struct Nodo* actual = *cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }

    // Conectar el último nodo al nuevo nodo
    actual->siguiente = nuevoNodo;
}

int main() {
    struct Nodo* cabeza = NULL; // Inicialmente la lista está vacía

    // Insertar nodos
    insertarNodo(&cabeza, 10);
    insertarNodo(&cabeza, 20);
    insertarNodo(&cabeza, 30);

    // Recorrer la lista e imprimir los datos
    struct Nodo* actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");

    // Liberar memoria
    actual = cabeza;
    while (actual != NULL) {
        struct Nodo* temp = actual;
        actual = actual->siguiente;
        free(temp);
    }

    return 0;
}
