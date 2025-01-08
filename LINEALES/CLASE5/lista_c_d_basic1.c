#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo* s;
    struct Nodo* a;
};


int main() {
    struct Nodo* primero = (struct Nodo*)malloc(sizeof(struct Nodo));
    primero->dato = 10;
    
    struct Nodo* segundo = (struct Nodo*)malloc(sizeof(struct Nodo));
    segundo->dato = 20;
    
    struct Nodo* tercero = (struct Nodo*)malloc(sizeof(struct Nodo));
    tercero->dato = 30;
    
    // Enlazar los nodos
    primero->s = segundo;
    primero->a = tercero;
    
    segundo->s = tercero;
    segundo->a = primero;
    
    tercero->s = primero;
    tercero->a = segundo;
    
    //Imprimir hacia adelante
    struct Nodo* actual = primero;
    printf("Recorrido hacia adelante\n");
    do{
        printf("%d -> ", actual->dato);
        actual = actual->s;
    }while(actual != primero);
    printf("[Vuelta completada]\n");
    
    //Imprimir hacia atrás
    actual = tercero;
    printf("Recorrido hacia atrás\n");
    do{
        printf("%d -> ", actual->dato);
        actual = actual->a;
    }while(actual != tercero);
    printf("[Vuelta completada]\n");
    //Liberar memoria(romper memoria)
    primero->a = NULL;
    tercero->s = NULL;
    free(primero);
    free(segundo);
    free(tercero);
    return 0;
}
