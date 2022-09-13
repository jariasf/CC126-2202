#include <iostream>
using namespace std;

bool esTipoProductoValido(char tipo_producto) {
    return tipo_producto == 'O' || 
           tipo_producto == 'J' || 
           tipo_producto == 'U';
}

bool esTipoCelularValido(char tipo_celular) {
    return tipo_celular == 'i' ||
           tipo_celular == 'A';
}

bool esCantidadValida(int cantidad) {
    return cantidad > 0;
}

char ingresarTipoProducto() {
    char tipo_producto;
    cout << "Tipo de producto (O: Oficina; J: Juegos; U: Utilidades): ";
    cin >> tipo_producto;
    return tipo_producto;
}

char ingresarTipoCelular() {
    char tipo_celular;
    cout << "Tipo de celular (i: iPhone; A: Android): ";
    cin >> tipo_celular;
    return tipo_celular;
}

int ingresarCantidad() {
    int cantidad;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    return cantidad;
}

double obtenerPrecio(char tipo_producto, char tipo_celular, int cantidad){
    double precio = 0;
    if (tipo_producto == 'O') {
        switch (tipo_celular) {
            case 'i': precio = 50.60; break;
            case 'A': precio = 20.30; break;
        }
    }
    else if (tipo_producto == 'J') {
        switch (tipo_celular) {
            case 'i': precio = 90.80; break;
            case 'A': precio = 40.50; break;
        }
    }
    else {
        switch (tipo_celular) {
            case 'i': precio = 60.50; break;
            case 'A': precio = 30.60; break;
        }
    }
    return precio * cantidad;
}

bool ingresoDatosValido(char &tipo_producto, char &tipo_celular, int &cantidad) {
    tipo_producto = ingresarTipoProducto();
    if (esTipoProductoValido(tipo_producto)) {
        tipo_celular = ingresarTipoCelular();
        if (esTipoCelularValido(tipo_celular)) {
            cantidad = ingresarCantidad();
            if (!esCantidadValida(cantidad)) {
                cout << "Cantidad invalida\n";
                return false;
            }
        }
        else {
            cout << "Tipo de celular invalido\n";
            return false;
        }
    }
    else {
        cout << "Tipo de producto invalido\n";
        return false;
    }
    return true;
}

int main() {
    char tipo_producto, tipo_celular;
    int cantidad;
    double precio;
    
    if (ingresoDatosValido(tipo_producto, tipo_celular, cantidad)) {
        precio = obtenerPrecio(tipo_producto, tipo_celular, cantidad);
        cout << "El precio es S/." << precio << endl;
    }
    return 0;
}