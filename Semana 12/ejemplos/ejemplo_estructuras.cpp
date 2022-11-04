#include <iostream>
using namespace std;

struct Persona {
    int edad{18};
    char sexo{'M'};
    double salario{10.0};
};

void declararSinNombre();
void mostrarPersona(Persona);
int nextInt(int, int);
double nextDouble(double, double);

int main() {
    srand(time(NULL));

    Persona persona;
    
    // Inicialización 1
    persona.edad = 23;
    persona.sexo = 'F';
    persona.salario = 12.5;
    cout << "\nPersona 1" << endl;
    mostrarPersona(persona);

    // Inicialización 2
    Persona persona2 = {45, 'M', 34.5};
    cout << "\nPersona 2" << endl;
    mostrarPersona(persona2);

    // Inicialización 3
    // c++20
    // Persona persona3 = {.edad = 50, .sexo = 'F', .salario=45.6};
    // mostrarPersona(persona3);

    // Inicialización 4 (por defecto)
    Persona persona3;
    cout << "\nPersona 3" << endl;
    mostrarPersona(persona3);

    // Inicialización 5 (por teclado)
    cout << "\nPersona 4" << endl;
    Persona persona4;
    cout << "Ingrese la edad: ";
    cin >> persona4.edad;
    cout << "Ingrese el sexo: ";
    cin >> persona4.sexo;
    cout << "Ingrese el salario: ";
    cin >> persona4.salario;
    mostrarPersona(persona4);

    // Inicialización 6 (aleatorio)
    //                 0    1   
    char sexos[2] = { 'F', 'M' };
    Persona persona5;
    persona5.edad = nextInt(18, 50);
    persona5.sexo = sexos[nextInt(0,1)]; // M o F
    persona5.salario = nextDouble(500, 1500);
    cout << "\nPersona 5" << endl;
    mostrarPersona(persona5);

    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

double nextDouble(double min, double max) {
    return min + rand() * (max - min) / RAND_MAX;
}

void declararSinNombre() {
    struct {
        int edad;
        char sexo;
        double salario;
    }persona, persona2, persona3, persoan4;
}

void mostrarPersona(Persona persona) {
    cout << "Edad: " << persona.edad << endl;
    cout << "Sexo: " << persona.sexo << endl;
    cout << "Salario: " << persona.salario << endl;
}