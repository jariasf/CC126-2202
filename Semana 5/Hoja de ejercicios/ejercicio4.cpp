#include<iostream>
using namespace std;

int ingresarNumero();

int main() {
    int numero, contador{0}, mayor, menor, positivos{0}, negativos{0};
    double suma{0}, promedio;

    numero = ingresarNumero();
    mayor = numero;
    menor = numero;

    while (numero != 0) {
        // 1. Contar los numeros ingresados
        contador++;

        // 2. Encontrar numero mayor
        mayor = (numero > mayor) ? numero: mayor;
        /*if (numero > mayor) {
            mayor = numero;
        }*/

        // 3. Encontrar numero menor
        menor = (numero < menor)? numero: menor;
        /*if (numero < menor) {
            menor = numero;
        }*/

        // 4. Contar positivos
        positivos += (numero > 0)?1:0;
        /*if (numero > 0)
            positivos++;*/

        // 5. Contar negativos
        if (numero < 0)
            negativos++;

        // 6.1 Calcular la suma
        suma += numero;

        // Ingreso del variable principal
        numero = ingresarNumero();
    }

    // 6.2 Calcular el promedio
    if (contador > 0) {
        promedio = suma / contador;
    }
    else {
        promedio = 0.;
    }

    cout << "Números Leídos = " << contador << endl;
    cout << "Número Mayor = " << mayor << endl;
    cout << "Número Menor = " << menor << endl;
    cout << "Números Positivos = " << positivos << endl;
    cout << "Números Negativos = " << negativos << endl;
    cout << "Promedio = " << promedio << endl;

    return 0;
}

int ingresarNumero() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    return numero;
}