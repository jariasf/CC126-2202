#include <iostream>
using namespace std;

int main() {
	int* numero = new int;
	bool* es_par = new bool;
	bool* es_impar = new bool;

	cout << "Ingrese un numero: ";
	cin >> *numero;

	*es_par = (*numero % 2 == 0);
	//*es_impar = (*numero % 2 != 0);
	*es_impar = !*es_par;

	cout << "Es par? " << *es_par << "\n";
	cout << "Es impar? " << *es_impar << "\n";

	delete es_par;
	delete es_impar;
	delete numero;
	return 0;
}