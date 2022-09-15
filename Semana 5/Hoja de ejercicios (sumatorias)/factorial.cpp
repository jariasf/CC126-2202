#include <iostream>
using namespace std;

/*
Hallar el factorial el un numero
Entrada
5
Salida
1*2*3*4*5 = 120

Entrada 
3
Salida
1*2*3 = 6
*/

/*

prod = 1;
i = 1, prod = 1 * 1 = 1
i = 2, prod = 1 * 2 = 2
i = 3, prod = 2 * 3 = 6
i = 4, prod = 6 * 4 = 24
i = 5, prod = 24 * 5 = 120
*/
int factorial(int n) {
    int prod = 1;
    int i = 1;
    while (i <= n) {
        prod = prod * i;
        //cout << i << " " << prod << endl;
        ++i;
    }
    return prod;
}

int main() {
    int n;
    cout << "Ingrese el valor de N: ";
    cin >> n;
    cout << "El factorial de " << n << " es " << factorial(n) << endl;
    return 0;
}