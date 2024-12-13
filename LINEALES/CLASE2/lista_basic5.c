#include <stdio.h>
#include <stdlib.h>
struct Nodo{
    int dato;
    struct Nodo* siguiente;
};

void insert(struct Nodo** cabeza,int nuevoDato,int pos){
    //printf("%p\n",cabeza);
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    
    //Insertar al inicio si la posicion es cero
    if(pos == 0){
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
        return;
    }
    //Buscar el nodo en la posición anterior a la deseada
    struct Nodo* actual = *cabeza;
    for(int i = 0; i<pos-1; i++){
        if(actual == NULL){
            printf("Fuera de rango\n");
            free(nuevoNodo);
            return;
        }
        actual = actual->siguiente;
    }
    
    //Insertar el nuevo nodo el posición
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

int main()
{
    struct Nodo *cabeza = NULL;
    //printf("%p\n",&cabeza);
    int c[] = {10,20,30,40,80,60};
    for(int i =0 ; i<= 5 ; i++){
        insert(&cabeza,c[i],i);
    }

    
    struct Nodo *actual = cabeza;
    while(actual != NULL){
        printf("%d ->", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
    return 0;
}
