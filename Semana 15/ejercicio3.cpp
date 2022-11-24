#include <iostream>
#include <iomanip>
using namespace std;

void generarInformacion(int** , int , int );
void mostrarInformacion(int*, int**, int, int);
void determinarCodigosDeMayorCantidadMinutos(int*, int**, int, int);
void determinarMontosPorExceso(int*, int**, int, int);


int main() {
    srand(time(0));

    //1. Generar un arreglo de 30 elementos que contenga los códigos de los vendedores. Se sabe que los códigos
    //de los vendedores empezarán en el valor 201.
    int filas{30};
    int* codigos = new int[filas];
    for (int i = 0; i < filas; ++i)
        codigos[i] = 201 + i;
    
    //2. Generar una matriz de 30 x 3, que contenga de forma aleatoria la información de los minutos de llamadas
    //a fijo y celulares así como el número de mensajes de texto de cada vendedor.
    int columnas{3};
    int** informacion = new int* [filas];
    for (int i = 0; i < filas; ++i)
        informacion[i] = new int[columnas];

    generarInformacion(informacion, filas, columnas);
    mostrarInformacion(codigos, informacion, filas, columnas);
    
    //3. Determinar el código o códigos de los vendedores que tienen la mayor cantidad de minutos de llamadas
    // a celulares.
    determinarCodigosDeMayorCantidadMinutos(codigos, informacion, filas, columnas);

    //4. Determinar por cada vendedor el monto total a pagar por el exceso en el consumo. El monto se calcula
    //como: sumexcesos * tarifas.
    determinarMontosPorExceso(codigos, informacion, filas, columnas);
    
    //5. TODO: Determinar el tiempo promedio de llamadas a fijo, el tiempo promedio de llamadas a celular y promedio
    //de mensajes enviados.


    delete[] codigos;
    for (int i = 0; i < filas; ++i)
        delete[] informacion[i];
    delete[] informacion;


    return 0;
}

void generarInformacion(int** informacion, int filas, int columnas) {
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            informacion[i][j] = rand() % 101;
        }
    }
}

void mostrarInformacion(int* codigos, int** informacion, int filas, int columnas) {
    cout <<endl<< left << setw(7) << "Codigo";
    cout << setw(10) << "Min. Fijo";
    cout << setw(13) << "Min. Celular";
    cout << setw(11) << "Msg. Texto"<<endl;
    for (int i = 0; i < filas; ++i) {
        cout << left << setw(7) << codigos[i];
        cout << setw(10) << informacion[i][0];
        cout << setw(13) << informacion[i][1];
        cout << setw(11) << informacion[i][2] << endl;
    }
}

void determinarCodigosDeMayorCantidadMinutos(int* codigos, int** informacion, int filas, int columnas) {
    /*
    columna 0 -> minutos a fijo  -- informacion[i][0]
    columna 1 -> minutos a celular -- informacion[i][1]
    columna 2 -> mensajes de texto -- informacion[i][2]

    codigos fijo celular texto
    201            23
    202            50
    ..
    230             1

    */
    int columna = 1;
    int mayor = informacion[0][columna];
    for (int i = 1; i < filas; ++i) {
        if (informacion[i][columna] > mayor) {
            mayor = informacion[i][columna];
        }
    }

    cout << "\nCodigo de vendedores con mayor cantidad de minutos de llamadas a celular:\n";
    for (int i = 0; i < filas; ++i) {
        if (informacion[i][columna] == mayor) {
            cout<<"Vendedor " << codigos[i] << endl;
        }
    }
}

void determinarMontosPorExceso(int* codigos, int** informacion, int filas, int columnas) {
    /*
    
    Plan: 
    - 20 minutos de llamadas a teléfono fijo
    - 40 minutos a celulares 
    - 20 mensajes de texto

    Costo por exceso:
    - 0.35 soles por minuto para teléfono fijo
    - 0.45 soles por minuto para celular
    - 0.20 soles por mensaje de texto.

     0          0      1      2
    codigos   fijo   celular texto
    201        15      23     31     -> exceso en texto 31 - 20 = 11 * 0.20 = 
    202        50      30     20     -> exceso en fijo: 50 - 20 = 30 * 0.35 = 
    ..
    230        1       50     10     

    */
    double monto;

    cout << "\nMontos a pagar por exceso de consumo\n";
    for (int i = 0; i < filas; ++i) {
        monto = 0;
        if (informacion[i][0] > 20) {
            monto += (informacion[i][0] - 20) * 0.35;
        }
        if (informacion[i][1] > 40) {
            monto += (informacion[i][1] - 40) * 0.45;
        }
        if (informacion[i][2] > 20) {
            monto += (informacion[i][2] - 20) * 0.20;
        }
        cout << "Vendedor " << codigos[i] << ": " << monto << endl;
    }
}