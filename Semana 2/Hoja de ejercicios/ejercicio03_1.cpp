#include <iostream>
using namespace std;

int main() {
    /*
    NEUMATICOS Hnos, empresa dedicada a vender neumáticos, está realizando la siguiente oferta:
    Si el cliente decide comprar menos de 3 neumáticos paga por cada uno de ellos S/. 145.
    Si compra entre 3 y 5 neumáticos paga, por cada uno, S/. 138.
    Si compra más de 5 paga S/. 135 por cada uno.
    Escriba un programa en C++ que teniendo como dato el número de neumáticos que un cliente va a comprar,
    muestre el monto total que pagará por los mismos.
    */
    short* num_neumaticos = new short;
    short* resultado_menos3 = new short, * resultado_entre3y5 = new short, * resultado_mas5 = new short;
    short* monto_total = new short;

    cout << "Ingrese el numero de neumaticos: ";
    cin >> *num_neumaticos;

    // Expresiones logicas y resultado
    *resultado_menos3 = (*num_neumaticos < 3) * (* num_neumaticos * 145); //C1*R1
    *resultado_entre3y5 = (*num_neumaticos >= 3 && *num_neumaticos <= 5) * (*num_neumaticos * 138); //C2*R2
    *resultado_mas5 = (*num_neumaticos > 5) * (*num_neumaticos * 135);    //C3*R3

    // Resultado Final
    // R = C1*R1 + C2*R2 + C3*R3 + ...
    *monto_total = *resultado_menos3 + *resultado_entre3y5 + *resultado_mas5;

    cout << "El monto total que pagara es " << *monto_total << endl;

    delete num_neumaticos;
    delete resultado_menos3;
    delete resultado_entre3y5;
    delete resultado_mas5;
    delete monto_total;
    return 0;
}