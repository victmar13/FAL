//Victoria Martin Rojo
//A43

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

// Solucion recursiva lineal final
int complementario(int n, int dig, int pot) {
	//caso base
	if (n < 10) {
		return (9 - n) * pot + dig;
	}
	//caso recursivo
	else {
		int digito = (9 - n % 10)* pot + dig;
		return complementario(n / 10, digito, 10 * pot );
	}
}

int inverso(int n, int dig) {
	/*//caso base
	if (n < 10) {
		return dig * 10 + n;
	}
	//caso recursivo
	else return inverso(n / 10, dig * 10 + n % 10);
	*/
	//caso base
	if (n < 10) {
		return (9 - n) + dig;
	}
	//caso recursivo
	else {
		int digito = (9 - n % 10) + dig;
		return inverso(n / 10, digito * 10);
	}

}

bool resuelveCaso() {
	// leer los datos de la entrada
	int num;
	cin >> num;
	if (!cin) return false;
	// resolver y escribir los resultados
	//no final
	int comp = complementario(num, 0, 1);
	int inv = inverso(num, 0);


	cout << comp << " " << inv << "\n";
	return true;
}
int main() {
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

	return 0;
}