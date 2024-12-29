#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

void insertarFinal(struct Nodo** cabeza, int dato){
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = NULL;
    
    if(*cabeza == NULL)
        {
            *cabeza = nuevoNodo;
        }
    else{
        struct Nodo* temp = *cabeza;
        while(temp->siguiente != NULL){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp;
    }
}

int main() {
    struct Nodo* cabeza = NULL;
    insertarFinal(&cabeza,10);
    insertarFinal(&cabeza,20);
    insertarFinal(&cabeza,30);
    //Recorre hacia adelante
    struct Nodo* actual = cabeza;
    while(actual != NULL){
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
    //Liberar memoria
    while(cabeza != NULL){
        struct Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    return 0;
}
