#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 60
#define ALTO_CONSOLA 30
#define COLUMNAS 60
#define FILAS 30
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESCAPE 27

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

// Ejemplo de definición de laberinto
struct Laberinto {
    int** matriz;
    int filas, columnas;
};


struct Personaje {
    int alto;
    int ancho;
    int color;
    double x, y;
    double dx, dy; // Direccion y tamaño de paso
    double velocidad{1};
    bool mover;
    bool vivo;
    string* cuerpo;
};

void configurar();
//void mostrarLaberinto(int[FILAS][COLUMNAS]);
void mostrarLaberinto(int**, int, int);
void gotoxy(int, int);
void colorear(int);
//void inicializarLaberinto(int[FILAS][COLUMNAS]);
void inicializarLaberinto(int**, int, int);
void mostrarPersonaje(Personaje);
void mostrarPersonaje(Personaje*);
void limpiarMemoriaPersonaje(Personaje*);
void borrarPersonaje(Personaje*);
void moverPersonaje(Personaje*);
void inicializarPersonaje(Personaje*);
void inicializarEnemigo(Personaje*);
//bool esMovimientoValido(Personaje*, int [FILAS][COLUMNAS]);
bool esMovimientoValido(Personaje*, int**, int, int);
void simularJuegoLaberinto(int**, int, int);
void cambiarDireccion(Personaje*);

int main() {
    configurar();
    int filas{FILAS}, columnas{COLUMNAS};
    int** laberinto = new int* [filas];
    for (int i = 0; i < filas; ++i)
        laberinto[i] = new int[columnas];

    inicializarLaberinto(laberinto, filas, columnas);
    simularJuegoLaberinto(laberinto, filas, columnas);

    //Laberinto* laberinto = new Laberinto;
    //simularJuegoLaberinto(laberinto);
    // Limpieza
    for (int i = 0; i < filas; ++i) {
        delete[] laberinto[i];
    }
    delete[] laberinto;

    system("pause>0");
    return 0;
}

void simularJuegoLaberinto(int** laberinto, int filas, int columnas) {

    mostrarLaberinto(laberinto, filas, columnas);

    time_t tiempo_inicio, tiempo_fin;
    time(&tiempo_inicio);

    // Memoria dinámica
    Personaje* principal = new Personaje;
    Personaje* enemigo = new Personaje;
    char tecla;

    inicializarPersonaje(principal);
    inicializarEnemigo(enemigo);
    if( principal -> vivo)
        mostrarPersonaje(principal);
    if( enemigo -> vivo)
        mostrarPersonaje(enemigo);

    while (1) {
        principal->mover = false;
        if (_kbhit()) {
            tecla = _getch();
            if (tecla == DERECHA) {
                principal->mover = true;
                principal->dx = 0;
                principal->dy = 1;
            }
            else if (tecla == ABAJO) {
                principal->mover = true;
                principal->dx = 1;
                principal->dy = 0;
            }
            else if (tecla == IZQUIERDA) {
                principal->mover = true;
                principal->dx = 0;
                principal->dy = -1;
            }
            else if (tecla == ARRIBA) {
                principal->mover = true;
                principal->dx = -1;
                principal->dy = 0;
            }
        }

        if (principal->vivo) {
            if (principal->mover) {
                if (esMovimientoValido(principal, laberinto, filas, columnas)) {
                    moverPersonaje(principal);
                }
            }
        }

        if (enemigo->vivo) {
            if (enemigo->mover) {
                if (esMovimientoValido(enemigo, laberinto, filas, columnas)) {
                    moverPersonaje(enemigo);
                }
                else {
                    cambiarDireccion(enemigo);
                }
            }
        }

        time(&tiempo_fin);
        int duracion = tiempo_fin - tiempo_inicio;
        // Mostrar enemigo luego de 5 segundos
        if (duracion == 5) {
            enemigo->vivo = true;
        }

        _sleep(50);
    }

    limpiarMemoriaPersonaje(principal);
    limpiarMemoriaPersonaje(enemigo);
}

void inicializarPersonaje(Personaje* personaje) {
    personaje->x = 1;
    personaje->y = 1;
    personaje->dx = 0;
    personaje->dy = 0;
    personaje->mover = false;
    personaje->alto = 3;
    personaje->ancho = 3;
    personaje->color = YELLOW;
    personaje->vivo = true;
    personaje->cuerpo = new string[3]{
        "("+ string(1, 1) + ")",
        "-|-",
        "---"
    };
}

