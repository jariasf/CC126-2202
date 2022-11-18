#include <iostream>
using namespace std;

struct Agente {
    int x, y;
    int alto, ancho;
    int dx, dy;
    bool activo;
};

int main() {

    // Variables
    Agente agente{1, 1, 3, 3, 1, 1, false};
    cout << agente.x << " " << agente.y << endl;

    /*
       entero_dinamico = 2341
                         |
                         Agente
    */
    Agente* agente_dinamico = new Agente{1, 1, 3, 3, 1, 1, false};
    cout << agente_dinamico->x << " " << agente_dinamico->y << endl;

    // Arreglo de estructuras
    /*
        agentes_dinamico = 1234
                           |
                           | agente  |  agente  |  agente  |
    */
    Agente* agentes = new Agente[5];
    agentes[0].x = 4;
    agentes[0].y = 2;
    agentes[0] = {1, 1, 3, 3, 1, 1, false};

    // Arreglo de punteros a estructuras
    /*
        agentes_dinamico = | 2345  |  5654  |  2353  |  6778 |   4564 |
                              |        |       |         |        |
                            agente    agente   agente   agente   agente
    */
    
    Agente** agentes_dinamicos = new Agente * [5];
    for (int i = 0; i < 5; ++i) {
        agentes_dinamicos[i] = new Agente;
    }
    agentes_dinamicos[0]->x = 4;
    agentes_dinamicos[0]->y = 2;

    // Liberar memoria de entero en heap
    delete agente_dinamico;

    // Liberar memoria de arreglo de estructuras
    delete[] agentes;

    // Liberar memoria de arreglo de punteros
    for (int i = 0; i < 5; ++i)
        delete agentes_dinamicos[i];
    delete[] agentes_dinamicos;
    return 0;
}