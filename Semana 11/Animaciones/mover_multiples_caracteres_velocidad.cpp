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
void mostrarCaracter(float, float, char, int);
void borrarCaracter(float, float);
void colorear(int);
int nextInt(int, int);
float nextFloat(float, float);
void moverCaracter(float&, float&, float, float, char, int);
void mostrarPantallaFinal();
void inicializarValores(float*, float*, float*, float*, char*, int*, int);
void mostrarCaracteres(float*, float*, char*, int*, int);
bool posicionesValidas(float*, int);
bool existanCaracteres(bool*, int);

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

float nextFloat(float min, float max) {
    return min + rand() * (max - min) / RAND_MAX;
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void mostrarCaracter(float x, float y, char c, int color) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    colorear(color);
    cout << c;
}

void borrarCaracter(float x, float y) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    cout << " ";
}

void moverCaracter(float& x, float& y, float dx, float dy, char caracter, int color) {
    borrarCaracter(x, y);
    x += dx; y += dy;
    mostrarCaracter(x, y, caracter, color);
}

void inicializarValores(float* x, float* y, float* dx, float* dy, char* caracteres, int* colores, int n) {
    for (int i = 0, col = 1; i < n; ++i, col += 2) {
        // Inicializar posiciones
        x[i] = 1;
        y[i] = col;

        // Inicializar incrementos
        dx[i] = nextFloat(0.1, 1);
        dy[i] = 0;

        // Inicializar caracteres
        caracteres[i] = (char)nextInt('A', 'Z');

        // Inicializar colores
        colores[i] = nextInt(0, 15);
    }
}

void mostrarCaracteres(float* x, float* y, char* caracteres, int* colores, int n) {
    for (int i = 0; i < n; ++i) {
        mostrarCaracter(x[i], y[i], caracteres[i], colores[i]);
    }
}

bool posicionesValidas(float* x, int n) {
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
    float* x = new float[n], * y = new float[n];
    float* dx = new float[n], * dy = new float[n];
    char* caracteres = new char[n];
    int* colores = new int[n];
    bool* eliminados = new bool[n] {};

    inicializarValores(x, y, dx, dy, caracteres, colores, n);
    mostrarCaracteres(x, y, caracteres, colores, n);

    while (existanCaracteres(eliminados, n)) {
        for (int i = 0; i < n; ++i) {
            if (!eliminados[i]) {
                moverCaracter(x[i], y[i], dx[i], dy[i], caracteres[i], colores[i]);
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
    //char c = _getch();
}