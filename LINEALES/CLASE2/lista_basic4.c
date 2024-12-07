#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para insertar un nodo en una posición específica
void insertarEnPosicion(struct Nodo** cabeza, int nuevoDato, int posicion) {
    // Crear el nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;

    // Insertar al inicio si la posición es 0
    if (posicion == 0) {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        return;
    }

    // Buscar el nodo en la posición anterior a la deseada
    struct Nodo* actual = *cabeza;
    for (int i = 0; i < posicion - 1; i++) {
        if (actual == NULL) {
            printf("La posición %d está fuera de rango.\n", posicion);
            free(nuevoNodo); // Liberar memoria si no es posible insertar
            return;
        }
        actual = actual->siguiente;
    }

    // Insertar el nuevo nodo en la posición
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

int main() {
    struct Nodo* cabeza = NULL; // Inicialmente la lista está vacía

    // Insertar nodos en posiciones específicas
    insertarEnPosicion(&cabeza, 10, 0); // Lista: 10 -> NULL
    insertarEnPosicion(&cabeza, 20, 1); // Lista: 10 -> 20 -> NULL
    insertarEnPosicion(&cabeza, 30, 1); // Lista: 10 -> 30 -> 20 -> NULL
    insertarEnPosicion(&cabeza, 40, 0); // Lista: 40 -> 10 -> 30 -> 20 -> NULL

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
