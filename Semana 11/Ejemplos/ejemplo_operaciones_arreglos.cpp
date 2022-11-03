#include <iostream>
using namespace std;

void listarElementos(int*, int);
int* insertarAlFinal(int*, int&, int);
int* insertarAlInicio(int*, int&, int);
int* insertarEnPosicion(int*, int&, int, int);
int* eliminarEnPosicion(int*, int&, int);
void mostrarMenu();
int ingresarPosicion(int);
void ordenar(int*, int);

int main() {
    int opcion, elemento, posicion;
    int* arreglo{nullptr};
    int n{0};
    do {
        mostrarMenu();
        cout << "Ingrese opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: listarElementos(arreglo, n); break;
            case 2: cout << "\nIngrese un elemento: "; cin >> elemento;
                    arreglo = insertarAlFinal(arreglo, n, elemento);
                    break;
            case 3: 
                    if (arreglo != nullptr) {
                        posicion = ingresarPosicion(n);
                        arreglo = eliminarEnPosicion(arreglo, n, posicion);
                    }
                    else {
                        cout << "Arreglo vacio" << endl;
                    }
                    break;
            case 4: cout << "\nIngrese un elemento: "; cin >> elemento;
                    arreglo = insertarAlInicio(arreglo, n, elemento);
                    break;
            case 5:
                    // TODO: Modificar en posición
                    break;
            case 6:
                    // TODO: Insertar en posición
                    break;
            case 7:
                    ordenar(arreglo, n);
                    break;
            case 8: break;
            default:
                    cout << "Opcion invalida. Ingrese nuevamente..."<<endl;
        }

        system("pause");
        system("cls");

    } while (opcion!=8);

    if (arreglo != nullptr) {
        delete[] arreglo;
        arreglo = nullptr;
    }

    return 0;
}

void mostrarMenu() {
    cout << "\t\tMENU" << endl;
    cout << "1. LISTAR ELEMENTOS\n";
    cout << "2. AGREGAR AL FINAL\n";
    cout << "3. ELIMINAR EN POSICION\n";
    cout << "4. AGREGAR AL INICIO\n";
    cout << "5. MODIFICAR EN POSICION\n";
    cout << "6. INSERTAR EN POSICION\n";
    cout << "7. ORDENAR DE MAYOR A MENOR\n";
    cout << "8. FIN\n";
}

int ingresarPosicion(int n) {
    int posicion;
    do {
        cout << "\nIngrese posicion: ";
        cin >> posicion;
        if (posicion < 0 || posicion >= n) {
            cout << "Posicion invalida, ingrese nuevamente...\n";
        }
    } while (posicion < 0 || posicion >= n);
    return posicion;
}

void listarElementos(int* arreglo, int n) {
    if (arreglo == nullptr) {
        cout << "Arreglo vacio" << endl;
        return;
    }
    cout << "Lista de elementos\n";
    cout << "------------------\n";
    for (int i = 0; i < n; ++i) {
        cout << "Arreglo[" << i << "] = " << arreglo[i] << endl;
    }
}

int* insertarAlFinal(int* arreglo, int& n, int elemento) {
    // Crear arreglo auxiliar de tamaño n+1
    int* auxiliar = new int[n + 1];

    // Copiamos valores del arreglo original en el auxiliar
    for (int i = 0; i < n; ++i) {
        auxiliar[i] = arreglo[i];
    }

    // Aumentar el valor de la variable tamaño (paso por referencia)
    n++;

    // Insertar el nuevo elemento
    auxiliar[n - 1] = elemento;

    // Liberar memoria de arreglo
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

int* insertarAlInicio(int* arreglo, int& n, int elemento) {
    // Crear arreglo auxiliar de tamaño n+1
    int* auxiliar = new int[n + 1];

    // Copiamos valores del arreglo original en el auxiliar
    for (int i = 0; i < n; ++i) {
        auxiliar[i + 1] = arreglo[i];
    }

    // Insertar el nuevo elemento
    auxiliar[0] = elemento;

    // Aumentar el valor de la variable tamaño (paso por referencia)
    n++;

    // Liberar memoria de arreglo
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

int* insertarEnPosicion(int* arreglo, int& n, int posicion, int elemento) {
    //TODO: Implementar método que permita insertar un nuevo elemento
    //      en una determinada posición
    return nullptr;
}

int* eliminarEnPosicion(int* arreglo, int& n, int posicion) {
    // Asumiendo que la posición ingresada es válida

    // Inicializar arreglo vacío
    int* auxiliar = nullptr;
    if (n > 1) {
        // Crear arreglo auxiliar de tamaño n-1
        auxiliar = new int[n - 1];
    }

    // Copiamos valores del arreglo original en el auxiliar
    for (int i = 0, k = 0; i < n; ++i) {
        if (i != posicion) {
            auxiliar[k] = arreglo[i];
            k++;
        }
    }

    // Disminuir el valor de la variable tamaño (paso por referencia)
    n--;

    // Liberar memoria de arreglo
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

void ordenar(int *arreglo, int n) {
    // TODO: Ordenar de mayor a menor
}