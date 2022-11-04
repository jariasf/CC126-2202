#include <iostream>
#include <iomanip>
using namespace std;

struct Persona {
    int edad;
    char sexo;
    double salario;
};

char sexos[2] = { 'F', 'M' };

void mostrarPersona(Persona);
int nextInt(int, int);
double nextDouble(double, double);
void generarValoresAleatorios(Persona*, int);
void mostrarPersonas(Persona*, int);

int main() {
    srand(time(NULL));

    // Declaración de arreglo de enteros en memoria dinámica
    int n{5};
    int* numeros = new int[n];
    //numeros[0] <- int
    delete[] numeros;

    // Declaración de arreglo de Personas en memoria dinámica
    Persona* personas = new Persona[n];
    //personas[0] <- Persona
    
    // Generar valores aleatorios
    generarValoresAleatorios(personas, n);

    // Mostrar valores de arreglo
    mostrarPersonas(personas, n);

    /*
    // Otra forma de mostrar arreglo de estructuras
    for (int i = 0; i < n; ++i) {
        cout << "\nPersona " << i + 1<<endl;
        mostrarPersona(personas[i]);
    }*/

    delete[] personas;

    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

double nextDouble(double min, double max) {
    return min + rand() * (max - min) / RAND_MAX;
}

void mostrarPersona(Persona persona) {
    cout << "Edad: " << persona.edad << endl;
    cout << "Sexo: " << persona.sexo << endl;
    cout << "Salario: " << persona.salario << endl;
}

void generarValoresAleatorios(Persona* personas, int n) {
    for (int i = 0; i < n; ++i) {
        personas[i].edad = nextInt(18, 50);
        personas[i].sexo = sexos[nextInt(0, 1)];
        personas[i].salario = nextDouble(800, 2000);
    }
}

void mostrarPersonas(Persona* personas, int n) {
    cout << left << setw(9) << "Personas";
    cout << left << setw(5) << "Edad";
    cout << left << setw(5) << "Sexo";
    cout << left << setw(8) << "Salario" << endl;
    for (int i = 0; i < n; ++i) {
        cout << left << setw(9) << i + 1;
        cout << left << setw(5) << personas[i].edad;
        cout << left << setw(5) << personas[i].sexo;
        cout << left << setw(8) << personas[i].salario << endl;
    }
}