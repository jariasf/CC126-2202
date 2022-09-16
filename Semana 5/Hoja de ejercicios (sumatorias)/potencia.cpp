#include <iostream>
using namespace std;

/*
i = 1, pot = 1*5 = 5
i = 2, pot = 5*5 = 25
i = 3, pot = 25*5 = 125
i = 4, pot = 125*5 = 625
*/
void elevar5ALaCuarta() {
    int pot = 1;
    int i = 1;
    while (i <= 4) {
        pot = pot * 5;
        cout << "5^"<<i<<" = " << pot << endl;
        ++i;
    }
}

int potencia(int base, int exponente) {
    int pot, i;
    pot = 1;
    i = 1;

    while (i <= exponente) {
        pot *= base;
        //cout << base << "^" << i << " = " << pot << endl;
        ++i;
    }
    return pot;
}


int main() {
    int base, exponente;

    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;

    cout<<"\n" << base << "^" << exponente << " = " << potencia(base, exponente) << endl;

    //elevar5ALaCuarta();
    return 0;
}