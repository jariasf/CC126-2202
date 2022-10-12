#include <iostream>
using namespace std;

void intercambiarPorReferencia(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void intercambiar(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int x{7}, y{5};
    //Salida esperada: x=5; y=7;

    int* ptr_x = &x;
    int* ptr_y = &y;
    intercambiar(ptr_x, ptr_y);

    //intercambiar(&x, &y);
    cout << "Valores luego del intercambio: x="<<x<<", y="<<y<< endl;
    return 0;
}