#include <stdio.h>

void modificarPuntero(int** doblePuntero) {
    // Crear un nuevo entero y asignar su dirección al puntero al que apunta el puntero doble
    int nuevoValor = 42;
    *doblePuntero = &nuevoValor;
}

int main() {
    int x = 10;
    int* ptr = &x;       // Puntero simple que apunta a x
    int** doblePtr = &ptr; // Puntero doble que apunta al puntero ptr

    printf("Antes de modificar: *ptr = %d\n", *ptr); // Imprime 10

    modificarPuntero(doblePtr); // Modifica el puntero ptr a que apunte a otro lugar

    printf("Después de modificar: *ptr = %d\n", *ptr); // Imprime 42

    return 0;
}
