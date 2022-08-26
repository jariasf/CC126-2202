#include <iostream>
using namespace std;

int main() {
    
    long long* codigo = new long long;
    short* valor_perecible = new short;
    char* tipo_producto = new char;
    short* anho = new short;
    short* mes = new short;
    short* dia = new short;
    bool* es_perecible = new bool;

    cout << "Ingrese codigo de barras: ";
    cin >> *codigo;

    // 120820206712
    *valor_perecible = *codigo % 100; // 12
    //*codigo = *codigo / 100; 
    *codigo /= 100;  // 1208202067
    *tipo_producto = *codigo % 100;   // 67
    *codigo /= 100;  // 12082020
    *anho = *codigo % 10000;  // 2020
    *codigo /= 10000; // 1208
    *mes = *codigo % 100; // 08
    *dia = *codigo / 100;   // 12

    // PP: Un entero que indica si el producto es perecible o no. 00 significa perecible.
    *es_perecible = (*valor_perecible == 0);

    cout << "Día de vencimiento: " << *dia << endl;
    cout << "Mes de vencimiento: " << *mes << endl;
    cout << "Año de vencimiento: " << *anho << endl;
    cout << "El tipo de producto es: " << *tipo_producto << endl;
    cout << "Producto perecible(0: No; 1: Sí): " << *es_perecible << endl;

    delete codigo;    
    delete valor_perecible;
    delete tipo_producto;
    delete anho;
    delete mes;
    delete dia;
    delete es_perecible;
    return 0;
}