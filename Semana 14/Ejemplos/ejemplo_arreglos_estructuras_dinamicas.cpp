#include <iostream>
#include "utils.hpp"
using namespace std;

struct Agente {
    int x, y;
    int alto, ancho;
    int dx, dy;
    bool activo;
    string* cuerpo{ nullptr };
};

void eliminarMemoriaAgentes(Agente**, int);
void eliminarMemoriaAgente(Agente*);
void mostrarAgentes(Agente**, int);
void generarAgentes(Agente**, int);

int main() {
    srand(time(NULL));
    int num_agentes{5};
    Agente** agentes = new Agente*[num_agentes];
    for (int i = 0; i < num_agentes; ++i)
        agentes[i] = new Agente;

    generarAgentes(agentes, num_agentes);
    mostrarAgentes(agentes, num_agentes);
    eliminarMemoriaAgentes(agentes, num_agentes);

    //system("pause>0");
    return 0;
}

void generarAgentes(Agente** agentes, int n) {

    int direcciones[4][2] = { {0,1},{1,0},{-1,0},{0,1} };
    string cabezas[3] = {"<o>", "-o-", "#_#"};
    for (int i = 0; i < n; ++i) {
        //do {
        agentes[i]->x = nextInt(1, 30);
        agentes[i]->y = nextInt(1, 30);
        //} while ( !esPosicionVacia(agentes[i]->x, agentes[i]->y, laberinto));
        
        int pos = nextInt(0, 3);
        agentes[i]->dx = direcciones[pos][0];
        agentes[i]->dy = direcciones[pos][1];
        /*do {
            agentes[i]->dx = nextInt(-1, 1);
            agentes[i]->dy = nextInt(-1, 1);
        } while (agentes[i]->dx == 0 && agentes[i]->dy == 0);
        */
        agentes[i]->alto = 3;
        agentes[i]->ancho = 3;

        agentes[i]->cuerpo = new string[3]{
            cabezas[nextInt(0,2)],
            "| |",
            "-o-"
        };
        agentes[i]->activo = nextInt(0,1);
    }
}

void mostrarAgentes(Agente** agentes, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\n\nAgente " << i + 1;
        cout << "\nPosicion: (" << agentes[i]->x << "," << agentes[i]->y << ");";
        cout << "\nDesplazamiento: (" << agentes[i]->dx << "," << agentes[i]->dy << ");";
        cout << "\nTamanio: (" << agentes[i]->alto << "," << agentes[i]->ancho << ");";
        cout << "\nCuerpo:\n";
        for (int j = 0; j < agentes[i]->alto; ++j) {
            cout << agentes[i]->cuerpo[j]<<endl;
        }
        cout << "Activo: " << agentes[i]->activo;
    }
}

void eliminarMemoriaAgente(Agente* agente) {
    if( agente -> cuerpo != nullptr)
        delete[] agente->cuerpo;
    delete agente;
}

void eliminarMemoriaAgentes(Agente** agentes, int n) {
    for (int i = 0; i < n; ++i)
        eliminarMemoriaAgente(agentes[i]);
    delete[] agentes;
}