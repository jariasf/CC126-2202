#include <iostream>
using namespace std;

int main() {
    
    int* k = new int, *monedas_cinco = new int, *monedas_dos = new int, *monedas_uno = new int;

    cout << "Ingrese la cantidad K: ";
    cin >> *k;

    *monedas_cinco = *k / 5; // 37 / 5 = 7
    *k = *k % 5;             // 37 % 5 = 2
    *monedas_dos = *k / 2;   // 2 / 2 = 1
    *k = *k % 2;             // 2 % 2 = 0
    *monedas_uno = *k;

    cout << "Monedas de 5: " << *monedas_cinco << "\n";
    cout << "Monedas de 2: " << *monedas_dos << "\n";
    cout << "Monedas de 1: " << *monedas_uno << "\n";

    delete k;
    delete monedas_cinco;
    delete monedas_dos;
    delete monedas_uno;       
    return 0;
}