#include <iostream>
#include <cstdlib>
using namespace std;

void generarAleatorios() {
    int aleatorio;
    for (int i = 0; i < 5; ++i) {
        aleatorio = rand(); // Genera entre 0 y RAND_MAX
        cout << "Numero aleatorio " << i + 1 << ": " << aleatorio << endl;
    }
}

void generarEntreCeroyCien(){
    int aleatorio;
    for (int i = 0; i < 5; ++i) {
        aleatorio = rand() % 101;
        cout << "Numero aleatorio entre 0 y 100 inclusive: " << aleatorio << endl;
    }

    /*
    Operador de modulo
    45 % 10 = 5
    49 % 10 = 9
    41 % 10 = 1
    num % 10 -> [0,9]
    num % 40 -> [0,39]
    num % m -> [0,m-1]
    rand() % 101 -> [0,100]
    */
}

int nextInt(int low, int high) {
    // Genera números aleatoros entre low y high inclusive [low,high]
    return low + rand() % (high - low + 1);
}

void generarEntreCincoyDiez() {
    int aleatorio;
    for (int i = 0; i < 5; ++i) {
        aleatorio = nextInt(5, 10);
        cout << "Numero generado entre 5 y 10 inclusive: " << aleatorio << endl;
    }
}

char nextLetter(char low, char high) {
    return low + rand() % (high - low + 1);
}

void generarLetras() {
    char aleatorio;
    for (int i = 0; i < 5; ++i) {
        aleatorio = nextLetter('A', 'Z');
        cout << "Caracter generado entre A y Z inclusive: " << aleatorio << endl;
    }
}

int main() {
    srand(time(NULL));
    generarAleatorios();
    generarEntreCeroyCien();
    generarEntreCincoyDiez();
    generarLetras();
    return 0;
}