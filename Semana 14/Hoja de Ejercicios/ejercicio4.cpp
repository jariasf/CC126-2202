#include<iostream>
#include<conio.h>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 40
#define ALTO_CONSOLA 40
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESCAPE 27
#define VACIO 0
#define PARED 1
#define RASTRO 2

enum {
    BLACK,
    DARKBLUE,
    DARKGREEN,
    DARKCYAN,
    DARKRED,
    DARKMAGENTA,
    DARKYELLOW,
    GRAY,
    DARKGRAY,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    YELLOW,
    WHITE
};

struct Matriz {
    int** valores{nullptr};
    int filas, columnas;
};

struct Jugador {
    int x, y;
    int dx, dy;
    int color;
    char caracter;
    bool mover;
};

void configurar();
void gotoxy(int, int);
void colorear(int);
void inicializarMatriz(Matriz*);
void liberarMemoriaMatriz(Matriz*);
void generarMatriz(Matriz*);
void mostrarMatriz(Matriz*);
void inicializarJugador(Jugador*);
void mostrarJugador(Jugador*);
void simularMovimiento(Matriz*, Jugador*);
void borrarJugador(Jugador*);
void moverJugador(Jugador*, Matriz*);
bool estaVacio(Jugador*, Matriz*);
void agregarRastro(Matriz*, int, int);

int main() {
    configurar();
    
    // Matriz
    Matriz* matriz = new Matriz;
    inicializarMatriz(matriz);
    generarMatriz(matriz);
    mostrarMatriz(matriz);

    // Jugador
    Jugador* jugador = new Jugador;
    inicializarJugador(jugador);

    // Simulación
    simularMovimiento(matriz, jugador);

    // Liberación de memoria
    liberarMemoriaMatriz(matriz);
    delete jugador;

    //system("pause>0");
    return 0;
}

void simularMovimiento(Matriz* matriz, Jugador* jugador) {
    mostrarJugador(jugador);
    char letra;
    while (1) {
        jugador->mover = false;
        if (_kbhit()) {
            letra = _getch();
            if (letra == ARRIBA) {
                jugador->mover = true;
                jugador->dx = -1;
                jugador->dy = 0;
            }
            else if (letra == DERECHA) {
                jugador->mover = true;
                jugador->dx = 0;
                jugador->dy = 1;
            }
            else if (letra == ABAJO) {
                jugador->mover = true;
                jugador->dx = 1;
                jugador->dy = 0;
            }
            else if (letra == IZQUIERDA) {
                jugador->mover = true;
                jugador->dx = 0;
                jugador->dy = -1;
            }
            else if (letra == ESCAPE) {
                break;
            }
        }
        if (jugador->mover) {
            if (estaVacio(jugador, matriz)) {
                moverJugador(jugador, matriz);
            }
        }
    }
}

bool estaVacio(Jugador* jugador, Matriz* matriz) {
    int nx = jugador->x + jugador->dx;
    int ny = jugador->y + jugador->dy;
    if (matriz->valores[nx][ny] == PARED || matriz->valores[nx][ny] == RASTRO) return false;
    return true;
}

void agregarRastro(Matriz* matriz, int x, int y) {
    matriz->valores[x][y] = RASTRO;
    colorear(GRAY);
    gotoxy(x, y);
    cout << (char)219;
}

void moverJugador(Jugador* jugador, Matriz* matriz) {
    borrarJugador(jugador);
    agregarRastro(matriz, jugador->x, jugador->y);
    jugador->x += jugador->dx;
    jugador->y += jugador->dy;
    mostrarJugador(jugador);
}

void mostrarJugador(Jugador* jugador) {
    colorear(jugador->color);
    gotoxy(jugador->x, jugador->y);
    cout << jugador->caracter;
}

void borrarJugador(Jugador* jugador) {
    gotoxy(jugador->x, jugador->y);
    cout << " ";
}

void inicializarJugador(Jugador* jugador) {
    jugador->x = 1;
    jugador->y = 1;
    jugador->dx = 0;
    jugador->dy = 0;
    jugador->mover = false;
    jugador->color = GREEN;
    jugador->caracter = '*';
}

void mostrarMatriz(Matriz* matriz) {
    for (int i = 0; i < matriz->filas; ++i) {
        gotoxy(i, 0);
        for (int j = 0; j < matriz->columnas; ++j) {
            if (matriz->valores[i][j] == PARED) colorear(RED);
            else colorear(BLACK);
            cout << (char)219;
        }
    }
}

void generarMatriz(Matriz* matriz) {
    for (int i = 0; i < matriz->filas; ++i) {
        matriz->valores[i][0] = PARED;
        matriz->valores[i][matriz->columnas - 1] = PARED;
    }

    for (int j = 0; j < matriz->columnas; ++j) {
        matriz->valores[0][j] = PARED;
        matriz->valores[matriz-> filas - 1][j] = PARED;
        matriz->valores[23][j] = PARED;
    }

    matriz->valores[23][8] = VACIO;
    matriz->valores[23][31] = matriz->valores[23][32] = VACIO;
}

void inicializarMatriz(Matriz* matriz) {
    matriz->filas = 40;
    matriz->columnas = 40;
    matriz->valores = new int* [matriz->filas];
    for (int i = 0; i < matriz->filas; ++i)
        matriz->valores[i] = new int[matriz->columnas]{};
}

void liberarMemoriaMatriz(Matriz* matriz) {
    if (matriz->valores != nullptr) {
        for (int i = 0; i < matriz->filas; ++i)
            delete[] matriz->valores[i];
        delete[] matriz->valores;
    }
    delete matriz;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void gotoxy(int x, int y) {
    Console::SetCursorPosition(y, x);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}