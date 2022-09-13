#include <iostream>
using namespace std;

bool esTipoProductoValido(char *tipo_producto) {
    return *tipo_producto == 'O' ||
           *tipo_producto == 'J' ||
           *tipo_producto == 'U';
}

bool esTipoCelularValido(char *tipo_celular) {
    return *tipo_celular == 'i' ||
           *tipo_celular == 'A';
}

bool esCantidadValida(int *cantidad) {
    return *cantidad > 0;
}

char* ingresarTipoProducto() {
    char *tipo_producto = new char;
    cout << "Tipo de producto (O: Oficina; J: Juegos; U: Utilidades): ";
    cin >> *tipo_producto;
    return tipo_producto;
}

char* ingresarTipoCelular() {
    char *tipo_celular = new char;
    cout << "Tipo de celular (i: iPhone; A: Android): ";
    cin >> *tipo_celular;
    return tipo_celular;
}

int* ingresarCantidad() {
    int* cantidad = new int;
    cout << "Ingrese la cantidad: ";
    cin >> *cantidad;
    return cantidad;
}

double* obtenerPrecio(char *tipo_producto, char *tipo_celular, int *cantidad) {
    double* precio = new double{0.};
    if (*tipo_producto == 'O') {
        switch (*tipo_celular) {
            case 'i': *precio = 50.60; break;
            case 'A': *precio = 20.30; break;
        }
    }
    else if (*tipo_producto == 'J') {
        switch (*tipo_celular) {
            case 'i': *precio = 90.80; break;
            case 'A': *precio = 40.50; break;
        }
    }
    else {
        switch (*tipo_celular) {
            case 'i': *precio = 60.50; break;
            case 'A': *precio = 30.60; break;
        }
    }
    *precio = *precio * *cantidad;
    return precio;
}

int main() {
    char *tipo_producto, *tipo_celular;
    int* cantidad;
    double* precio;

    tipo_producto = ingresarTipoProducto();
    if (esTipoProductoValido(tipo_producto)) {
        tipo_celular = ingresarTipoCelular();
        if (esTipoCelularValido(tipo_celular)) {
            cantidad = ingresarCantidad();
            if (esCantidadValida(cantidad)) {
                precio = obtenerPrecio(tipo_producto, tipo_celular, cantidad);
                cout << "El precio es S/." << *precio << endl;
                delete precio;
            }
            else {
                cout << "Cantidad invalida\n";
            }
            delete cantidad;
        }
        else {
            cout << "Tipo de celular invalido\n";
        }
        delete tipo_celular;
    }
    else {
        cout << "Tipo de producto invalido\n";
    }
    delete tipo_producto;
    return 0;
}