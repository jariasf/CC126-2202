#include <iostream>
using namespace std;

int nextInt(int, int);
void generarValores(int*, int);
void imprimirArreglo(int*, int);
void intercambiar(int&, int&);
void ordenar(int*, int);
void imprimirFrecuencia(int*, int);
int* eliminarEnPosicion(int*, int&, int);
int* eliminarRepetidosUsandoFor(int*, int&);
int* eliminarRepetidosUsandoWhile(int*, int&);

int main() {
    srand(time(NULL));
    int n{30};
    int* arreglo = new int[n];

    generarValores(arreglo, n);
    cout << "\nArreglo original" << endl;
    cout << "----------------" << endl;
    imprimirArreglo(arreglo, n);

    ordenar(arreglo, n);
    cout << "\nArreglo ordenado" << endl;
    cout << "----------------" << endl;
    imprimirArreglo(arreglo, n);

    cout << "\nFrecuencias" << endl;
    cout << "-----------" << endl;
    imprimirFrecuencia(arreglo, n);

    arreglo = eliminarRepetidosUsandoWhile(arreglo, n);
    cout << "\nArreglo sin elementos repetidos" << endl;
    cout << "-------------------------------" << endl;
    imprimirArreglo(arreglo, n);

    delete[]arreglo;
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarValores(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        arreglo[i] = nextInt(1, 100);
    }
}

void imprimirArreglo(int* arreglo, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
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

void imprimirFrecuencia(int* arreglo, int n) {
    // Inicializamos el contador como 1 ya que asumimos que
    // hemos contado el primer número
    int contador{1};

    for (int i = 1; i < n - 1; ++i) {
        // Empezamos a iterar desde 1 ya que asumimos que hemos
        // contado el primer número
        
        // Verificamos si el actual es igual al elemento anterior
        // Como el iterador inicia desde i=1 entonces no hay
        // accesos inválidos, si "i" inicia en 0 entonces no podría 
        // hacer esto ya que accedería a arreglo[-1] que es inválido
        if (arreglo[i] != arreglo[i - 1]) {
            // Si no son iguales mostramos la frecuencia
            cout << arreglo[i - 1] << " se repite " << contador << " ";
            cout << (contador == 1 ? "vez" : "veces") << endl;
            contador = 1;
        }
        else {
            // Si son iguales aumentamos el contador
            contador++;
        }
    }
    cout << arreglo[n - 1] << " se repite " << contador << " ";
    cout << (contador == 1 ? "vez" : "veces") << endl;
}


int* eliminarEnPosicion(int* arreglo, int& n, int posicion) {
    int* auxiliar = nullptr;
    if (n > 1) {
        auxiliar = new int[n - 1];
        for (int i = 0, k = 0 ; i < n; ++i) {
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

/*
    Eliminar valores repetidos
    --------------------------
    Dado que el arreglo ingresado está ordenado entonces se pueden
    eliminar repetidos verificando los valores en posiciones
    adyacentes. Por ejemplo:

    arreglo = [1,1,2,2,2,3,4,4,4], n = 9
               |
               i
    Empezamos desde i = 0 y preguntamos si el elemento en esa
    posición (arreglo[0]) es el mismo que el elemento en la siguiente
    posición (arreglo[1]).

    Caso 1: Si son el mismo entonces tenemos que eliminar uno de ellos
    Caso 2: Si no son iguales avanzamos a la siguiente posición

    En este caso son iguales entonces eliminamos cualquiera de los dos
    para eso podemos usar el método eliminar aprendido en clase. En
    este caso eliminaremos la posición i

        arreglo = eliminarEnPosicion(arreglo, n, i);

    Luego de ello al arreglo quedaría de la siguiente forma:

    arreglo = [1,2,2,2,3,4,4,4], n = 9
               |
               i
    No aumentamos el valor de i debido a que hemos eliminado
    un elemento y por defecto ya estamos apuntando al
    siguiente elemento

    Ahora nuevamente preguntas (arreglo[0] == arreglo[1])
    En este caso no son iguales entonces recién avanza i

    arreglo = [1,2,2,2,3,4,4,4], n = 8
                 |
                 i
    El algoritmo continua hasta llegar al final.

    Importante: Solo iteramos hasta n-1 debido a que
    el último elemento del arreglo no tiene siguiente,
    es decir, al hacer la verificación
    if(arreglo[i] == arreglo[i + 1]) no existe arreglo[i+1]
    cuando i sea la última posición. Ejemplo:

    arreglo = [1,2]  n = 2
                 |
                 i
    Si i está en la última posición no existe arreglo[i+1]
    por eso no es iteramos hasta el final.
*/
int* eliminarRepetidosUsandoFor(int* arreglo, int& n) {
    for (int i = 0; i < n - 1;) {
        if (arreglo[i] == arreglo[i + 1]) {
            // Cuando sean repetidos no aumentamos i
            // ya que vamos a eliminar elementos
            arreglo = eliminarEnPosicion(arreglo, n, i);
        }else {
            // Solo aumentamos i cuando no sean repetidos
            i++;
        }
    }
    return arreglo;
}

int* eliminarRepetidosUsandoWhile(int* arreglo, int& n) {
    int i{0};
    while (i < n - 1) {
        if (arreglo[i] == arreglo[i + 1]) {
            // Cuando sean repetidos no aumentamos i
            // ya que vamos a eliminar elementos
            arreglo = eliminarEnPosicion(arreglo, n, i);
        }else {
            // Solo aumentamos i cuando no sean repetidos
            i++;
        }
    }
    return arreglo;
}