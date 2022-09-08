#include <iostream>
using namespace std;

int main() {
    short* edad = new short;
    short* precio = new short;
    cout << "Ingrese la edad de la persona: ";
    cin >> *edad;

    // Validacion
    if (*edad > 0) {
        // Caso válido
        if (*edad < 18) {
            *precio = 7;
        }
        else if (*edad >= 18 && *edad <= 50) {
            *precio = 15;
        }
        else {
            *precio = 5;
        }
        cout << "El precio de la entrada es de " << *precio << " soles\n";
    }else{
        // Caso inválido
        cout << "La edad ingresada es invalida.\n";
    }


    delete edad;
    delete precio;
    return 0;
}