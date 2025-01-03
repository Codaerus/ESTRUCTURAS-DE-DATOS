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

void insertarPrincipio(struct Nodo** cabeza, int dato){
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = *cabeza;
    nuevoNodo->anterior = NULL;
    if(*cabeza != NULL){
        (*cabeza)->anterior = nuevoNodo;
    }
    *cabeza = nuevoNodo;
}

void borrarElemento(struct Nodo** cabeza, int dato){
    if(*cabeza == NULL) return; //Lista vacía
    
    struct Nodo* temp = *cabeza;
    //Buscar el nodo con el dato
    while(temp != NULL && temp->dato != dato){
        temp = temp->siguiente;
    }
    
    if (temp == NULL) return; //Dato no encontrado
    
    //Ajustar los punteros
    if(temp->anterior != NULL){
        temp->anterior->siguiente = temp->siguiente;
    }
    else{
        //Es el primer nodo
        *cabeza = temp->siguiente;
    }
    free(temp);
    
}

int main() {
    struct Nodo* cabeza = NULL;
    insertarFinal(&cabeza,10);
    insertarFinal(&cabeza,20);
    insertarFinal(&cabeza,30);
    
    insertarPrincipio(&cabeza,5);
    insertarPrincipio(&cabeza,1);
    //insertarPrincipio(&cabeza,7);
    
    borrarElemento(&cabeza,5);
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
