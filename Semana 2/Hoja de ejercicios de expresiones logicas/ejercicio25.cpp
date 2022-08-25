#include <iostream>
using namespace std;

int main() {
    short* anho = new short;
    char* empresa = new char;
    double* precio = new double;
    bool* es_valido1 = new bool;
    bool* es_valido2 = new bool;
    bool* es_invalido = new bool;
    char* compra_producto = new char; // S: verdadero, N: falso

    cout << "COMPRA DE PRODUCTO\n";
    cout << "==================\n";
    cout << "INGRESO DE DATOS\n";
    cout << "Año de vencimiento: ";
    cin >> *anho;
    cout << "Empresa de fabricación (K: King, Q: Queen, T: Thor): ";
    cin >> *empresa;
    cout << "Precio: ";
    cin >> *precio;

    // numero impar, King(K) o Queen(Q), Entre 20 y 50 inclusive
    *es_valido1 = (*anho % 2 != 0) && 
                  (*empresa == 'K' || *empresa == 'Q') && 
                  (*precio >= 20 && *precio <= 50);

    // divisible por 50, Thor(T), Entre 51 y 60 inclusive
    *es_valido2 = (*anho % 50 == 0) &&
                  (*empresa == 'T') &&
                  (*precio >= 51 && *precio <= 60);

    *es_invalido = !*es_valido1 && !*es_valido2;

    //R =  C1 * R1 + C2 * R2 + C3 * R3

    //*es_valido1 = 0, *es_valido2 = 1, *es_invalido = 0
    // = 1 * 'S' + 0 * 'S' + 0 * 'N' = 'S'
    // = 0 * 'S' + 1 * 'S' + 0 * 'N' = 'S'
    // = 0 * 'S' + 0 * 'S' + 1 * 'N' = 'N'
    *compra_producto = *es_valido1 * 'S' + *es_valido2 * 'S' + *es_invalido * 'N';

    cout << "\n¿REALIZA LA COMPRA? " << *compra_producto << endl;

    delete anho;
    delete empresa;
    delete precio;
    delete es_valido1;
    delete es_valido2;
    delete es_invalido;
    delete compra_producto;
    return 0;
}