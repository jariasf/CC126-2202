#include <iostream>
using namespace std;

void modificarValores(char *ptr_caracter, int* ptr_entero, float* ptr_real) {
    *ptr_caracter = 'Z';
    *ptr_entero += 5;
    *ptr_real = *ptr_real * 10;
}

void modificarValoresReferencia(char& ref_caracter, int& ref_entero, float& ref_real) {
    ref_caracter = 'Z';
    ref_entero += 5;
    ref_real = ref_real * 10;
}

int main() {
    char letra{'A'};
    int entero{50};
    float real{12.5};

    cout << "\nAntes de llamar a la funcion";
    cout << "\nLetra: " << letra;
    cout << "\nEntero: " << entero;
    cout << "\nReal: " << real;

    char* ptr_caracter = &letra;
    int* ptr_entero = &entero;
    float* ptr_real = &real;
    modificarValores(ptr_caracter, ptr_entero, ptr_real);
    //modificarValores(&letra, &entero, &real);
    //modificarValoresReferencia(letra, entero, real);

    cout << "\n\nDespues de llamar a la funcion";
    cout << "\nLetra: " << letra;
    cout << "\nEntero: " << entero;
    cout << "\nReal: " << real;

    return 0;
}