#include <iostream>
using namespace std;

int main() {
    int *numero = new int, *original = new int;
    int* n1 = new int, *n2 = new int, * n3 = new int;
    int* reordenado = new int;
    bool* es_divisible = new bool;
    bool* no_es_divisible = new bool;
    char* divisible = new char;
    bool* esta_entre33y90 = new bool;
    bool* es_menor33 = new bool;
    bool* es_mayor90 = new bool;
    double* resultado = new double;

    // Entrada de datos
    cout << "Ingrese un numero de 9 dígitos: ";
    cin >> *numero;
    *original = *numero;

    // 1. Particionar el numero
    // ABCDEFGHI -> ABCDE FGHI
    // Obtener en número 3 (FGHI)
    *n3 = *numero % 10000; // FGHI
    *numero = *numero / 10000; // ABCDE
    // ABCDE -> AB CDE
    *n2 = *numero % 1000; // CDE
    *n1 = *numero / 1000; // AB

    // 2. Reordenar el numero -> n3=FGHI n2=CDE n1=AB
    // FGHICDEAB
    *reordenado = *n3 * 100000 + *n2 * 100 + *n1;

    // 3. Verificar divisibilidad: Verificar si el número reordenado es 
    // divisible por el número original.
    *es_divisible = (*reordenado % *original == 0);
    *no_es_divisible = !(*es_divisible);
    // C1 * R1 + C2 * R2
    *divisible = *es_divisible * 'S' + *no_es_divisible * 'N';

    // 4. Operaciones con expresión lógicas
    *esta_entre33y90 = (*n1 >= 33 && *n1 <= 90);
    *es_menor33 = (*n1 < 33);
    *es_mayor90 = (*n1 > 90);

    *resultado = *esta_entre33y90 * (*n1 + *n2) / 2.0 +
                 *es_menor33 * (*n2 + *n3) +
                 *es_mayor90 * ((double)*n3 / *n1);

    // 5. Mostrar resultados
    cout << "El numero original es: " << *original << endl;
    cout << "El numero reordenado es: " << *reordenado << endl;
    cout << "Son divisibles? (N: No; S: Si): " << *divisible << endl;
    cout << "El resultado de la operacion es: " << *resultado << endl;

    delete numero;
    delete n1;
    delete n2;
    delete n3;
    delete original;
    delete reordenado;
    delete es_divisible;
    delete no_es_divisible;
    delete divisible;
    delete esta_entre33y90;
    delete es_menor33;
    delete es_mayor90;
    delete resultado;
    return 0;
}