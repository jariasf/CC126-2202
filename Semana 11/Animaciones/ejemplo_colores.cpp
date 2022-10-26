#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
using namespace System;

enum {
    BLACK, //codigo 0
    DARKBLUE, // codigo 1
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

int nextInt(int, int);
void colorear(int);

int main() {
    srand(time(NULL));
    Console::ForegroundColor = ConsoleColor::Green;
    cout << "Mensaje de color verde" << endl;
    Console::ForegroundColor = ConsoleColor::Red;
    cout << "Mensaje de color rojo" << endl;
    cout << "Otro mensajes" << endl;

    int ROJO = (int)ConsoleColor::Red;
    cout << "Codigo de color rojo " << ROJO << endl;

    //Console::ForegroundColor = (ConsoleColor)6;
    colorear(DARKBLUE);
    cout << "Mensaje de color dark yellow" << endl;


    int codigo_aleatorio = nextInt(0, 15);
    colorear(codigo_aleatorio);
    cout << "COLOR ALEATORIO" << endl;

    char c = _getch();
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void colorear(int codigo) {
    Console::ForegroundColor = (ConsoleColor)codigo;
}