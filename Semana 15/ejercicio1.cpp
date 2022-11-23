#include <iostream>
#include <iomanip>
using namespace std;

int nextInt(int, int);
void generarListarParalelos(int*, char*, char*, int);
void intercambiar(int&, int&);
void intercambiar(char&, char&);
bool actualizar(int, int);
void listadoOrdenado(int*, char*, char*, int);
double porcentajeGripeTos(char*, char*, int);

int main() {
    srand(time(0));
    
    int n;
    int* pesos;
    char* gripe, * tos;

    do {
        cout << "Ingrese Número de alumnos: ";
        cin >> n;
    } while ( n <= 0 || n > 20);

    pesos = new int[n];
    gripe = new char[n];
    tos = new char[n];

    // 1. Implementar la función GenerayLista_Paralelos, que permita generar de forma aleatoria e 
    //    imprimir los datos de los N alumnos que se almacenan en los vectores paralelos Vgripe, Vtos y
    //    Vpesos.
    generarListarParalelos(pesos, gripe, tos, n);
    
    // 2. Implementar la función Porcentaje_gripe_tos, que determine el porcentaje de alumnos que
    //    tuvieron gripe y tos simultáneamente sobre el total de alumnos.
    double porcentaje = porcentajeGripeTos(gripe, tos, n);
    cout << "\nPorcentaje de alumnos(as) que tienen gripe y tos: "<<porcentaje<<"%"<<endl;

    // 3. TODO: Implementar la función Promedio_pesos, que determine el promedio del peso de los alumnos
    //    que han tenido alguna enfermedad.
    
    // 4. Implementar la función Listado_ordenado, que imprima el listado de los alumnos ordenado
    //    descendentemente por el peso.
    listadoOrdenado(pesos, gripe, tos, n);

    delete[] pesos;
    delete[] gripe;
    delete[] tos;
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarListarParalelos(int* pesos, char* gripe, char* tos, int n) {
    char respuesta[2] = { 'S', 'N' };
    // Generación de datos
    for (int i = 0; i < n; ++i) {
        pesos[i] = nextInt(30, 60);
        gripe[i] = respuesta[rand() % 2];
        tos[i] = respuesta[nextInt(0, 1)];
    }

    // Listar los datos
    for (int i = 0; i < n; ++i) {
        cout << "\nAlumno " << i + 1 << endl;
        cout << "Gripe: " << gripe[i] << endl;
        cout << "Tos: " << tos[i] << endl;
        cout << "Peso: " << pesos[i] << endl;
    }
}

double porcentajeGripeTos(char* gripe, char* tos, int n) {
    /*
    Entrada:
    n = 3
    gripe = ['S', 'N', 'S']
    tos = ['S', 'N', 'N']

    Salida:
    porcentaje=33.33%
    */
    int contador{0};
    double porcentaje;
    for (int i = 0; i < n; ++i) {
        if (gripe[i] == 'S' && tos[i] == 'S') {
            contador++;
        }
    }
    porcentaje = contador * 100.0 / n;
    return porcentaje;
}

void intercambiar(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void intercambiar(char &x, char &y) {
    char tmp = x;
    x = y;
    y = tmp;
}

bool actualizar(int peso_actual, int peso_nuevo) {
    // Ordenar de forma descendente por el peso
    // peso_actual = 23, peso_nuevo = 45
    if (peso_nuevo > peso_actual) return true;
    return false;
}

void listadoOrdenado(int* pesos, char*gripe, char*tos, int n) {
    // Ordenar
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (actualizar(pesos[i], pesos[j])) {
                intercambiar(pesos[i], pesos[j]);
                intercambiar(gripe[i], gripe[j]);
                intercambiar(tos[i], tos[j]);
            }
        }
    }

    // Mostrar datos ordenados
    cout << "\n";
    cout << left << setw(6)<<"Pesos";
    cout << setw(6) << "Gripe";
    cout << setw(4) << "Tos"<<endl;
    for (int i = 0; i < n; ++i) {
        cout << left << setw(6) << pesos[i];
        cout << setw(6) << gripe[i];
        cout << setw(4) << tos[i] << endl;
    }
}