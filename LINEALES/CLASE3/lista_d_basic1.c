#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

int main() {
    // Crear el primer nodo
    struct Nodo* primero = (struct Nodo*)malloc(sizeof(struct Nodo));
    primero->dato = 10;
    primero->siguiente = NULL;
    primero->anterior = NULL;
    // Crear el segundo nodo
    struct Nodo* segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo->dato = 20;
    segundo->siguiente = NULL;
    segundo->anterior = primero;
    primero->siguiente = segundo;
    // Crear el tercer nodo 
    struct Nodo* tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero->dato = 30;
    tercero->siguiente = NULL;
    segundo->siguiente = tercero;
    tercero->anterior = segundo;
    
    // Recorrer la lista hacia adelante
    struct Nodo* actual = primero;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
    // Recorrer la lista hacia atrás
    actual = tercero;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual=actual->anterior;
    }
    printf("NULL\n");
    free(primero);
    free(segundo);
    free(tercero);
    return 0;
}
