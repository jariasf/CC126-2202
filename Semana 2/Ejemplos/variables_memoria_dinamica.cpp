#include <iostream>
using namespace std;

int main() {
    // Declaracion de variables
    int variable_memoria_estatica; // Variable reserva espacio en memoria estatica (pila)
    int* variable_memoria_dinamica = new int; // Variable reserva espacio en memoria dinamica (heap)

    // Asignacion de valores
    variable_memoria_estatica = 35;  // Asignacion memoria estatica (pila)
    *variable_memoria_dinamica = 35; // Asignacion memoria dinamica (heap)

    // Inicialización de variables
    int numero1{ 35 };
    int* numero1_dinamica = new int{35};
    cout << "Valor de variable en memoria estatica " << numero1 << endl;
    cout << "Valor de variable en memoria dinamica " << *numero1_dinamica << endl;

    float* variable_flotante = new float{23.5};
    float* variable_flotante2 = new float;
    *variable_flotante2 = 34.6;

    *variable_flotante2 = 45.65;

    // (Opcional) limpiar la memoria
    delete numero1_dinamica;
    delete variable_memoria_dinamica;
    delete variable_flotante;
    return 0;
}