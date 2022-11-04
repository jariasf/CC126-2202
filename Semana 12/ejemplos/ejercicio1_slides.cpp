#include <iostream>
using namespace std;

struct Imagen{
    char tipo;
    int ancho, alto;
    double tamanio;
};
void mostrarMenu();
void insertarImagen(Imagen*, int&);

int main() {
    int capacidad{100}, n{0};
    char tipo;
    Imagen* imagenes = new Imagen[capacidad];
    int opcion;
    do {
        mostrarMenu();
        cout << "Ingrese opcion: ";
        cin >>opcion;
        switch (opcion) {
            case 1: 
                    if (n < capacidad) {
                        insertarImagen(imagenes, n);
                    }else {
                        cout << "Memoria insuficiente. Ya no se pueden insertar mas imagenes..." << endl;
                    }
                    break;
            case 2:
                    // TODO: Implementar método mostrarImagenes
                    break;
            case 3: 
                    cout << "Ingrese tipo a buscar: ";
                    cin >> tipo;
                    // TODO: Implementar método buscarPorTipo
                    break;
            case 4: break;
            default:
                cout << "Opción inválida" << endl;

        }
        system("pause>0");
        system("cls");
    } while (opcion != 4);

    delete[] imagenes;

    return 0;
}

void mostrarMenu() {
    cout << "Menu" << endl;
    cout << "1. Insertar imagen" << endl;
    cout << "2. Mostrar imagenes" << endl;
    cout << "3. Buscar por tipo" << endl;
    cout << "4. Fin" << endl;
}

void insertarImagen(Imagen* imagenes, int& n) {
    cout << "\nAgregar imagen" << endl;
    cout << "-------------" << endl;
    cout << "Ingrese el tipo: ";
    cin >> imagenes[n].tipo;
    cout << "Ingrese el ancho: ";
    cin >> imagenes[n].ancho;
    cout << "Ingrese el alto: ";
    cin >> imagenes[n].alto;
    cout << "Ingrese el tamanio: ";
    cin >> imagenes[n].tamanio;

    // Aumentamos el numero de elementos del arreglo
    n++;
}