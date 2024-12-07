#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para insertar un nuevo nodo al inicio de la lista
void insertarAlInicio(struct Nodo** cabeza, int nuevoDato) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    // El nuevo nodo apunta al antiguo inicio
    nuevoNodo->siguiente = *cabeza;
    // La cabeza ahora apunta al nuevo nodo
    *cabeza = nuevoNodo;
}

int main() {
    struct Nodo* cabeza = NULL; // Inicialmente la lista está vacía

    // Insertar nodos al inicio
    insertarAlInicio(&cabeza, 10); // Lista: 10 -> NULL
    insertarAlInicio(&cabeza, 20); // Lista: 20 -> 10 -> NULL
    insertarAlInicio(&cabeza, 30); // Lista: 30 -> 20 -> 10 -> NULL

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

