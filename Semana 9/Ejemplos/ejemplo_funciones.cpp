#include <iostream>
using namespace std;

void mostrarValores(int numero, char caracter, float real, 
	                int* puntero_entero, char* puntero_caracter) {
    cout << "Numero entero: " << numero << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Numero real: " << real << endl;
    cout << "Puntero entero: " << *puntero_entero << endl;
    cout << "Puntero caracter: " << *puntero_caracter << endl;
}

int main() {
    int entero{5};
    char caracter{'A'};
    float flotante{2.3};
    
    cout << "Primera llamada a la función\n";
    mostrarValores( entero, caracter, flotante, &entero, &caracter);


    cout << "\nSegunda llamada a la función\n";
    int* ptr_entero = &entero;
    char* ptr_caracter = &caracter;
    mostrarValores( entero, caracter, flotante, ptr_entero, ptr_caracter);

    /*
    Asignaciones
    int numero = entero, 
    char caracter = caracter, 
    float real = flotante, 
    int* puntero_entero = &entero, 
    char* puntero_caracter = &caracter
    */

    return 0;
}