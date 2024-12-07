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
    primero->siguiente = NULL;

    // Crear el segundo nodo
    struct Nodo* segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo->dato = 20;
    segundo->siguiente = NULL;
    primero->siguiente = segundo;

    // Crear el tercer nodo
    struct Nodo* tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero->dato = 30;
    tercero->siguiente = NULL;
    segundo->siguiente = tercero;

    // Recorrer la lista e imprimir los datos
    struct Nodo* actual = primero;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");

    // Liberar memoria (opcional pero recomendado)
    free(tercero);
    free(segundo);
    free(primero);

    return 0;
}
