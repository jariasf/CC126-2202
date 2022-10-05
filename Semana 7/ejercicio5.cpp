#include <iostream>
#include <clocale> // setlocale
#include <cctype>  // toupper
#include <cmath>   // pow
using namespace std;

char ingresarTipoDeUsuario();
short ingresarHoraDeAcceso();
char ingresarTipoDeServicio();
void imprimirMomentoDelDiaConMasAccesos(int,int,int,int);
void imprimirTipoDeServicioPredominante(int,int,int);

int main() {
    setlocale(LC_ALL, "spanish");
    char tipo_usuario, tipo_servicio;
    short hora_acceso;

    // Variables de conteo
    int profesores{0}, alumnos{0}, administrativos{0};
    int madrugada{0}, manhana{0}, tarde{0}, noche{0};
    int servicio_personal{ 0 }, servicio_academico{ 0 }, servicio_administrativo{ 0 };

    bool se_ingresaron_datos{false};
    int cnt_usuarios{0};

    /*
    // Tipo de ingreso usando while
    tipo_usuario = ingresarTipoDeUsuario();
    while (tipo_usuario != 'X') {
        // Ingreso de datos
        hora_acceso = ingresarHoraDeAcceso();
        tipo_servicio = ingresarTipoDeServicio();

        // Cálculos, conteos, etc
        cout << endl;
        tipo_usuario = ingresarTipoDeUsuario();
    }*/

    // Tipo de ingreso usando do-while
    do {
        tipo_usuario = ingresarTipoDeUsuario();
        if (tipo_usuario != 'X') {
            cnt_usuarios++;
            se_ingresaron_datos = true;

            // Ingreso de datos
            hora_acceso = ingresarHoraDeAcceso();
            tipo_servicio = ingresarTipoDeServicio();

            // 1. Contar tipo de usuario
            if (tipo_usuario == 'P') {
                profesores++;
            }
            else if (tipo_usuario == 'A') {
                alumnos++;
            }
            else {
                administrativos++;
            }

            // 2. Contar el momento del día
            //    (madrugada (0 a 5); mañana (6 a 12); tarde(13 a 17); noche(18 a 23))
            if (hora_acceso >= 0 && hora_acceso <= 5) {
                madrugada++;
            }
            else if (hora_acceso >= 6 && hora_acceso <= 12) {
                manhana++;
            }
            else if (hora_acceso >= 13 && hora_acceso <= 17) {
                tarde++;
            }
            else {
                noche++;
            }

            // 3. Contar el tipo de servicio
            switch (tipo_servicio) {
                case 'P': servicio_personal++; break;
                case 'A': servicio_academico++; break;
                case 'D': servicio_administrativo++;  break;
            }

            cout << endl;
        }
    } while (tipo_usuario != 'X');
    
    // Resultados
    cout << "\nLos resultados son: ";
    cout << "\n-----------------------";
    // 1. Mostrar conteo de tipo de usuario
    cout << "\nProfesores: "<<profesores;
    cout << "\nAlumnos: "<<alumnos;
    cout << "\nAdministrativos: " << administrativos;

    if(cnt_usuarios > 0){
    //if (se_ingresaron_datos) {
        // 2. Determinar en qué momento del día se realizan más accesos 
        imprimirMomentoDelDiaConMasAccesos(madrugada, manhana, tarde, noche);

        // 3. Que tipo de servicio predomina más
        imprimirTipoDeServicioPredominante(servicio_personal, servicio_academico, servicio_administrativo);
    }

    return 0;
}

char ingresarTipoDeUsuario() {
    // Tipo de usuario (P: Profesor; A: Alumno: D: Administrativo, X: Fin de ingreso)
    char tipo_usuario;
    do {
        cout << "Ingrese tipo de usuario: ";
        cin >> tipo_usuario;
        tipo_usuario = toupper(tipo_usuario);
    } while ( tipo_usuario != 'P' && tipo_usuario != 'A' 
           && tipo_usuario != 'D' && tipo_usuario != 'X');
    return tipo_usuario;
}

short ingresarHoraDeAcceso() {
    // Hora de acceso (Entero positivo entre 0 y 23)
    short hora_acceso;
    do {
        cout << "Hora de acceso: ";
        cin >> hora_acceso;
    } while ( !(hora_acceso >= 0 && hora_acceso <= 23) );
    return hora_acceso;
}

char ingresarTipoDeServicio() {
    //Tipo de servicio (P: Personal; A: Académico; D: Administrativo)
    char tipo_servicio;
    do {
        cout << "Tipo de servicio: ";
        cin >> tipo_servicio;
        tipo_servicio = toupper(tipo_servicio);
    } while ( !(tipo_servicio == 'P' || tipo_servicio == 'A' || tipo_servicio == 'D') );
    return tipo_servicio;
}

void imprimirMomentoDelDiaConMasAccesos(int madrugada, int manhana, int tarde, int noche) {
    cout << "\nEn la ";
    if (madrugada >= manhana && madrugada >= tarde && madrugada >= noche) {
        cout << "MADRUGADA";
    }
    else if (manhana >= madrugada && manhana >= tarde && manhana >= noche) {
        cout << "MAÑANA";
    }
    else if (tarde >= madrugada && tarde >= manhana && tarde >= noche) {
        cout << "TARDE";
    }
    else {
        cout << "NOCHE";
    }
    cout << " se tuvieron más accesos\n";
    /*
    if (madrugada >= manhana && madrugada >= tarde && madrugada >= noche) {
        cout << "En la MADRUGADA se tuvieron más accesos"<<endl;
    }
    else if (manhana >= madrugada && manhana >= tarde && manhana >= noche ) {
        cout << "En la MAÑANA se tuvieron más accesos" << endl;
    }
    else if (tarde >= madrugada && tarde >= manhana && tarde >= noche) {
        cout << "En la TARDE se tuvieron más accesos" << endl;
    }
    else {
        cout << "En la NOCHE se tuvieron más accesos" << endl;
    }*/
}

void imprimirTipoDeServicioPredominante(int personal, int academico, int administrativo) {
    cout << "Predominan los servicios de: ";
    if (personal >= academico && personal >= administrativo) {
        cout << "Personal";
    }
    if (academico >= personal && academico >= administrativo) {
        cout << "\n                             Academico";
    }
    if (administrativo >= academico && administrativo >= personal) {
        cout << "\n                             Administrativo";
    }
}