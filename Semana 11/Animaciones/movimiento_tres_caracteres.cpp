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
void mostrarCaracter(int, int, char, int);
void borrarCaracter(int, int);
void colorear(int);
int nextInt(int, int);
void moverCaracter(int&, int&, int, int, char, int);
void mostrarPantallaFinal();

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
    Console::SetCursorPosition(ANCHO/2 - 10, ALTO/2);
    Console::ForegroundColor = ConsoleColor::White;
    cout << "Simulacion finalizada!" << endl;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void colorear(int color) {
    Console::ForegroundColor = (ConsoleColor)color;
}

void mostrarCaracter(int x, int y, char c, int color) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    colorear(color);
    cout << c;
}

void borrarCaracter(int x, int y) {
    if (x < 0 || y < 0 || x >= ALTO || y >= ANCHO) return;
    Console::SetCursorPosition(y, x);
    cout << " ";
}

/*
 0 1 2 3 4 5 6 7 -> y
0
1            o
2      x       x
3
|
v
x

*/

void moverCaracter(int& x, int& y, int dx, int dy, char caracter, int color) {
    borrarCaracter(x, y);
    x += dx; y += dy;
    mostrarCaracter(x, y, caracter, color);
}

void simularDescensoDeCaracter() {
    int x1{1}, y1{10}, dx1{1}, dy1{0};
    int x2{1}, y2{5} , dx2{1}, dy2{0};
    int x3{1}, y3{20}, dx3{1}, dy3{0};
    char caracter1{'*'}, caracter2{'+'}, caracter3{'-'};
    int color1{nextInt(0, 15)}, color2{nextInt(0, 15)}, color3{nextInt(0, 15)};

    mostrarCaracter(x1, y1, caracter1, color1);
    mostrarCaracter(x2, y2, caracter2, color2);
    mostrarCaracter(x3, y3, caracter3, color3);

    while(x1 < ALTO || x2 < ALTO || x3 < ALTO){
        moverCaracter(x1, y1, dx1, dy1, caracter1, color1);
        moverCaracter(x2, y2, dx2, dy2, caracter2, color2);
        moverCaracter(x3, y3, dx3, dy3, caracter3, color3);
        _sleep(200);
    }
    //char c = _getch();
}