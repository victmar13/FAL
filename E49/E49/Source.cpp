//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento

int menorNum(vector < int> const& v, int min, int ini, int fin) {
	if (ini + 1 >= fin) return min; // vector 1 elemento
	else { // Vector de dos o mas elementos
		int mitad = (ini + fin - 1) / 2;
		if (v[mitad] > v[mitad + 1]) return menorNum(v, v[mitad + 1], mitad + 1, fin);
		else return menorNum(v, v[mitad], ini, mitad + 1); // incluye la mitad
	}
}

bool resuelveCaso() {
	int numelem;
	cin >> numelem;
	if (!cin || numelem == 0) return false;
	vector < int > v(numelem);
	for (int& n : v) cin >> n;

	if (!numelem) cout << 0 << endl;
	// Busca en el lado izquierdo
	else {
		int num = menorNum(v, v[0], 0, (int)v.size());
		cout << num << "\n";
	}

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}