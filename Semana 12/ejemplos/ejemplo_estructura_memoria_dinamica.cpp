#include <iostream>
using namespace std;

struct Persona {
    int edad;
    char sexo;
    double salario;
};

void mostrarPersona(Persona*);

int main() {
    srand(time(NULL));

    // Declaración de variable del tipo entero en memoria dinámica
    int* entero = new int;
    *entero = 5;
    //cout << *entero << endl;
    delete entero;

    // Declaración de variable del tipo Persona en memoria dinámica
    Persona* persona = new Persona;

    // Acceso usando operador *
    (*persona).edad = 5;
    (*persona).sexo = 'F';
    (*persona).salario = 50.5;
    cout << "Persona" << endl;
    mostrarPersona(persona);

    // Acceso usando operador ->
    persona->edad = 12;
    persona->sexo = 'M';
    persona->salario = 30.5;
    cout << "\nPersona" << endl;
    mostrarPersona(persona);

    delete persona;
    return 0;
}

void mostrarPersona(Persona* persona) {
    /*
        La entrada es una variable del tipo estructura,
        no es un arreglo.
    */
    cout << "Edad: " << persona->edad << endl;
    cout << "Sexo: " << persona->sexo << endl;
    cout << "Salario: " << persona->salario << endl;
}