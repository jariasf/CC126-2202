#include <iostream>
#include <conio.h>
#include <time.h>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 100
#define ALTO_CONSOLA 40
#define COLUMNAS 60
#define FILAS 30
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75
#define DERECHA 77
#define ESCAPE 27
#define X_UL 5 //(x upper-left)
#define Y_UL 3 //(y upper-left)

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
    int x, y;
    int filas, columnas;
};

struct Rectangulo {
    int x, y;
    int alto, ancho;
};

struct Personaje {
    int alto;
    int ancho;
    int color;
    double x, y;
    double dx, dy; // Direccion y tamaño de paso
    double velocidad{1};
    bool mover;
    bool activo;
    int vidas;
    string* cuerpo;
};

void configurar();
//void mostrarLaberinto(int[FILAS][COLUMNAS]);
void mostrarLaberinto(int**, int, int);
void gotoxy(int, int);
void colorear(int);
//void inicializarLaberinto(int[FILAS][COLUMNAS]);
void inicializarLaberinto(int**, int, int);
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
bool intersectan(Rectangulo*, Rectangulo*);
bool intersectan(Personaje*, Personaje*);
void mostrarInformacionDelJuego(Personaje*);

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

void mostrarInformacionDelJuego(Personaje* principal) {
    colorear(GREEN);
    gotoxy(5, Y_UL + COLUMNAS + 5);
    cout << "Juego "<<principal->x<<","<<principal->y << endl;
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
    if( principal -> activo)
        mostrarPersonaje(principal);
    if( enemigo -> activo)
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
            else if (tecla == ESCAPE) {
                break;
            }
        }

        if (principal->activo) {
            if (principal->mover) {
                if (esMovimientoValido(principal, laberinto, filas, columnas)) {
                    moverPersonaje(principal);
                }
            }
        }

        if (enemigo->activo) {
            if (enemigo->mover) {
                if (esMovimientoValido(enemigo, laberinto, filas, columnas)) {
                    moverPersonaje(enemigo);
                }
                else {
                    cambiarDireccion(enemigo);
                }
            }
            if (principal->activo && intersectan(principal, enemigo)) {
                borrarPersonaje(enemigo);
                enemigo->activo = false;
            }
        }

        time(&tiempo_fin);
        int duracion = tiempo_fin - tiempo_inicio;
        // Mostrar enemigo luego de 5 segundos
        if (duracion == 5) {
            enemigo->activo = true;
        }
        mostrarInformacionDelJuego(principal);
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
    personaje->activo = true;
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
    personaje->activo = false;
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

bool intersectan(Rectangulo* r1, Rectangulo* r2) {
    /*
      r1 = {1, 1, 3, 3}   r2 = {1, 2, 4, 3}
      return true si intersectan, false si no

      (l1_x,l1_y)
          -------- 
         |        |
         |        |
         |        |
         |        |
         |________| (r1_x,r1_y)
    */
    int l1_x = r1->x, l1_y = r1 -> y;
    int r1_x = r1->x + r1->alto - 1, r1_y = r1->y + r1->ancho - 1;

    int l2_x = r2->x, l2_y = r2->y;
    int r2_x = r2->x + r2->alto - 1, r2_y = r2->y + r2->ancho - 1;

    if (l2_y > r1_y || l1_y > r2_y) return false;
    if (r1_x < l2_x || r2_x < l1_x) return false;

    return true;
}

bool intersectan(Personaje* p1, Personaje* p2) {
    Rectangulo* r1 = new Rectangulo{(int)p1->x, (int)p1->y, p1->alto, p1->ancho};
    Rectangulo* r2 = new Rectangulo{(int)p2->x, (int)p2->y, p2->alto, p2->ancho };
    bool flag= intersectan(r1, r2);
    delete r1; delete r2;
    return flag;
}

/*
bool intersectan(Personaje* p1, Bala* bala) {

}*/

void mostrarPersonaje(Personaje* personaje) {
    colorear(personaje->color);
    for (int i = 0; i < personaje->alto; ++i) {
        gotoxy(X_UL + personaje->x + i, Y_UL + personaje->y);
        cout << personaje->cuerpo[i];
    }
}

void borrarPersonaje(Personaje* personaje) {
    for (int i = 0; i < personaje->alto; ++i) {
        for (int j = 0; j < personaje->ancho; ++j) {
            gotoxy(X_UL + personaje->x + i, Y_UL + personaje->y + j);
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
            gotoxy(X_UL + i, Y_UL + j);
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