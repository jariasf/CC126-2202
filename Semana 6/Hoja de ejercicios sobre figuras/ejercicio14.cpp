#include <iostream>
using namespace std;

int ingresarNumero() {
    int n;
    do {
        cout << "Ingrese un numero: ";
        cin >> n;
    } while (n < 1 || n > 5);
    return n;
}

void imprimirFigura(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 2 * i - 1; ++j) {
            cout << j;
        }
        cout << endl;
    }
}

int main() {

    int n = ingresarNumero();
    imprimirFigura(n);

    return 0;
}