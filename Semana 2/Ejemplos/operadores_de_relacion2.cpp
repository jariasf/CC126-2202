#include <iostream>
using namespace std;

int main() {
    int* numero1 = new int;
    int* numero2 = new int;
    bool* son_iguales = new bool;
    bool* es_mayor = new bool;
    bool* es_menor = new bool;
    bool* son_diferentes = new bool;

    cout << "Ingrese el primer numero: ";
    cin >> *numero1;
    cout << "Ingrese el segundo numero: ";
    cin >> *numero2;

    // Operadores de relacion: <, >, ==, >=, <=, !=
    *son_iguales = (*numero1 == *numero2);
    *es_mayor = (*numero1 > *numero2);
    *es_menor = (*numero1 < *numero2);
    *son_diferentes = (*numero1 != *numero2);

    cout << "El numero " << *numero1 << " es mayor al numero " << *numero2 << "? " << *es_mayor << endl;
    cout << "El numero " << *numero1 << " es menor al numero " << *numero2 << "? " << *es_menor << endl;
    cout << "Los numeros son iguales? " << *son_iguales << endl;
    cout << "Los numeros son diferentes? " << *son_diferentes << endl;

    // Operadores logicos: expr && expr2, expr1 || expr2, !expr

    // Liberamos memoria
    delete numero1;
    delete numero2;
    delete son_iguales;
    return 0;
}