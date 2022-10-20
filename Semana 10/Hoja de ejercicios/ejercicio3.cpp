#include <iostream>
#include <cstdlib>
using namespace std;

int ingresarNumeroPersonas();
int nextInt(int, int);
void generarEdades(int*, int);
void mostrarEdades(int*, int);
void encontrarMenorEdad(int*, int);
int encontrarPosicionMenorEdad(int*, int);
int contarPersonasEntre30y50(int*, int);
double calcularPromedioEdades(int*, int);

int main() {
    srand(time(NULL));
    int n, *edades, posicion_menor, entre30y50;
    double promedio;

    // Un listado de los N edades generados al azar (N tendrá un valor máximo de 100) 
    n = ingresarNumeroPersonas();
    edades = new int[n];
    generarEdades(edades, n);
    mostrarEdades(edades, n);

    // La menor edad y su posición en el Arreglo
    posicion_menor = encontrarPosicionMenorEdad(edades, n);
    cout << "\nMenor edad: " << edades[posicion_menor] << endl;
    cout << "La persona con menor edad es " << posicion_menor + 1 << endl;

    // El número de personas que tienen entre 30 y 50 años
    entre30y50 = contarPersonasEntre30y50(edades, n);
    cout << "\nEl numero de personas que tienen entre 30 y 50 años es " << entre30y50 << endl;
    
    // El promedio de edades
    promedio = calcularPromedioEdades(edades, n);
    cout << "\nEl promedio de edades es: " << promedio << endl;

    // TODO: Se desea que el programa solicite una edad a buscar 
    // en el arreglo y muestre si se encontró o no en el arreglo

    delete[] edades;
    return 0;
}

int ingresarNumeroPersonas() {
    int n;
    do {
        cout << "Ingrese el numero de personas: ";
        cin >> n;
    } while (n <= 0 || n > 100);
    return n;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarEdades(int *edades, int n) {
    for (int i = 0; i < n; ++i) {
        edades[i] = nextInt(10, 100);
    }
}

void mostrarEdades(int *edades, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Edad de la persona " << i + 1 << ": " << edades[i] << endl;
    }
}

void encontrarMenorEdad(int *edades, int n) {
    int menor = edades[0], indice_menor{0};
    //  0   1   2  3   4
    // [12, 45, 2, 13, 1]
    for (int i = 1; i < n; ++i) {
        if (edades[i] < menor) {
            menor = edades[i];
            indice_menor = i;
        }
    }
    cout << "Menor edad: " << menor << endl;
    cout << "Persona de menor edad: " << indice_menor + 1<< endl;
}

int encontrarPosicionMenorEdad(int *edades, int n) {
    int indice_menor{0};
    for (int i = 1; i < n; ++i) {
        if (edades[i] < edades[indice_menor]) {
            indice_menor = i;
        }
    }
    return indice_menor;
}

int contarPersonasEntre30y50(int *edades, int n) {
    int contador{0};
    for (int i = 0; i < n; ++i) {
        if (edades[i] >= 30 && edades[i] <= 50) {
            contador++;
        }
    }
    return contador;
}

double calcularPromedioEdades(int *edades, int n) {
    double promedio{0};
    for (int i = 0; i < n; ++i) {
        promedio += edades[i];
    }
    promedio /= n;
    return promedio;
}