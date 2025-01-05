#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

int main() {
    // Crear el primer nodo
    struct Nodo* primero = (struct Nodo*)malloc(sizeof(struct Nodo));
    primero->dato = 10;

    // Crear el segundo nodo
    struct Nodo* segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo->dato = 20;

    // Crear el tercer nodo
    struct Nodo* tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero->dato = 30;

    // Enlazar los nodos para formar una lista circular
    primero->siguiente = segundo;
    segundo->siguiente = tercero;
    tercero->siguiente = primero; // El último nodo apunta al primero

    // Recorrer la lista circular e imprimir los datos
    printf("Recorrido de la lista circular:\n");
    struct Nodo* actual = primero;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != primero); // Se detiene al volver al primer nodo
    printf("[Vuelta completada]\n");

    // Liberar memoria (cuidado al liberar listas circulares)
    tercero->siguiente = NULL; // Romper el ciclo para liberar memoria
    free(tercero);
    free(segundo);
    free(primero);

    return 0;
}
