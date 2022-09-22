#include <iostream>
#include <conio.h>
using namespace std;
#define BARRA_ESPACIADORA 32
#define FLECHA_IZQUIERDA 75
#define FLECHA_DERECHA 77

int main() {

    while (1) {
        if (_kbhit()) {
            char tecla = _getch();
            if (tecla == BARRA_ESPACIADORA) {
                cout << "Barra espaciadora\n";
            }
            else if (tecla == FLECHA_IZQUIERDA) {
                cout << "Flecha izquierda\n";
            }
            else if (tecla == FLECHA_DERECHA) {
                cout << "Flecha derecha\n";
            }
            else
                cout << "otro caracter\n"; 
        }
        //else
        //    cout << "No se presiona tecla\n";
    }

    //char tecla = _getch();
    //tecla = _getch();
    //cout << tecla << " " << (int)tecla << endl;

    system("pause");
    return 0;
}