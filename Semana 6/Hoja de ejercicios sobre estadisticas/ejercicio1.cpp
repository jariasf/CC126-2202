#include <iostream>
using namespace std;

char ingresarTipoDeTransporte();
char ingresarEmpresa();
char ingresarHotel();
short ingresarDiasDeViaje();
void calcularIngresosPorEmpresa(char, char, short&, short&, short&, short&, short&);
void calcularIngresosPorHotel(char, short, double&, double&, double&);
void imprimirHotelConMasIngresos(double, double, double);

int main() {
    char tipo_transporte, empresa, hotel;
    short dias_viaje, viajeros_hotel30{0}, viajeros_oltursa{0}, total_viajeros{0};
    double porcentaje_oltursa;
    // Variables de conteo o acumuladores
    short oltursa_bus_cama{ 0 }, oltursa_vip{ 0 }, cruz_bus_cama{ 0 }, cruz_vip{ 0 }, linea_bus_cama{ 0 };
    double pinos{ 0. }, emperador{ 0. }, canhaveral{ 0. };

    tipo_transporte = ingresarTipoDeTransporte();        
    while (tipo_transporte != 'F') {
        empresa = ingresarEmpresa();
        hotel = ingresarHotel();
        dias_viaje = ingresarDiasDeViaje();
        // 0. Contar total de viajeros
        total_viajeros++;

        // 1. Contar viajeros que se alojan en hotel de $30
        if (hotel == 'E' || hotel == 'C') {
            viajeros_hotel30++;
        }

        // 2. Contar viajeros que eligieron Oltursa
        if (empresa == 'O') {
            viajeros_oltursa++;
        }

        // 3. Calcular ingresos por empresa
        calcularIngresosPorEmpresa(empresa, tipo_transporte, 
                                   oltursa_bus_cama, oltursa_vip,
                                   cruz_bus_cama, cruz_vip,
                                   linea_bus_cama);

        // 4. Calcular ingresos por hotel
        calcularIngresosPorHotel(hotel, dias_viaje, pinos, emperador, canhaveral);

        cout << "\n";
        tipo_transporte = ingresarTipoDeTransporte();
    }

    // Calcular el porcentaje
    if (total_viajeros != 0) {
        porcentaje_oltursa = 100.0 * viajeros_oltursa / total_viajeros;
    }
    else {
        porcentaje_oltursa = 0.;
    }

    cout << "\nCantidad de viajeros que se alojan en un hotel de US$ 30: "<<viajeros_hotel30;
    cout << "\n% de viajeros que eligieron Oltursa: "<<porcentaje_oltursa;
    cout << "\nReporte de ingresos de cada empresa";
    cout << "\nOltursa";
    cout << "\nBus Cama: " << oltursa_bus_cama;
    cout << "\nServicio VIP: " << oltursa_vip;
    cout << "\nCruz del Sur";
    cout << "\nBus Cama: " << cruz_bus_cama;
    cout << "\nServicio VIP: " << cruz_vip;
    cout << "\nLinea: ";
    cout << "\nBus Cama: " << linea_bus_cama;

    if (total_viajeros > 0) {
        imprimirHotelConMasIngresos(pinos, emperador, canhaveral);
    }
    else {
        cout << "\n\nNo se registraron ingresos para los hoteles";
    }
    return 0;
}

char ingresarTipoDeTransporte() {
    char tipo_transporte;
    do {
        cout << "Ingrese el tipo de transporte (B: bus cama; V: servicio vip): ";
        cin >> tipo_transporte;
        tipo_transporte = toupper(tipo_transporte);
    } while ( !(tipo_transporte == 'B' || tipo_transporte == 'V' || tipo_transporte == 'F'));
    return tipo_transporte;
}

char ingresarEmpresa() {
    char empresa;
    do {
        cout << "Ingrese la empresa en la que viaja (O: Oltursa; C: Cruz del Sur; L: Línea): ";
        cin >> empresa;
        empresa = toupper(empresa);
    } while (empresa != 'O' && empresa != 'C' && empresa != 'L');
    return empresa;
}

char ingresarHotel() {
    char hotel;
    do {
        cout << "Ingrese el Hotel en el que se hospeda (P: Los Pinos; E: Emperador; C: Cañaveral): ";
        cin >> hotel;
        hotel = toupper(hotel);
    } while ( hotel != 'P' && hotel != 'E' && hotel != 'C');
    return hotel;
}

short ingresarDiasDeViaje() {
    short dias_viaje;
    do {
        cout << "Número de días del viaje: ";
        cin >> dias_viaje;
    } while ( dias_viaje < 3);
    return dias_viaje;
}

void calcularIngresosPorEmpresa(char empresa, char tipo_transporte, 
                                short &oltursa_bus_cama, short &oltursa_vip,
                                short &cruz_bus_cama, short &cruz_vip, 
                                short &linea_bus_cama) {
    if (empresa == 'O') {
        if (tipo_transporte == 'B') {
            oltursa_bus_cama += 150;
        }
        else {
            oltursa_vip += 230;
        }
    }
    else if (empresa == 'C') {
        if (tipo_transporte == 'B') {
            cruz_bus_cama += 200;
        }
        else {
            cruz_vip += 330;
        }
    }
    else {
        if (tipo_transporte == 'B') {
            linea_bus_cama += 100;
        }
    }
}

void calcularIngresosPorHotel(char hotel, short dias_viaje, 
                              double&pinos, double&emperador, double&canhaveral) {

    switch (hotel) {
        case 'P': pinos += 2.6 * (20. * dias_viaje); break;
        case 'E': emperador += 2.6 * (30. * dias_viaje); break;
        case 'C': canhaveral += 2.6 * (30. * dias_viaje); break;
    }
}

void imprimirHotelConMasIngresos(double pinos, double emperador, double canhaveral) {
    double monto;
    cout << "\n\nEl hotel que registró más ingresos fue ";
    if (pinos > emperador && pinos > canhaveral) {
        cout << "Pinos";
        monto = pinos;
    }
    else if (emperador > pinos && emperador > canhaveral) {
        cout << "Emperador";
        monto = emperador;
    }
    else {
        cout << "Cañaveral";
        monto = canhaveral;
    }
    cout << " y el monto fue " << monto << " soles";
}