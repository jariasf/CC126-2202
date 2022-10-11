#include <iostream>
using namespace std;

int main() {

    int y;
    int* ptr_entero;

    y = 14;
    cout << "El valor de y es " << y << endl;
    cout << "La dirección de memoria de y es " << &y << endl;

    ptr_entero = &y;
    
    cout << "\nEl valor de ptr_entero es " << ptr_entero << endl;
    cout << "El valor al que ptr_entero apunta es " << *ptr_entero << endl;
    //cout << "La dirección de memoria de ptr_entero es " << &ptr_entero << endl;

    // Modifiquemos el contendo al que apunta
    *ptr_entero = *ptr_entero + 1;

    cout << "\nEl valor de y " << y << endl;
    cout << "El valor al que apunta ptr_entero " << *ptr_entero << endl;

    // Uso de segundo puntero
    int* segundo_ptr;
    segundo_ptr = ptr_entero;

    cout << "\nEl valor de segundo_ptr es " << segundo_ptr << endl;
    cout << "El valor al que apunta segundo_ptr " << *segundo_ptr << endl;

    // Modifiquemos el contendo al que apunta
    *segundo_ptr = *segundo_ptr + 5;
    cout << "\nEl valor de y " << y << endl;

    cout << "\n\nDirecciones en memoria de las variables\n";
    cout << "Direccion de y " << &y << endl;
    cout << "Direccion de ptr_entero " << &ptr_entero << endl;
    cout << "Direccion de segundo_tr " << &segundo_ptr << endl;

    // La dirección asignada debe ser del tipo al que apunta
    long long real, numero2;
    long long* ptr = &real;
    ptr = &numero2;

    // Ejemplo de múltiple declaración de punteros
    int* puntero1, *puntero2, *puntero3;
    return 0;
}