#include <iostream>
using namespace std;
int main(){
    /*Comentario en bloque
    - Declare una variable llamada numero_entero y asígnele el valor de 30
    - Declare una variable llamada numero_flotante y asígnele el valor de 30.78
    - Declare una variable llamada numero_double y asígnele el valor de 45.1234
    - Declare una variable llamada booleano y asígnele el valor de verdadero
    - Declare una variable llamada caracter y asígnele el valor de u
    */
    int* numero_entero = new int{30};
    //int* numero_entero = new int;
    //*numero_entero = 30;

    float* numero_flotante = new float{30.78};
    //float* numero_flotante;
    //*numero_flotante = 30.78;

    double* numero_double = new double{45.1234};

    bool* boolean = new bool;
    *boolean = true;

    char* caracter = new char;
    *caracter = 'u';

    // Mostrar los valores
    cout << "Numero entero: " << *numero_entero << endl;
    cout << "Numero flotante: " << *numero_flotante << endl;
    cout << "Numero double: " << *numero_double << endl;
    cout << "Booleano: " << *boolean << endl;
    cout << "Caracter: " << *caracter << endl;
  
    // Liberar memoria
    delete numero_entero;
    delete numero_flotante;
    delete numero_double;
    delete boolean;
    delete caracter;
    return 0;
}