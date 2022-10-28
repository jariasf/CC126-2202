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
float nextFloat(float, float);
void mostrarPantallaFinal();
void inicializarValores(float*, float*, float*, float*, char*, int*, int*, int);
bool existanCaracteres(bool*, int);
bool validaPosicion(float, float);
void mostrarObjeto(float, float, char, int, int);
void mostrarObjetos(float*, float*, char*, int*, int*, int);
void borrarObjeto(float, float, int);
void moverObjeto(float&, float&, float&, float, char, int, int);
void mostrarCaracter(int, int, char, int);
void borrarCaracter(int, int);

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

void inicializarValores(float* x, float* y, float* dx, float* dy, char* caracteres,
    int* colores, int* tamanios, int n) {
    for (int i = 0; i < n; ++i) {
        // Inicializar posiciones
        x[i] = 1;
        y[i] = nextInt(1, ANCHO - 1);

        // Inicializar incrementos
        dx[i] = nextFloat(0.1, 1.0);
        dy[i] = 0;

        // Inicializar caracteres
        caracteres[i] = '*';

        // Inicializar colores
        colores[i] = nextInt(0, 15);

        // Inicializar tamaños
        tamanios[i] = nextInt(1, 4);
    }
}

bool validaPosicion(float x, float y) {
    return x >= 0 && y >= 0 && x < ALTO&& y < ANCHO;
}

void mostrarObjeto(float x, float y, char c, int color, int tamanio) {
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x + i, y)) continue;
        Console::SetCursorPosition(y, x + i);
        colorear(color);
        cout << c;
    }
}

void borrarObjeto(float x, float y, int tamanio) {
    for (int i = 0; i < tamanio; ++i) {
        if (!validaPosicion(x + i, y)) continue;
        Console::SetCursorPosition(y, x + i);
        cout << ' ';
    }
}

void moverObjeto(float& x, float& y, float& dx, float dy, char caracter, int color, int tamanio) {
    borrarObjeto(x, y, tamanio);
    x += dx; y += dy;
    mostrarObjeto(x, y, caracter, color, tamanio);
    if (x + tamanio - 1 >= ALTO - 1 || x < 1) dx = -dx;
}

void mostrarObjetos(float* x, float* y, char* caracteres, int* colores, int* tamanios, int n) {
    for (int i = 0; i < n; ++i) {
        mostrarObjeto(x[i], y[i], caracteres[i], colores[i], tamanios[i]);
    }
}


void mostrarCaracter(int x, int y, char c, int color) {
    if (!validaPosicion(x, y)) return;
    Console::SetCursorPosition(y, x);
    colorear(color);
    cout << c;
}

void borrarCaracter(int x, int y) {
    if (!validaPosicion(x, y)) return;
    Console::SetCursorPosition(y, x);
    cout << " ";
}

bool existanCaracteres(bool* eliminados, int n) {
    for (int i = 0; i < n; ++i) {
        if (!eliminados[i]) return true;
    }
    return false;
}

void simularDescensoDeCaracter() {
    int n{5};
    float* x = new float[n], * y = new float[n];
    float* dx = new float[n], * dy = new float[n];
    char* caracteres = new char[n];
    int* colores = new int[n];
    int* tamanios = new int[n];
    bool* eliminados = new bool[n]{};
    char tecla;

    // Nuevo objeto
    int xn{ALTO-1}, yn{ANCHO/2}, dxn{-1}, dyn{0};
    int xn2{ALTO - 1}, yn2{ANCHO - 1}, dxn2{-1}, dyn2{0};
    int num_nuevos{0};
    //bool mostrar_nuevo{false}, mostrar_segundo{false};

    inicializarValores(x, y, dx, dy, caracteres, colores, tamanios, n);
    mostrarObjetos(x, y, caracteres, colores, tamanios, n);

    while (existanCaracteres(eliminados, n)) {

        if (_kbhit()) {
            tecla = _getch();
            if (tecla == 'R' || tecla == 'r') {
                // Eliminación de objetos mediante tecla
                int posicion_eliminar;
                
                // Generar una posición que no haya sido eliminada
                do {
                    posicion_eliminar = nextInt(0, n - 1);
                } while (eliminados[posicion_eliminar]);

                borrarObjeto(x[posicion_eliminar], y[posicion_eliminar], tamanios[posicion_eliminar]);
                eliminados[posicion_eliminar] = true;
            }
            else if ( (tecla == 'A' || tecla == 'a') && num_nuevos < 2 ) {
                num_nuevos++;
            }
        }

        // Nuevos caracteres que se mueven de abajo hacia arriba
        if (num_nuevos > 0) {
            borrarCaracter(xn, yn);
            if (validaPosicion(xn + dxn, yn + dyn)) {
                xn += dxn;
                yn += dyn;
                mostrarCaracter(xn, yn, '%', 13);
            }
        }
        if (num_nuevos > 1) {
            borrarCaracter(xn2, yn2);
            if (validaPosicion(xn2 + dxn2, yn2 + dyn2)) {
                xn2 += dxn2;
                yn2 += dyn2;
                mostrarCaracter(xn2, yn2, '?', 13);
            }
        }

        // Simulación de objetos
        for (int i = 0; i < n; ++i) {
            if (!eliminados[i]) {
                moverObjeto(x[i], y[i], dx[i], dy[i], caracteres[i], colores[i], tamanios[i]);
                if (!validaPosicion(x[i], y[i])) {
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