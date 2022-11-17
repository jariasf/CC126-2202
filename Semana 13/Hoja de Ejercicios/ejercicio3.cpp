#include <iostream>
using namespace std;

void generarInformacion(int**, int, int);
void registrarInformacion(int**, int, int);
void mostrarInformacion(int**, int, int);
int calcularTotalDeVentasPorAgencia(int**, int, int, int);
double calcularPromedioDeVentasPorMes(int**, int, int, int);
int obtenerAgenciaDeMayoresVentasPorMes(int**, int, int, int);

/*
             Agencia 1   Agencia 2  Agencia 3.... Agencia 5
Enero                                  
Febrero                                  
Marzo                                  
...
Diciembre                              

*/
//string meses[12] = { "Enero", "Febrero", ... };

int main() {
    srand(time(NULL));
    int filas{12}, columnas{5};
    int** matriz = new int* [filas];
    for (int i = 0; i < filas; ++i)
        matriz[i] = new int[columnas];

    //a) Registrar la información de las ventas por mes de cada una de las agencias.
    generarInformacion(matriz, filas, columnas);
    //registrarInformacion(matriz, filas, columnas);
         
    //b) Mostrar en pantalla el resumen de ventas de cada agencia.
    mostrarInformacion(matriz, filas, columnas);

    //c) Mostrar cuál fue el total de ventas en el año de la Agencia 3.
    int total_ventas = calcularTotalDeVentasPorAgencia(matriz, filas, columnas, 2);
    cout << "\nTotal de ventas de la agencia 3: " << total_ventas << endl;

    //d) Mostrar el promedio de ventas en el mes de diciembre.
    double promedio = calcularPromedioDeVentasPorMes(matriz, filas, columnas, 11);
    cout << "\nPromedio de ventas en el mes de diciembre: " << promedio << endl;

    //e) Mostrar el número de la agencia que tuvo mayores ventas en el mes de mayo.
    int agencia = obtenerAgenciaDeMayoresVentasPorMes(matriz, filas, columnas, 4);
    cout << "\nEl numero de la agencia que tuvo mayores ventas en el mes de mayo: " << agencia + 1 << endl;

    //f) TODO: Indicar en qué mes se registraron las menores ventas del año, considerando todas las agencias. 


    for (int i = 0; i < filas; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

void generarInformacion(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            matriz[i][j] = rand() % 101;
        }
    }
}

void registrarInformacion(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << "Ingrese informacion de la venta del mes " << i + 1 << " para agencia " << j + 1 << ": ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarInformacion(int** matriz, int filas, int columnas) {
    for (int j = 0; j < columnas; ++j) {
        cout << "Agencia " << j << "\n";
        for (int i = 0; i < filas; ++i) {
            cout << "Ventas del mes " << i << ": " << matriz[i][j] << endl;
        }
    }
}

int calcularTotalDeVentasPorAgencia(int** matriz, int filas, int columnas, int agencia) {  
    /*
                 Agencia 1   Agencia 2  Agencia 3.... Agencia 5
    Enero                                  12
    Febrero                                5
    Marzo                                  20
    ...
    Diciembre                              100

    */
    int total_ventas{0};
    for (int i = 0; i < filas; ++i) {
        total_ventas += matriz[i][agencia];
    }
    return total_ventas;
}

double calcularPromedioDeVentasPorMes(int** matriz, int filas, int columnas, int mes) {
    /*
                 Agencia 1   Agencia 2  Agencia 3.... Agencia 5
    Enero                                  
    Febrero                                
    Marzo                                  
    ...
    Diciembre       23          67         100     ...    2

    */
    double promedio = 0;
    for (int j = 0; j < columnas; ++j) {
        promedio += matriz[mes][j];
    }
    promedio /= columnas;
    return promedio;
}

int obtenerAgenciaDeMayoresVentasPorMes(int** matriz, int filas, int columnas, int mes) {
    /*
                     0           1         2         3          4 
                 Agencia 1   Agencia 2  Agencia 3  Agenda 4  Agencia 5
  0  Enero
  1  Febrero
  2  Marzo
  3  ...
  4  Mayo            12          6         99        80         20  
     ...
  11 Diciembre 

    */
    int mayor = matriz[mes][0], mayor_agencia = 0;
    for (int j = 1; j < columnas; ++j) {
        if (matriz[mes][j] > mayor) {
            mayor = matriz[mes][j];
            mayor_agencia = j;
        }
    }
    return mayor_agencia;
}