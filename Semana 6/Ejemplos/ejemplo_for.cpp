#include <iostream>
using namespace std;

void contadorUsandoWhile() {
    cout << "Contador usando while\n";
    int contador = 1;
    while (contador <= 10) {
        cout << contador << endl;
        contador++;
    }
}

void contadorUsandoFor() {
    cout << "Contador usando for\n";
    for(int contador = 1; contador <= 10; contador++) {
        cout << contador << endl;
    }
}

void contadorInfinitoUsandoFor() {
    cout << "Contador infinito usando for\n";
    for (int contador = 1; ; contador++) {
        cout << contador << endl;
        if (contador == 20) {
            break;
        }
    }
}

void contadorDecrecienteUsandoFor() {
    cout << "Contador en orden descendente usando for\n";
    for (int contador = 10; contador >= 1 ; --contador) {
        cout << contador << endl;
    }
}

void contadorUsandoForPunteros() {
    cout << "Contador usando for con punteros\n";
    int* contador = new int;
    for( *contador = 1; *contador <= 10; (*contador)++ ) {
        cout << *contador << endl;
    }
    delete contador;
}

int main() {
    contadorUsandoWhile();
    cout << endl;
    contadorUsandoFor();
    cout << endl;
    contadorInfinitoUsandoFor();
    cout << endl;
    contadorDecrecienteUsandoFor();
    cout << endl;
    contadorUsandoForPunteros();
    return 0;
}