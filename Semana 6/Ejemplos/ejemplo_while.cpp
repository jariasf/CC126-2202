#include <iostream>
using namespace std;
/*
Ingresar el primer caracter del nombre de un juego (A: Apex, D: Dota, F: Fornite)
Ingresar el primer caracter del nombre del jugador
Ingresa hasa que el caracter del nombre del juego sea X

Entrada
Ingrese el juego (A: Apex, D: Dota, F: Fornite): A
Ingrese el caracter del nombre: J

Ingrese el juego (A: Apex, D: Dota, F: Fornite): d
Ingrese el caracter del nombre: K

Ingrese el juego (A: Apex, D: Dota, F: Fornite): R
Ingrese el juego (A: Apex, D: Dota, F: Fornite): P
Ingrese el juego (A: Apex, D: Dota, F: Fornite): F
Ingrese el caracter del nombre: A

Ingrese el juego (A: Apex, D: Dota, F: Fornite): X
*/

char ingresarJuego() {
    char juego;
    do {
        cout << "Ingrese el juego (A: Apex, D: Dota, F: Fornite): ";
        cin >> juego;
        juego = toupper(juego);
    } while ( juego != 'A' && juego != 'D' && juego != 'F' && juego != 'X');
    //} while ( !(juego == 'A' || juego == 'D' || juego == 'F' || juego == 'X'));
    return juego;
}

char ingresarNombre() {
    char nombre;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    return nombre;
}

void ingresarUsandoWhile() {
    char juego, nombre;
    juego = ingresarJuego();
    while (juego != 'X') {
        // Ingresar mas valores
        nombre = ingresarNombre();
        // Operaciones como conteos, hallar el mayor, el menor, usar if-else, etc.

        // Ingreso del juego
        cout << "\n";
        juego = ingresarJuego();
    }
}

void ingresarUsandoDoWhile() {
    char juego, nombre;
    do {
        juego = ingresarJuego();
        if (juego != 'X') {
            // Ingresar mas valores
            nombre = ingresarNombre();

            // Operaciones como conteos, hallar el mayor, el menor, usar if-else, etc.

            cout << "\n";
        }
    } while (juego != 'X');
}

int main() {
    //ingresarUsandoWhile();
    //ingresarUsandoDoWhile();
    return 0;
}