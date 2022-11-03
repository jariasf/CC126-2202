#include <iostream>
using namespace std;

int ingresarTamanio();
int nextInt(int, int);
void generarValores(int*, int);
void imprimirValores(int*, int);
void intercambiar(int&, int&);
void ordenar(int*, int);
int* modificarArregloUsandoInsertarEliminar(int*, int&, int);
int* eliminarEnPosicion(int*, int&, int);
int* insertarEnPosicion(int*, int&, int, int);

int main() {
    srand(time(NULL));
    int n, R;
    int* arreglo;

    n = ingresarTamanio();
    arreglo = new int[n];

    generarValores(arreglo, n);
    cout << "\nArreglo original" << endl;
    cout << "----------------" << endl;
    imprimirValores(arreglo, n);

    ordenar(arreglo, n);
    cout << "\nArreglo ordenado" << endl;
    cout << "----------------" << endl;
    imprimirValores(arreglo, n);

    cout << endl;
    do {
        cout << "Ingrese el valor de R: ";
        cin >> R;
    } while (R < 2 || R > 5);

    arreglo = modificarArregloUsandoInsertarEliminar(arreglo, n, R);
    cout << "\nArreglo modificado" << endl;
    cout << "------------------" << endl;
    imprimirValores(arreglo, n);

    delete[]arreglo;
    return 0;
}

int ingresarTamanio() {
    int n;
    do {
        cout << "Ingrese el tamaño del arreglo: ";
        cin >> n;
    } while (n < 10 || n > 30);
    return n;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarValores(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        arreglo[i] = nextInt(1, 50);
    }
}

void imprimirValores(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Arreglo[" << i << "] = " << arreglo[i] << endl;
    }
}

void intercambiar(int& x, int& y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void ordenar(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arreglo[i] > arreglo[j]) {
                intercambiar(arreglo[i], arreglo[j]);
            }
        }
    }
}

int* eliminarEnPosicion(int* arreglo, int& n, int posicion) {
    int* auxiliar = nullptr;
    if (n > 1) {
        auxiliar = new int[n - 1];
        for (int i = 0, k = 0; i < n; ++i) {
            if (i != posicion) {
                auxiliar[k++] = arreglo[i];
            }
        }
        n--;
    }
    delete[] arreglo;
    arreglo = nullptr;

    return auxiliar;
}

int* insertarEnPosicion(int* arreglo, int& n, int posicion, int elemento) {
    int* auxiliar = new int[n + 1];

    for (int i = 0; i < posicion; ++i) {
        auxiliar[i] = arreglo[i];
    }
    auxiliar[posicion] = elemento;
    for (int i = posicion; i < n ; ++i) {
        auxiliar[i + 1] = arreglo[i];
    }

    delete[] arreglo;
    arreglo = nullptr;

    n++;
    return auxiliar;
}

int* modificarArregloUsandoInsertarEliminar(int* arreglo, int& n, int R) {
    /*
        Modificar arreglo usando insertar y eliminar, esta es una forma
        de solucionar el problema, es posible usar dos bucles, uno para
        iterar el arreglo y otro para realizar el conteo. Está segunda 
        forma se deja como ejercicios. A continuación se muestra usando 
        un bucle para iterar y contar a medida que se itera
    */
    int contador{1}; // Contador de frecuencias
    for(int i = 1; i < n ; ++i){
        // Iteramos desde 1 debido a que ya hemos contado elemento inicial
        if (arreglo[i] != arreglo[i - 1]) {
            // Si son diferentes verificamos la
            // frecuencia del número anterior
            if (contador < R) {
                // Si tiene menos frecuencia que R, insertamos
                // elementos al arreglo usando el número anterior
                for (int j = contador; j < R; ++j) {
                    arreglo = insertarEnPosicion(arreglo, n, i, arreglo[i - 1]);
                    // Aumentamos indice de arreglo ya que hemos insertado
                    // un nuevo elemento. Por ejemplo actualmente tenemos:
                    //  arreglo = [1,1,1,2,2,3], contador = 3, R = 5
                    //                   |
                    //                   i
                    // Luego de insertar tendremos
                    //  arreglo = [1,1,1,1,2,2,3], contador = 3, R = 5
                    //                   |
                    //                   i
                    // Como se puede ver el índice "i" que antes estaba en la posición
                    // del primer 2, ahora apunta al último 1, por lo tanto para que 
                    // vuelva a estar en la posición del primer 2 lo aumentamos
                    i++;

                    // Luego de esto tendremos
                    //  arreglo = [1,1,1,1,2,2,3], contador = 3, R = 5
                    //                     |
                    //                     i
                    // El proceso se repite hasta haber insertado todos
                }
            }else {
                // Si tiene mas frecuencia que R, eliminamos
                // elementos al arreglo usando la posición del anterior
                // Ejemplo de caso:
                //    arreglo = [1,1,1,1,1,1,1,2,2,3], contador=7, R=5
                //                             |
                //                             i
                // Actualmente estamos ubicados en la posición del primer 2
                // tenemos que eliminar elementos de la posición anterior
                for (int j = R; j < contador; ++j) {
                    arreglo = eliminarEnPosicion(arreglo, n, i - 1);
                }
                // Luego de ejecutar tendremos
                //    arreglo = [1,1,1,1,1,2,2,3], contador=7, R=5
                //                         |
                //                         i
                // En este caso no es necesario cambiar i
            }
            // Inicializamos contador como 1, indicando que
            // hemos contado el elemento actual arreglo[i]
            contador = 1;
        }
        else {
            contador++;
        }
    }

    // Al final tenemos que repetir el proceso para el último
    // número ya que contador puede ser menor o mayor a R
    // Ejemplo:
    //   arreglo = [5,5,5,5,5]  , contador = 5, R = 3
    //                        |
    //                        i
    // Este caso no se incluye dentro del bucle
    if (contador < R) {
        for (int j = contador; j < R; ++j) {
            arreglo = insertarEnPosicion(arreglo, n, n - 1, arreglo[n - 1]);
        }
    }
    else {
        for (int j = R; j < contador; ++j) {
            arreglo = eliminarEnPosicion(arreglo, n, n - 1);
        }
    }

    // Retornamos arreglo modificado, no limpiamos
    // memoria ya que no hemos creado auxiliar
    return arreglo;
}