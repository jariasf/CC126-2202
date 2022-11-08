#include <iostream>
#include <iomanip>
using namespace std;


struct Encuestado {
    int nivel_aprobacion;
    int edad;
    char nivel_socio_economico;
};

void generarDatos(Encuestado*, int);
int nextInt(int, int);
void mostrarDatos(Encuestado*, int);
int calcularNivelAprobacionMasFrecuente(Encuestado*, int);
int calcularPersonasPorNivelSocioEconomico(Encuestado*, int, char);

int main() {
    srand(time(NULL));

    int n;
    Encuestado* encuestados;

    // 1. Ingreso del número de personas
    do {
        cout << "Ingresar el número de encuestados: ";
        cin >> n;
    } while (n <= 0 || n > 100);

    encuestados = new Encuestado[n];

    // 2. Generar aleatoriamente los datos de cada encuestado
    generarDatos(encuestados, n);
    mostrarDatos(encuestados, n);

    // 3. Calcule e imprima cual es el nivel de aprobación que obtuvo la mayor votación
    int mayor_nivel = calcularNivelAprobacionMasFrecuente(encuestados, n);
    cout << "\nNivel de aprobacion que obtuvo la mayor votacion: " << mayor_nivel << endl;

    // 4. Calcule e imprima cuantas personas del nivel socio económico A, participaron de la encuesta
    int cantidad = calcularPersonasPorNivelSocioEconomico(encuestados, n, 'A');
    cout << "\nCantidad de personas del nivel socio economico A: " << cantidad << endl;

    // 5. TODO: Determine e imprima la edad de la persona más joven que fue encuestada.


    delete[] encuestados;
    encuestados = nullptr;
    return 0;
}

int nextInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void generarDatos(Encuestado* encuestados, int n) {
    for (int i = 0; i < n; ++i) {
        encuestados[i].nivel_aprobacion = nextInt(1, 5); //1 (malo) y 5 (excelente)
        encuestados[i].edad = nextInt(18, 120);
        encuestados[i].nivel_socio_economico = nextInt('A', 'D');
    }
}

void mostrarDatos(Encuestado* encuestados, int n) {
    cout << left << setw(11) << "Encuestado";
    cout << setw(11) << "Aprobacion";
    cout << setw(5) << "Edad";
    cout << setw(14) << "Socieconomico"<<endl;
    
    for (int i = 0; i < n; ++i) {
        cout << left << setw(11) << i + 1;
        cout << setw(11) << encuestados[i].nivel_aprobacion;
        cout << setw(5) << encuestados[i].edad;
        cout << setw(14) << encuestados[i].nivel_socio_economico << endl;
    }
}

int calcularNivelAprobacionMasFrecuente(Encuestado* encuestados, int n) {
    /*
    Entrada:
    encuestados= [(1, 23, 'A'), (2, 34, 'C'),(1, 22, 'B'), (4, 35, 'D')], n = 4;

    Salida:
    1
    */
    // 1. Calcular las frecuencias
    /*
    1 -> 2
    2 -> 1
    3 -> 0
    4 -> 1
    5 -> 0
    */
    int frecuencias[6]{}; //[contador0, contador1, contador2, contador3, contador4, contador5]

    //frecuencias[1]++;
    //frecuencias[4]++;
    //frecuencias[5]++;
    for (int i = 0; i < n; ++i) {
        int aprobacion_actual = encuestados[i].nivel_aprobacion; //1-5
        frecuencias[aprobacion_actual]++;
    }

    //                0  1  2  3  4  5
    // frecuencias = [0, 2, 1, 0, 1, 0]

    // 2. Calcular la mayor
    int mayor = frecuencias[1], nivel_mayor{1};
    for (int i = 2; i < 6; ++i) {
        if (frecuencias[i] > mayor) {
            mayor = frecuencias[i];
            nivel_mayor = i;
        }
    }
    return nivel_mayor;
}

int calcularPersonasPorNivelSocioEconomico(Encuestado* encuestados, int n, char nivel) {
    /*
    Entrada:
    encuestados= [(1, 23, 'A'), (2, 34, 'C'),(1, 22, 'A'), (4, 35, 'D')], n = 4, nivel='A';

    Salida:
    2
    */
    int contador{0};
    for (int i = 0; i < n; ++i) {
        if (encuestados[i].nivel_socio_economico == nivel) {
            contador++;
        }
    }
    return contador;
}