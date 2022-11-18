#include <iostream>
using namespace std;

int main() {
    
    // Variables
    int entero{5};
    /*
       entero_dinamico = 2341
                         |
                         5     
    */
    int* entero_dinamico = new int{5};

    // Arreglos
    // Arreglo estático
    int arreglo[5]{ 1,2,3,4,5 };

    // Arreglo dinámico
    /*
       arreglo_dinamico = 2341
                          | 
                          |1|2|3|4|5|
    */
    int* arreglo_dinamico = new int[5]{ 1,2,3,4,5 };

    /*
       arreglo_punteros = |2456|2460|2464|2468|2472|
                             |   |    |     |   |
                             1   2    3     4   5
    */
    int** arreglo_punteros = new int* [5];
    for (int i = 0; i < 5; ++i) {
        arreglo_punteros[i] = new int;
    }

    /*
       matriz = |2456|  2460  | 2464 |  2468  |  2472|
                 |      |       |       |        |
                 |1|2|  |3|4|   |9|1|   |4|1|    |5|9|0|
    */
    int** matriz = new int* [5];
    for (int i = 0; i < 5; ++i) {
        matriz[i] = new int[2];
    }


    // Liberar memoria de entero en heap
    delete entero_dinamico;

    // Liberar memoria de arreglo dinámico
    delete[] arreglo_dinamico;

    // Liberar memoria de arreglo de punteros
    for (int i = 0; i < 5; ++i) {
        delete arreglo_punteros[i];
    }
    delete[] arreglo_punteros;

    // Liberar memoria de matriz
    for (int i = 0; i < 5; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
    return 0;
}