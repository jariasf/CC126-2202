#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "MENU DE OPCIONES\n";
    cout << "****************\n";
    cout << "1. CONVERTIR A MAYUSCULA\n";
    cout << "2. CONVERTIR A MINUSCULA\n";
    cout << "3. CARACTER SIGUIENTE\n";
    cout << "4. CARACTER ANTERIOR\n";
}

short ingresarOpcion() {
    short opcion;
    cout << "\nELIJA UNA OPCION: ";
    cin >> opcion;
    return opcion;
}

char ingresarLetra() {
    char letra;
    cout << "\nIngrese una letra: ";
    cin >> letra;
    return letra;
}

char convertirAMayuscula(char letra) {
    /*
    letra esta minuscula 'c'
    'a' = 97		'A' = 65
    'b' = 98		'B' = 66
    'c' = 99		'C' = 67

    'c' - 'a' = 99 - 97 = 2
     2 + 'A' = 2 + 65 = 67 -> 'C'
    */
    //Asumiendo que la entrada esta en minuscula
    //return letra - 'a' + 'A';
    return toupper(letra);
}

char convertirAMinuscula(char letra) {
    //Asumiendo que la entrada esta en mayuscula
    //return letra - 'A' + 'a';
    return tolower(letra);
}

char obtenerCaracterSiguiente(char letra) {
    return letra + 1;
}

char obtenerCaracterAnterior(char letra) {
    return letra - 1;
}

void mostrarResultados(char opcion1, char opcion2, char opcion3, char opcion4) {
    cout << "RESULTADOS\n";
    cout << "----------\n";
    cout << "MAYUSCULA: " << opcion1;
    cout << "\nMINUSCULA: " << opcion2;
    cout << "\nSIGUIENTE: " << opcion3;
    cout << "\nANTERIOR: " << opcion4;
}

void obtenerResultados(short opcion, char letra, char &opcion1, char &opcion2, char &opcion3, char &opcion4) {
    opcion1 = (opcion == 1) * convertirAMayuscula(letra); // condicion * resultado
    opcion2 = (opcion == 2) * convertirAMinuscula(letra);
    opcion3 = (opcion == 3) * obtenerCaracterSiguiente(letra);
    opcion4 = (opcion == 4) * obtenerCaracterAnterior(letra);
}

int main() {
    short opcion;
    char letra;
    char opcion1, opcion2, opcion3, opcion4;
    mostrarMenu();
    opcion = ingresarOpcion();
    letra = ingresarLetra();
    //obtenerResultados(opcion, letra, opcion1, opcion2, opcion3, opcion4);
    opcion1 = (opcion == 1) * convertirAMayuscula(letra); // expr. logica * resultado
    opcion2 = (opcion == 2) * convertirAMinuscula(letra);
    opcion3 = (opcion == 3) * obtenerCaracterSiguiente(letra);
    opcion4 = (opcion == 4) * obtenerCaracterAnterior(letra);
    mostrarResultados(opcion1, opcion2, opcion3, opcion4);
    return 0;
}