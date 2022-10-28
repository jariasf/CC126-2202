#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
using namespace System;
#define ALTO 30
#define ANCHO 50
// Se pueden usar arreglos estaticos como globales o constantes
char simbolos[5] = {'*', '-', '&', '=', '#'};

int nextInt(int, int);
void ejemploStrings();
void generarCaracteres();
int sumar(int*, int n);
void ejemploArreglosEstaticos();

int main() {
	srand(time(NULL));
    ejemploArreglosEstaticos();
    generarCaracteres();
    char c = _getch();
    ejemploStrings();
    return 0;
}

void ejemploStrings() {
    // Ejemplo de texto centrado en pantalla
    // usando strings

    string mensaje{ "Hola mundo" };
    //cout << "String: " << mensaje << endl;
    //cout << "Tamaño del string " << mensaje.size() << endl;
    
    // Mostrar mensaje al centro de la pantalla
    Console::Clear();
    Console::SetWindowSize(ANCHO, ALTO);
    Console::CursorVisible = false;
    Console::SetCursorPosition(ANCHO / 2 - mensaje.size() / 2, ALTO / 2);
    cout << mensaje << endl;
    _sleep(1500);
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarCaracteres() {
    cout << "\nGeneracion de caracteres a partir de un arreglo";
    cout << "\n-----------------------------------------------\n";
    /*
        Generar caracteres apartir de un arreglo, en este ejemplo se genera
        en base al arreglo simbolos. Para ello lo que se genera en realidad
        son indices/posiciones del arreglo y luego se accede al contenido
        De esta forma se pueden generar caracteres específicos
    */
    for (int i = 0; i < 4; ++i) {
        int posicion = nextInt(0, 4);
        cout << "Caracter aleatorio de arreglo: " << simbolos[posicion] << endl;
    }
}

int sumar(int* arreglo, int n) {
    /*
        El funcionamiento de arreglos estáticos en funciones
        es la misma que arreglos dinámicos, la diferencia es que
        no nos preocupamos de los delete
    */
    int suma{0};
    for (int i = 0; i < n; ++i) {
        arreglo[i]++;
        suma += arreglo[i];
    }
    return suma;
}

void ejemploArreglosEstaticos() {
    cout << "\nArreglos Estaticos";
    cout << "\n------------------\n";
    // Declaración e inicialización de arreglo dinámico
    int n{10};
    int* arreglo_dinamico = new int[n] {1, 34, 523, 1, 2, 34};


    // Declaración e inicialización de arreglo estático
    cout << "Arreglo asignado de forma estatica\n";
    int n2{6};
    // En arreglos estáticos es necesario especificar el tamaño
    int arreglo_estatico[6] = {1,34,523,1,2,34};

    // Mostramos contenido del arreglo de forma similar a dinámicos
    cout << "Antes de llamar a la funcion...\n";
    for (int i = 0; i < n2; ++i) {
        cout << arreglo_estatico[i] << " ";
    }
    cout << endl;

    // Llamada a funciones es de igual forma que con dinámicos
    cout << "\nLa suma es " << sumar(arreglo_estatico, n2) << endl;

    // Mostramos contenido del arreglo de forma similar a dinámicos
    // El paso es por puntero, cualquier cambio dentro de la función
    // afecta al arreglo original
    cout << "\nDespues de llamar a la funcion...\n";
    for (int i = 0; i < n2; ++i) {
        cout << arreglo_estatico[i] << " ";
    }
    cout << endl;

    // Solo se libera memoria del arreglo dinámico
    delete[] arreglo_dinamico;
}