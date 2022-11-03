#include <iostream>
using namespace std;

int ingresarTamanio();
int nextInt(int, int);
void generarValores(int*, int);
void imprimirValores(int*, int);
void intercambiar(int&, int&);
void ordenar(int*, int);
int* modificarArregloUsandoAuxiliar(int*, int&, int);

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

    arreglo = modificarArregloUsandoAuxiliar(arreglo, n, R);
    cout << "\nArreglo modificado" << endl;
    cout << "------------------" << endl;
    imprimirValores(arreglo, n);

    delete[]arreglo;
    return 0;
}

int ingresarTamanio() {
    int n;
    do {
        cout << "Ingrese el tama�o del arreglo: ";
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
        cout <<"Arreglo["<<i<<"] = " << arreglo[i] << endl;
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

int contarDiferentes(int* arreglo, int n) {
    // Inicializamos el contador como 1 ya que asumimos que
    // hemos contado el primer n�mero
    int contador{1};
    for (int i = 1; i < n; ++i) {
        // Empezamos a iterar desde 1 ya que asumimos que hemos
        // contado el primer n�mero

        // Verificamos si el actual es igual al elemento anterior
        // Como el iterador inicia desde i=1 entonces no hay
        // accesos inv�lidos, si "i" inicia en 0 entonces no podr�a 
        // hacer esto ya que acceder�a a arreglo[-1] que es inv�lido
        if (arreglo[i] != arreglo[i - 1]) {
            // Si son diferentes aumentamos contador
            contador++;
        }
    }
    return contador;
}

int* modificarArregloUsandoAuxiliar(int* arreglo, int &n, int R) {
    // Contamos cantidad de elementos diferentes
    int elementos_diferentes = contarDiferentes(arreglo, n);

    // El arreglo auxiliar tendr� R veces el n�mero de elementos diferentes
    int m = elementos_diferentes * R;
    int* auxiliar = new int[m];


    // Copiamos R veces el primer elemento
    // k es el �ndice del arreglo auxiliar
    int k = 0;
    while (k < R) {
        auxiliar[k] = arreglo[0];
        k++;
    }

    for (int i = 1; i < n; ++i) {
        // Empezamos desde 1 debido a que ya copiamos
        // el elemento de posici�n 0
        if (arreglo[i] != arreglo[i - 1]) {
            // Si son diferentes copiamos R veces el
            // valor actual, recordar que el �ndice
            // del auxiliar es k
            for (int j = 0; j < R; ++j) {
                auxiliar[k] = arreglo[i];
                k++;
            }
        }
    }
    // Actualizamos el tama�o del arreglo
    n = m;

    // Limpiamos el arreglo original
    delete[] arreglo;
    arreglo = nullptr;

    // Retornamos auxiliar
    return auxiliar;
}