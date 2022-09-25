#include <iostream>
using namespace std;

double* calcularPromedio(int*);
void calcularPromedioFinal(int*);
void calcularPromedioFinal2(int*);

int main() {
    int* num_alumnos = new int;
    cout << "Ingrese el numero de alumnos: ";
    cin >> *num_alumnos;
    calcularPromedioFinal2(num_alumnos);
    delete num_alumnos;
    return 0;
}

double* calcularPromedio(int* alumno_actual) {
    double* EF = new double, * EP = new double, * TF = new double;
    double* promedio = new double;
    cout << "Ingrese el EF del Alumno " << *alumno_actual << ": ";
    cin >> *EF;
    cout << "Ingrese el EP del Alumno " << *alumno_actual << ": ";
    cin >> *EP;
    cout << "Ingrese el TF del Alumno " << *alumno_actual << ": ";
    cin >> *TF;
    *promedio = 0.55 * *EF + 0.3 * *EP + 0.15 * *TF;

    delete EF;
    delete EP;
    delete TF;
    return promedio;
}

void calcularPromedioFinal(int* num_alumnos) {
    int* alumno_actual = new int{ 1 };
    double* promedio;
    while (*alumno_actual <= *num_alumnos) {
        cout << "\n";
        promedio = calcularPromedio(alumno_actual);
        cout << "Su promedio final es: " << *promedio << endl;
        (*alumno_actual)++;
        delete promedio;
    }
    delete alumno_actual;
}

void calcularPromedioFinal2(int* num_alumnos) {
    int* alumno_actual = new int{ 1 };
    double* promedio = new double;
    double* EF = new double, * EP = new double, * TF = new double;
    while (*alumno_actual <= *num_alumnos) {
        cout << "\n";
        cout << "Ingrese el EF del Alumno " << *alumno_actual << ": ";
        cin >> *EF;
        cout << "Ingrese el EP del Alumno " << *alumno_actual << ": ";
        cin >> *EP;
        cout << "Ingrese el TF del Alumno " << *alumno_actual << ": ";
        cin >> *TF;
        *promedio = 0.55 * *EF + 0.3 * *EP + 0.15 * *TF;
        cout << "Su promedio final es: " << *promedio << endl;
        (*alumno_actual)++;
    }
    delete alumno_actual;
    delete EF;
    delete EP;
    delete TF;
    delete promedio;
}