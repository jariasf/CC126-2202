#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#define ANCHO 50 //[0,49]
#define ALTO 30  //[0,29]
#define CARACTER '*'
#define ROJO 12

void configurar();
void simularDescensoDeCaracter();
void colorear(int);
int nextInt(int, int);
void mostrarPantallaFinal();
void inicializarValores(int*, int*, int*, int*, char*, int*, int*, int);
bool posicionesValidas(int*, int);
bool existanCaracteres(bool*, int);
bool validaPosicion(int, int);
void mostrarObjeto(int, int, char, int, int);
void mostrarObjetos(int*, int*, char*, int*, int*, int);
void borrarObjeto(int, int, int);
void moverObjeto(int&, int&, int, int, char, int, int);

int main() {
    configurar();
    simularDescensoDeCaracter();
    mostrarPantallaFinal();
    char c = _getch();
    return 0;
}

void configurar() {
    srand(time(NULL));
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
}

void mostrarPantallaFinal() {
    Console::Clear();
    Console::SetCursorPosition(ANCHO / 2 - 10, ALTO / 2);
    Console::ForegroundColor = ConsoleColor::White;
    cout << "Simulacion finalizada!" << endl;
    //_sleep(3000);
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void inicializarValores(int* x, int* y, int* dx, int* dy, char* caracteres,
    int* colores, int* tamanios, int n) {
    for (int i = 0, col = 1; i < n; ++i, col += 2) {
        // Inicializar posiciones
        x[i] = 1;
        y[i] = col;

        // Inicializar incrementos
        dx[i] = 1;
        dy[i] = 0;

        // Inicializar caracteres
        caracteres[i] = '*';

        // Inicializar colores
        colores[i] = nextInt(0, 15);

        // Inicializar tamaños
        tamanios[i] = nextInt(1, 4);
    }
}

bool validaPosicion(int x, int y) {
    return x >= 0 && y >= 0 && x < ALTO && y < ANCHO;
}

void mostrarObjeto(int x, int y, char c, int color, int tamanio) {
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x + i, y)) continue;
        Console::SetCursorPosition(y, x + i);
        colorear(color);
        cout << c;
    }
}

void borrarObjeto(int x, int y, int tamanio) {
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x + i, y)) continue;
        Console::SetCursorPosition(y, x + i);
        cout << ' ';
    }
}

void moverObjeto(int& x, int& y, int dx, int dy, char caracter, int color, int tamanio) {
    borrarObjeto(x, y, tamanio);
    x += dx; y += dy;
    mostrarObjeto(x, y, caracter, color, tamanio);
}

void mostrarObjetos(int* x, int* y, char* caracteres, int* colores, int* tamanios, int n) {
    for (int i = 0; i < n; ++i) {
        mostrarObjeto(x[i], y[i], caracteres[i], colores[i], tamanios[i]);
    }
}

bool posicionesValidas(int* x, int n) {
    for (int i = 0; i < n; ++i) {
        if (x[i] < ALTO) return true;
    }
    return false;
}

bool existanCaracteres(bool* eliminados, int n) {
    for (int i = 0; i < n; ++i) {
        if (!eliminados[i]) return true;
    }
    return false;
}

void simularDescensoDeCaracter() {
    int n{20};
    int* x = new int[n], * y = new int[n];
    int* dx = new int[n], * dy = new int[n];
    char* caracteres = new char[n];
    int* colores = new int[n];
    int* tamanios = new int[n];
    bool* eliminados = new bool[n] {};

    inicializarValores(x, y, dx, dy, caracteres, colores, tamanios, n);
    mostrarObjetos(x, y, caracteres, colores, tamanios, n);

    while (existanCaracteres(eliminados, n)) {
        for (int i = 0; i < n; ++i) {
            if (!eliminados[i]) {
                moverObjeto(x[i], y[i], dx[i], dy[i], caracteres[i], colores[i], tamanios[i]);
                if (x[i] >= ALTO) {
                    eliminados[i] = true;
                }
            }
        }
        _sleep(200);
    }

    delete[] x;
    delete[] y;
    delete[] dx;
    delete[] dy;
    delete[] caracteres;
    delete[] colores;
    delete[] eliminados;
    delete[] tamanios;
    //char c = _getch();
}