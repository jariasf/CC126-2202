#include <iostream>
using namespace std;

int main() {
    int* num1 = new int, * num2 = new int;
    int* mayor = new int;

    cout << "Ingrese el numero 1: ";
    cin >> *num1;
    cout << "Ingrese el numero 2: ";
    cin >> *num2;

    *mayor = (*num1 > *num2) ? *num1 : *num2;

    /*
    if (*num1 > *num2) {
        *mayor = *num1;
    }
    else {
        *mayor = *num2;
    }*/

    cout << "El mayor entre " << *num1 << " y " << *num2 << " es " << *mayor << endl;

    delete num1;
    delete num2;
    delete mayor;
    return 0;
}