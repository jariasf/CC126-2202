#include <iostream>
#include <iomanip>
using namespace std;

struct Persona {
    int edad, monto;
    char sexo;
};
char sexos[2] = { 'M', 'F' };

int nextInt(int, int);
void generarDatos(Persona*, int);
void mostrarDatos(Persona*, int);
void ordenar(Persona*, int);
void intercambiar(Persona*, Persona*);

int main() {
    srand(time(NULL));
    int n;
    Persona* personas;

    // Validar el tamaño del arreglo
    do {
        cout << "Ingresar el numero de personas: ";
        cin >> n;
    } while (n <= 0 || n > 200);

    personas = new Persona[n];
    
    generarDatos(personas, n);
    mostrarDatos(personas, n);
    ordenar(personas, n);

    cout << "\nDatos ordenados\n";
    mostrarDatos(personas, n);

    delete[] personas;

    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarDatos(Persona* personas, int n) {
    for (int i = 0; i < n; ++i) {
        personas[i].edad = nextInt(15, 50);
        personas[i].monto = nextInt(25, 500);
        personas[i].sexo = sexos[nextInt(0,1)];
    }
}

void mostrarDatos(Persona* personas, int n) {
    cout << left << setw(8) << "Persona";
    cout << setw(5) << "Edad";
    cout << setw(6) << "Monto";
    cout << setw(5) << "Sexo" << endl;

    for (int i = 0; i < n; ++i) {
        cout << left << setw(8) << i + 1;
        cout << setw(5) << personas[i].edad;
        cout << setw(6) << personas[i].monto;
        cout << setw(5) << personas[i].sexo << endl;
    }
}

void intercambiar(Persona& x, Persona& y) {
    Persona tmp = x;
    x = y;
    y = tmp;
}

bool hacerIntercambio(Persona actual, Persona nueva) {
    // Ordenamiento sea de forma ascendente por sexo
    if (nueva.sexo < actual.sexo) {
        return true;
    }
    return false;
}

void ordenar(Persona* personas, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ( hacerIntercambio(personas[i], personas[j])) {
                intercambiar(personas[i], personas[j]);
            }
        }
    }
}