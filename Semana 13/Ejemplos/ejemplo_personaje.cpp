#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;

#define ANCHO_CONSOLA 60
#define ALTO_CONSOLA 30
#define COLUMNAS 60
#define FILAS 30

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

struct Personaje{
    int alto;
    int ancho;
    int color;
    int x, y;
    string* cuerpo;
};


void configurar();
void mostrarLaberinto(int[FILAS][COLUMNAS]);
void gotoxy(int, int);
void colorear(int);
void inicializarLaberinto(int[FILAS][COLUMNAS]);
void mostrarPersonaje(char[4][4], int, int, int, int);
void mostrarPersonaje(int, int);
void mostrarPersonaje(int, int, string*, int n);
void mostrarPersonaje(Personaje);
void mostrarPersonaje(Personaje*);
void limpiarMemoriaPersonaje(Personaje*);

int main() {
    configurar();
    int laberinto[FILAS][COLUMNAS];
    inicializarLaberinto(laberinto);
    mostrarLaberinto(laberinto);

    // 1. Ejemplo de personaje usando matriz estática
    int alto{4}, ancho{4}, x{5}, y{1};
    char personaje[4][4] = {
        {'(','O',')'},
        {'_','|','_'},
        {' ','|',' '},
        {' ','|',' '},
    };

    //mostrarPersonaje(personaje, alto, ancho, x, y);

    // 2. Ejemplo de personaje usando arreglo de strings
    //char arreglo[5] = { 'a', 'b', 'c', 'd', '\0' }; //"abcd"
    //cout << arreglo << endl;

    //mostrarPersonaje(x , y);

    string personaje2[3] = {
        "(O)",
        "-|-",
        " | "
    };
    alto = 3;
    mostrarPersonaje(x, y, personaje2, alto);


    string personaje3[4] = {
        "(O)-",
        "-|--",
        " |  "
    };
    alto = 3;
    mostrarPersonaje(10, 10, personaje3, alto);


    // 3. Usando estructuras
    // Memoria pila
    Personaje personaje4;
    personaje4.x = 1;
    personaje4.y = 1;
    personaje4.alto = 3;
    personaje4.ancho = 3;
    personaje4.color = GREEN;
    personaje4.cuerpo = new string[3]{
        "(O)",
        "-|-",
        "---"
    };

    mostrarPersonaje(personaje4);
    delete[] personaje4.cuerpo;

    // Memoria dinámica
    //int* variable_dinamica = new int;
    Personaje* personaje5 = new Personaje;
    personaje5 -> x = 1;
    personaje5 -> y = 8;
    personaje5 -> alto = 3;
    personaje5 -> ancho = 3;
    personaje5 -> color = BLUE;
    personaje5 -> cuerpo = new string[3]{
        "(O)",
        "-|-",
        "---"
    };

    mostrarPersonaje(personaje5);

    limpiarMemoriaPersonaje(personaje5);

    system("pause>0");
    return 0;
}

void limpiarMemoriaPersonaje(Personaje* personaje) {
    delete[] personaje->cuerpo;
    delete personaje;
}

void mostrarPersonaje(char personaje[4][4], int alto, int ancho, int x, int y) {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            gotoxy(x + i , y + j);
            colorear(YELLOW);
            cout << personaje[i][j];
        }
    }
}

/*
void mostrarPersonaje(int x, int y) {
    colorear(YELLOW);
    gotoxy(x+0, y);
    cout << "(O)";
    gotoxy(x+1, y);
    cout << "-|-";
    gotoxy(x+2, y);
    cout << " | ";
}*/

void mostrarPersonaje(int x, int y) {
    string personaje[4] = {
        "(O)",
        "-|-",
        " | ",
        " - "
    };
    int alto = 4;
    colorear(YELLOW);
    for (int i = 0; i < alto; ++i) {
        gotoxy(x + i, y);
        cout << personaje[i];
    }
}

void mostrarPersonaje(int x, int y, string* personaje, int alto) {
    colorear(YELLOW);
    for (int i = 0; i < alto; ++i) {
        gotoxy(x + i, y);
        cout << personaje[i];
    }
}

void mostrarPersonaje(Personaje personaje) {
    colorear(personaje.color);
    for (int i = 0; i < personaje.alto; ++i) {
        gotoxy(personaje.x + i, personaje.y);
        cout << personaje.cuerpo[i];
    }
}

void mostrarPersonaje(Personaje* personaje) {
    colorear(personaje -> color);
    for (int i = 0; i < personaje -> alto; ++i) {
        gotoxy(personaje -> x + i, personaje -> y);
        cout << personaje -> cuerpo[i];
    }
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

void inicializarLaberinto(int laberinto[FILAS][COLUMNAS]) {
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

    for (int i = 0; i < FILAS; ++i) {
        for (int j = 0; j < COLUMNAS; ++j) {
            laberinto[i][j] = auxiliar[i][j];
        }
    }
}