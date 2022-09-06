#include <iostream>
using namespace std;

//1. Invertir número: Función que invierte un número entero de 4 dígitos.
int invertirNumero(int numero) {
    int d1, d2, d3, d4, invertido;
    // 1234 -> 4321
    // 1. Obtener digitos del numero
    d4 = numero % 10; // 4
    numero /= 10;     // 123
    d3 = numero % 10; // 3
    numero /= 10;     // 12
    d2 = numero % 10; // 2
    d1 = numero / 10; // 1
    invertido = d4 * 1000 + d3 * 100 + d2 * 10 + d1;
    return invertido;
}

//2. Verificar palíndromo: Función que verifica si un número entero de 4 dígitos es 
// palindromo. Un número palíndromo es aquel que se lee igual de izquierda a derecha que
// de derecha a izquierda. Debe hacer uso de la función invertir número.
/*
bool verificarPalindromo(int numero) {
    // 1551 -> invertir(1551) = 1551
    // 1231 -> invertir(1231) = 1321
    int num_invertido = invertirNumero(numero);
    return (num_invertido == numero);
}*/

char verificarPalindromo(int numero){
    int num_invertido = invertirNumero(numero);
    bool es_palindromo = (num_invertido == numero);
    bool no_es_palindromo = !es_palindromo;
    char palindromo = es_palindromo * 'V' + no_es_palindromo * 'F';
    return palindromo;
}


//3. Verificar si es divisible por 5: Función que verifica si un número es divisible por 5
bool esDivisiblePor5(int numero) {
    return numero % 5 == 0;
}

//4. Codificar número: Función que codifica un número de 4 dígitos en base a lo siguiente:
// Si el número es divisible por 5 retorna el carácter formado por los dos primeros dígitos,
// de otro modo retorna el carácter formado por los dos últimos dígitos. Debe hacer uso de
// la función que verifica si un número es divisible por 5.
char codificarNumero(int numero) {
    bool es_divisible, no_es_divisible;
    char resultado;
    int n1, n2;
    n2 = numero % 100; // 2 ultimos digitos
    n1 = numero / 100; // 2 primeros digitos
    // Expresiones logicas
    es_divisible = esDivisiblePor5(numero);
    no_es_divisible = !es_divisible;
    // Resultado
    resultado = es_divisible * (char)n1 + no_es_divisible * (char)n2;
    return resultado;
}

int main() {
    int numero;
    
    cout << "Ingrese un numero de 4 digitos: ";
    cin >> numero;

    cout << "Numero invertido: " << invertirNumero(numero) << endl;
    cout << "¿Es palíndromo? " << verificarPalindromo(numero) << endl;
    cout << "¿Es divisible por 5? " << esDivisiblePor5(numero) << endl;
    cout << "Numero codificado: " << codificarNumero(numero) << endl;

    return 0;
}