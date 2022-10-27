#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#define ANCHO 50 
#define ALTO 30 

void configurar();
void mostrarObjetoArribaAbajo(int, int, int, char);
void mostrarObjetoAbajoArriba(int, int, int, char);
void mostrarObjetoDerechaIzquierda(int, int, int, char);
void mostrarObjetoIzquierdaDerecha(int, int, int, char);

int main() {
    configurar();

    // ----------------------------------
    // Mostrar objetos de forma vertical
    // ----------------------------------
    // Caracteres se imprimien de arriba hacia abajo
    int x{1}, y{4}, tamanio{4};
    mostrarObjetoArribaAbajo(x, y, tamanio, '*');
    int x2{28}, y2{7}, tamanio2{10};
    mostrarObjetoArribaAbajo(x2, y2, tamanio2, '/');

    // Caracteres se imprimien de abajo hacia arriba
    int x3{ALTO- 1}, y3{10}, tamanio3{6};
    mostrarObjetoAbajoArriba(x3, y3, tamanio3, '+');

    // -----------------------------------
    // Mostrar objetos de forma horizontal
    // -----------------------------------
    // Caracteres se imprimien de derecha a izquierda
    int x4{20}, y4{ANCHO - 1}, tamanio4{5};
    mostrarObjetoDerechaIzquierda(x4, y4, tamanio4, '&');

    // Caracteres se imprimien de izquierda a derecha
    int x5{10}, y5{ANCHO - 6}, tamanio5{6};
    mostrarObjetoIzquierdaDerecha(x5, y5, tamanio5, '*');

    char c = _getch();
    return 0;
}

void configurar() {
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
}

bool validaPosicion(int x, int y) {
    return x >= 0 && y >= 0 && x < ALTO && y < ANCHO;
}

void mostrarObjetoArribaAbajo(int x, int y, int tamanio, char c) {
    /*
       Mostrar objetos de forma vertical donde el punto de inicio
       es el caracter superior
         0 1 2 3 4 5 6
       0     
       1     * <- punto de inicio
       2     * |  
       3     * |  se imprime hacia abajo
       4     * v
       5  
    */

    /*
    Console::SetCursorPosition(y, x);     // (x, y)   -> (1,2)
    cout << c;
    Console::SetCursorPosition(y, x + 1); // (x+1, y) -> (2,2)
    cout << c;
    Console::SetCursorPosition(y, x + 2); // (x+2, y) -> (3,2)
    cout << c;
    Console::SetCursorPosition(y, x + 3); // (x+3, y) -> (4,2)
    cout << c;*/
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x+i, y)) continue;
        Console::SetCursorPosition(y, x + i);
        cout << c;
    }
}

void mostrarObjetoAbajoArriba(int x, int y, int tamanio, char c) {
    /*
       Mostrar objetos de forma vertical donde el punto de inicio
       es el caracter inferior
         0 1 2 3 4 5 6
       0
       1     * ^ 
       2     * |  se imprime hacia arriba 
       3     * |  
       4     * <- punto de inicio
       5
    */

    /*
    Console::SetCursorPosition(y, x);     // (x, y)   -> (4,2)
    cout << c;
    Console::SetCursorPosition(y, x - 1); // (x-1, y) -> (3,2)
    cout << c;
    Console::SetCursorPosition(y, x - 2); // (x-2, y) -> (2,2)
    cout << c;
    Console::SetCursorPosition(y, x - 3); // (x-3, y) -> (1,2)
    cout << c;*/
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x - i, y)) continue;
        Console::SetCursorPosition(y, x - i);
        cout << c;
    }
}

void mostrarObjetoDerechaIzquierda(int x, int y, int tamanio, char c) {
    /*
       Mostrar objetos de forma horizontal donde el punto de inicio
       es el caracter del extremo derecho
         0 1 2 3 4 5 6
       0
       1             punto de inicio
       2             |
       3             v
       4       * * * *
       5       < - - - se imprime hacia la izquierda
    */

    /*
    Console::SetCursorPosition(y, x);     // (x, y)   -> (4,6)
    cout << c;
    Console::SetCursorPosition(y - 1, x); // (x, y-1) -> (4,5)
    cout << c;
    Console::SetCursorPosition(y - 2, x); // (x, y-2) -> (4,4)
    cout << c;
    Console::SetCursorPosition(y - 3, x); // (x, y-3) -> (4,3)
    cout << c;*/

    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x, y - i)) continue;
        Console::SetCursorPosition(y - i, x);
        cout << c;
    }
}

void mostrarObjetoIzquierdaDerecha(int x, int y, int tamanio, char c) {
    /*
       Mostrar objetos de forma horizontal donde el punto de inicio
       es el caracter del extremo izquierdo
         0 1 2 3 4 5 6
       0
       1       punto de inicio
       2       |
       3       v
       4       * * * *
       5       - - - -> se imprime hacia la derecha
    */

    /*
    Console::SetCursorPosition(y, x);     // (x, y)   -> (4,3)
    cout << c;
    Console::SetCursorPosition(y + 1, x); // (x, y+1) -> (4,4)
    cout << c;
    Console::SetCursorPosition(y + 2, x); // (x, y+2) -> (4,5)
    cout << c;
    Console::SetCursorPosition(y + 3, x); // (x, y+3) -> (4,6)
    cout << c;*/

    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x, y + i)) continue;
        Console::SetCursorPosition(y + i, x);
        cout << c;
    }
}