void inicializarEnemigo(Personaje* personaje) {
    personaje->alto = 3;
    personaje->ancho = 3;
    personaje->x = (FILAS - 1) - personaje->alto;
    personaje->y = 1;
    personaje->dx = 0;
    personaje->dy = 1;
    personaje->mover = true;
    personaje->color = GREEN;
    personaje->vivo = false;
    personaje->velocidad = 0.5; // velocidad
    personaje->cuerpo = new string[3]{
        "<o ",
        "-|-",
        "- -"
    };
}

void limpiarMemoriaPersonaje(Personaje* personaje) {
    delete[] personaje->cuerpo;
    delete personaje;
}

/*
bool intersectan(Rectangulo* r1, Rectangulo* r2) {
    return false;
}*/

bool intersectan(Personaje* p1, Personaje* p2) {
    return false;
}

void mostrarPersonaje(Personaje personaje) {
    colorear(personaje.color);
    for (int i = 0; i < personaje.alto; ++i) {
        gotoxy(personaje.x + i, personaje.y);
        cout << personaje.cuerpo[i];
    }
}

void mostrarPersonaje(Personaje* personaje) {
    colorear(personaje->color);
    for (int i = 0; i < personaje->alto; ++i) {
        gotoxy(personaje->x + i, personaje->y);
        cout << personaje->cuerpo[i];
    }
}

void borrarPersonaje(Personaje* personaje) {
    for (int i = 0; i < personaje->alto; ++i) {
        for (int j = 0; j < personaje->ancho; ++j) {
            gotoxy(personaje->x + i, personaje->y + j);
            cout << " ";
        }
    }
}

void moverPersonaje(Personaje* personaje) {
    borrarPersonaje(personaje);
    personaje->x += personaje->dx * personaje->velocidad;
    personaje->y += personaje->dy * personaje->velocidad;
    mostrarPersonaje(personaje);
}

void cambiarDireccion(Personaje* personaje) {
    personaje->dx *= -1;
    personaje->dy *= -1;
}

/*
void moverPersonaje(Personaje& personaje) {
    borrarPersonaje(personaje);

    personaje.x += personaje.dx;
    personaje.y += personaje.dy;

    mostrarPersonaje(personaje);
}*/

//bool esMovimientoValido(Personaje* personaje, int laberinto[FILAS][COLUMNAS]) {
bool esMovimientoValido(Personaje* personaje, int** laberinto, int filas, int columnas) {
    /*
        Entrada:
        x = 1, y = 1, dx = 0, dy = 1, laberinto

        Salida:
        true: es posible avanzar en la dirección dada (al momento de avanzar lo haga sobre
              espacios vacios)
        false: no es posible
    */

    int nx = personaje->x + personaje->dx;
    int ny = personaje->y + personaje->dy;

    for (int i = 0; i < personaje->alto; ++i) {
        for (int j = 0; j < personaje->ancho; ++j) {
            if (laberinto[nx + i][ny + j] == 1) {
                return false;
            }
        }
    }
    return true;
}

void gotoxy(int x, int y) {
    Console::SetCursorPosition(y, x);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void configurar() {
    Console::SetWindowSize(ANCHO_CONSOLA, ALTO_CONSOLA);
    Console::CursorVisible = false;
}

void mostrarLaberinto(int** laberinto, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            gotoxy(i, j);
            if (laberinto[i][j] == 1) colorear(RED);
            else if (laberinto[i][j] == 0) colorear(BLACK);
            else if (laberinto[i][j] == 2) colorear(GREEN);
            cout << (char)219;
        }
    }
}


void mostrarLaberinto(int laberinto[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            gotoxy(i, j);
            if (laberinto[i][j] == 1) colorear(RED);
            else if (laberinto[i][j] == 0) colorear(BLACK);
            else if (laberinto[i][j] == 2) colorear(GREEN);
            cout << (char)219;
        }
    }
}


//void inicializarLaberinto(int laberinto[FILAS][COLUMNAS]) {
void inicializarLaberinto(int** laberinto, int filas, int columnas) {
    int auxiliar[FILAS][COLUMNAS] = {
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
            {1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    //for (int i = 0; i < FILAS; ++i) {
    //    for (int j = 0; j < COLUMNAS; ++j) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            laberinto[i][j] = auxiliar[i][j];
        }
    }
}