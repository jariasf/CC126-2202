#include <iostream>
using namespace std;

int main() {
    // Formas de inicialización de punteros
    int entero{5};
    int* ptr_entero = &entero;
    short* ptr_short = nullptr;
    float* ptr_real = new float;

    // En caso no se tenga espacio en memoria dinámica
    if (ptr_real == nullptr) {
        cout << "No hubo espacio en memoria";
    }
    else {
        cout << "El valor del puntero ptr_real: " << ptr_real << endl;
        // Eliminar memoria y apuntar a nulo
        delete ptr_real;
        ptr_real = nullptr;
    }
    return 0;
}
