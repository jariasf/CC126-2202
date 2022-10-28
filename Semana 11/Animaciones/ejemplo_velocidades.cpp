#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
#define ANCHO 80 
#define ALTO 30 

void configurar();
int nextInt(int, int);
float nextFloat(float, float);
void simularVelocidadesEnteras();
void simularVelocidadesFlotantes();
void generarNumerosFlotantes(int, float, float);

int main() {
    configurar();
    //simularVelocidadesEnteras();
    simularVelocidadesFlotantes();
    //generarNumerosFlotantes(10, 0.1, 1.0);

    char c = _getch();
    return 0;
}

void configurar() {
    srand(time(NULL));
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

float nextFloat(float min, float max) {
    return  min + rand() * (max - min) / RAND_MAX;
}

void simularVelocidadesEnteras() {
    int x1{1}, y1{1}, x2{1}, y2{5};
    int dx1{1}, dy1{0}, dx2{3}, dy2{0};
    //int v1{1}, v2{1};

    //v1 = nextInt(1, 5);
    //v2 = nextInt(1, 5);
    dx1 = nextInt(1, 5);
    dx2 = nextInt(1, 5);
    cout << "Velocidades enteras\n";
    while (x1 < ALTO || x2 < ALTO ) {
        cout<<"("<<x1<<","<<y1<< ")      " << "(" << x2 << "," << y2 << ")\n";
        if (x1 < ALTO) {
            x1 += dx1; y1 += dy1;
        }
        if (x2 < ALTO) {
            x2 += dx2; y2 += dy2;
        }
    }
}


void simularVelocidadesFlotantes() {
    float x1{1}, y1{1}, x2{1}, y2{5};
    float dx1{1}, dy1{0}, dx2{0.2}, dy2{0};

    dx1 = nextFloat(0.1, 1);
    dx2 = nextFloat(0.1, 1);

    cout << "Velocidades flotantes\n";
    while (x1 < ALTO || x2 < ALTO) {
        cout << "(" << x1 << "," << y1 << ")      " << "(" << x2 << "," << y2 << ")\n";
        if (x1 < ALTO) {
            x1 += dx1; y1 += dy1;
        }
        if (x2 < ALTO) {
            x2 += dx2; y2 += dy2;
        }
    }
}


void generarNumerosFlotantes(int n, float min, float max) {
    cout << "Generacion de numeros flotantes\n";
    for (int i = 0; i < n; ++i) {
        cout << i + 1 << ": " << nextFloat(min, max)<<endl;
    }
}