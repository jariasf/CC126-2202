#include <iostream>
using namespace std;

int main() {

    int* numero1 = new int{ 12 };
    int* numero2 = new int{ 5 };
    int* suma = new int;

    *suma = *numero1 + *numero2;
    cout << "Suma de dos numeros " << *suma << endl;

    // Operacion de division
    double* division = new double;
    *division = *numero1 / *numero2; // pseint: trunc(numero1/numero2)
    cout << "Division de dos numeros enteros " << *division << endl;

    *division = *numero1 / (double) (*numero2); // pseint: numero1/numero2
    cout << "Division de dos numeros enteros " << *division << endl;

    // Operador de modulo - residuo (solo enteros)
    int* modulo = new int;
    *modulo = *numero1 % *numero2; // pseint: numero1 mod numero2
    cout << "Residuo de dividir dos numeros enteros " << *modulo << endl;

    // (Opcional)
    delete numero1;
    delete numero2;
    delete division;
    delete modulo;
    return 0;
}