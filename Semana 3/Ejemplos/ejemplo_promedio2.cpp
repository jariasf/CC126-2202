#include <iostream>; 
using namespace std;

float calcularPromedio(int numero1, int numero2, int numero3);

int main()
{
    int numero1, numero2, numero3;
    float resultado;

    cout << "Ingrese el primer numero: ";
    cin >> numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> numero2;
    cout << "Ingrese el tercer numero: ";
    cin >> numero3;

    resultado = calcularPromedio(numero1, numero2, numero3);
    cout << "El promedio es: " << resultado << endl;
    return 0;
}

// * /  de izquierda a derecha
// 34 / 5 * 1.0
// 6 * 1.0 = 6.0

// 1.0 * 34 / 5
// 34.0/5 = 6....
float calcularPromedio(int numero1, int numero2, int numero3) {
    float promedio = 1.0 * (numero1 + numero2 + numero3) / 3;
    return promedio;
}
