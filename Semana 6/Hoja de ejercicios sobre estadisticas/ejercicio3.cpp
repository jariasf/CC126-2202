#include <iostream>
using namespace std;

char ingresarTipoDeNoticia();
short ingresarHoraDePublicacion();
char ingresarOrigen();
void contarTipoDeNoticias(char, short&, short&, short&);
void contarMomentosDelDia(short, short&, short&, short&, short&);
void imprimirMayorMomentoDelDia(short, short, short, short);
void imprimirNoticiaMasPredominante(short, short);
void imprimirMayoresMomentosDelDia(short, short, short, short);

int main() {
    char tipo_noticia, origen;
    short hora_publicacion;

    // Variables de conteo
    short deportes{0}, actualidad{0}, entretenimiento{0};
    short madrugada{0}, manhana{0}, tarde{0}, noche{0};
    short nacional{0}, extranjera{0};

    tipo_noticia = ingresarTipoDeNoticia();
    while (tipo_noticia != 'X') {
        hora_publicacion = ingresarHoraDePublicacion();
        origen = ingresarOrigen();

        // 1. Contar tipos de noticias
        /*switch (tipo_noticia) {
            case 'D': deportes++; break;
            case 'A': actualidad++; break;
            case 'E': entretenimiento++; break;
        }*/
        contarTipoDeNoticias(tipo_noticia, deportes, actualidad, entretenimiento);

        // 2. Contar momentos del dia
        // (madrugada (0 a 5); mañana (6 a 12); tarde (13 a 17); noche (18 a 23)) 
        contarMomentosDelDia(hora_publicacion, madrugada, manhana, tarde, noche);

        // 3. Contar de origen (N o E)
        if (origen == 'N')
            nacional++;
        else
            extranjera++;

        cout << "\n";
        tipo_noticia = ingresarTipoDeNoticia();
    }

    cout << "\nLos resultados son:";
    cout << "\n-------------------";
    cout << "\nNoticias de Deporte: " << deportes;
    cout << "\nNoticias de Actualidad: " << actualidad;
    cout << "\nNoticas de Entretenimiento: " << entretenimiento;
    // Imprimir el mayor momento del dia
    imprimirMayorMomentoDelDia(madrugada, manhana, tarde, noche);

    // Imprimir la noticia mas predominante
    imprimirNoticiaMasPredominante(nacional, extranjera);
    return 0;
}

char ingresarTipoDeNoticia() {
    char tipo_noticia;
    do {
        cout << "Ingrese tipo de noticia  (D: Deportes; A: Actualidad: E: Entretenimiento): ";
        cin >> tipo_noticia;
        tipo_noticia = toupper(tipo_noticia);
    } while ( tipo_noticia != 'D' && tipo_noticia != 'A' && 
              tipo_noticia != 'E' && tipo_noticia != 'X');
    return tipo_noticia;
}

short ingresarHoraDePublicacion() {
    short hora_publicacion;
    do {
        cout << "Hora de publicacion: ";
        cin >> hora_publicacion;
    } while ( !(hora_publicacion >= 0 && hora_publicacion <= 23) );
    return hora_publicacion;
}

char ingresarOrigen() {
    char origen;
    do {
        cout << "Origen (N: Nacional; E: Extranjera): ";
        cin >> origen;
        origen = toupper(origen);
    } while (origen != 'N' && origen != 'E');
    return origen;
}

void contarTipoDeNoticias(char tipo_noticia, short &deportes, 
                         short &actualidad, short &entretenimiento) {
    switch (tipo_noticia) {
        case 'D': deportes++; break;
        case 'A': actualidad++; break;
        case 'E': entretenimiento++; break;
    }
}

void contarMomentosDelDia(short hora_publicacion, short &madrugada, 
                          short &manhana, short &tarde, short&noche) {
    // (madrugada (0 a 5); mañana (6 a 12); tarde (13 a 17); noche (18 a 23)) 
    if (hora_publicacion >= 0 && hora_publicacion <= 5) {
        madrugada++;
    }
    else if (hora_publicacion <= 12) {
        manhana++;
    }
    else if (hora_publicacion <= 17) {
        tarde++;
    }
    else {
        noche++;
    }
}

void imprimirMayorMomentoDelDia(short madrugada, short manhana, short tarde, short noche) {
    // Asumiendo que existe un unico elemento mayor
    // En la TARDE se publicaron más noticias
    cout << "\nEn la ";
    if (madrugada > manhana && madrugada > tarde && madrugada > noche) {
        cout << "MADRUGADA";
    }
    else if (manhana > madrugada && manhana > tarde && manhana > noche) {
        cout << "MAÑANA";
    }
    else if (tarde > madrugada && tarde > manhana && tarde > noche ) {
        cout << "TARDE";
    }
    else {
        cout << "NOCHE";
    }
    cout << " se publicaron mas noticias";
}

void imprimirMayoresMomentosDelDia(short madrugada, short manhana, short tarde, short noche) {
    // Asumiendo que existe mas de un mayor
    cout << "\nEn la ";
    if (madrugada >= manhana && madrugada >= tarde && madrugada >= noche) {
        cout << "MADRUGADA ";
    }
    if (manhana >= madrugada && manhana >= tarde && manhana >= noche) {
        cout << "MAÑANA ";
    }
    if (tarde >= madrugada && tarde >= manhana && tarde >= noche) {
        cout << "TARDE ";
    }
    if (noche >= madrugada && noche >= manhana && noche >= tarde) {
        cout << "NOCHE ";
    }
    cout << "se publicaron mas noticias";
}

void imprimirNoticiaMasPredominante(short nacional, short extranjera) {
    cout << "\nPredominan las noticias ";
    if (nacional > extranjera) {
        cout << "Nacionales";
    }
    else if (extranjera > nacional) {
        cout << "del Extranjero";
    }
    else {
        cout << "Nacionales y del Extranjero";
    }
}