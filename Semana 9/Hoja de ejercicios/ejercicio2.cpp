#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n);
void determinarFactorial();
void calcularExponencial();
double exponencial(int, double);

int main() {
    int opcion;
    do {
        cout << "MENU PRINCIPAL" << endl;
        cout << "1) Determinar el factorial de un número" << endl;
        cout << "2) Calcular el valor de ea" << endl;
        cout << "3) Imprime rombo" << endl;
        cout << "4) Fin" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: determinarFactorial(); break;
            case 2: calcularExponencial(); break;
            case 3: break;
            case 4: break;
            default:
                cout << "La opcion es invalida" << endl;
        }
        cout << endl;

    } while (opcion != 4);

    return 0;
}

int factorial(int n) {
    int prod = 1;
    for (int i = 1; i <= n; ++i) {
        prod *= i;
    }
    return prod;
}

void determinarFactorial() {
    // -Si la opción elegida fuese 1, debe leer un número positivo y 
    // determinar y mostrar el factorial del número
    int numero;
    do {
        cout << "Ingrese un numero: ";
        cin >> numero;
    } while (numero <= 0);

    int resultado = factorial(numero);
    cout << "El factorial de " << numero << " es: " << resultado << endl;
}

double exponencial(int k, double a) {
    double suma{0}, termino, numerador, denominador;

    for (int i = 0; i <= k; ++i) {
        numerador = pow(a, i);
        denominador = factorial(i);
        termino = numerador / denominador;
        suma += termino;
    }
    return suma;
}

void calcularExponencial() {
    double a;
    int k;
    do {
        cout << "Ingrese el valor de k: ";
        cin >> k;
    } while ( k <= 0 || k > 20);

    do {
        cout << "Ingrese el valor de a: ";
        cin >> a;
    } while (a <= 0);

    double resultado = exponencial(k, a);
    cout << "El valor del exponencial es: " << resultado << endl;
}