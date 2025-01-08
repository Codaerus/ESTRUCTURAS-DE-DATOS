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
    *cabeza = NULL;
    printf("La lista ha sido vaciada\n");
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
