#include <iostream>
#include <climits> // Usado para mostrar los limites de cada tipo de dato
using namespace std;

int main() {
    ///////////////////////////
    // Tipo de dato Entero
    //////////////////////////
    cout << "Tipo de dato entero\n\n";
    int numero1;
    int numero2;
    int n1, n2;
    short numero_pequenho;
    long long numero_grande;
    cout <<"Rango de valores de short: " << SHRT_MIN << " " << SHRT_MAX << endl;
    cout << "Rango de valores de entero: " << INT_MIN << " " << INT_MAX << endl;
    cout << "Rango de valores de long long: " << LLONG_MIN << " " << LLONG_MAX << endl;

    numero1 = 123;
    numero2 = 456;
    numero_pequenho = 1234567; // Desbordamiento
   
    cout << "El numero 1 es " << numero1 << endl;
    cout << "El numero 2 es " << numero2 << endl;
    cout << "El numero pequenho es " << numero_pequenho << endl;

    // Inicializacion
    int variable{3455};
    //int variable = 3455;
    cout << "Variable inicializada " << variable << endl;

    ////////////////////////////////////
    // Tipo de dato booleano
    ////////////////////////////////////
    cout << "\n\nTipo de dato boolean\n\n";
    bool variable_booleana{false};
    cout << "Variable booleana " << variable_booleana << endl;

    ////////////////////////////////////
    // Tipo de dato de numero reales
    ////////////////////////////////////
    cout << "\n\nTipo de dato float o double\n\n";
    float numero_real{3.146};
    double numero_real_mas_preciso{3.675756};
    long double numero_mucho_mas_preciso{ 3.456547547 };
    cout << "Variable float " << numero_real << endl;
    cout << "Variable double " << numero_real_mas_preciso << endl;
    cout << "Variable long double " << numero_mucho_mas_preciso << endl;

    ////////////////////////////////////
    // Tipo de dato caracter
    ////////////////////////////////////
    cout << "\n\nTipo de dato char\n\n";
    char letra_mayuscula{'A'};
    char letra_minuscula{'a'};
    char operador{'+'};
    cout << "Variable caracter " << letra_mayuscula << " " << letra_minuscula << " " << operador << endl;
    cout << "Rango de valores de char: " << CHAR_MIN << " " << CHAR_MAX << endl;

    ///////////////////////////////////
    // Conversion de tipos
    //////////////////////////////////
    cout << "\n\nConversion de tipos\n\n";
    float real{ 31.15 };
    int entero = (int)real; // Conversion explicita
    int implicita = real;   // Conversion implicita;
    cout << "Conversion de flotante a entero: " << real << " -> " << implicita << endl;

    char letra{ 'A' };
    int codigo_letra = (int)letra;
    cout << "Conversion de caracter a entero: " << letra << " -> " << codigo_letra << endl;
    cout << "Conversion de caracter a entero: " << 'B' << " -> " << (int)'B' << endl;

    int codigo{ 65 };
    char caracter_apartir_codigo = codigo;
    cout << "Conversion de entero a caracter: " << codigo << " -> " << caracter_apartir_codigo << endl;
    return 0;
}