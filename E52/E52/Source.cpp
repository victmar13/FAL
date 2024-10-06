//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento

int numBingo(vector <int> const& v, int ini, int fin, int num) {
	int sol;
	if (fin - ini == 1 && (num + ini == v[ini])) {
		return v[ini];
	}
	else if (fin - ini == 1) {
		sol = -1;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (num + mitad < v[mitad]) {
			return numBingo(v, ini, mitad, num);
		}
		else if (num + mitad == v[mitad]) {
			return v[mitad];
		}
		else if (num + mitad > v[mitad]) {
			return numBingo(v, mitad, fin, num);
		}
	}

	return sol;
}

bool resuelveCaso() {
	int tam, num;
		cin >> tam;
		if (!cin || tam == 0) { return false; }

		cin >> num;
	vector < int > v(tam);
	for (int i = 0; i < tam; i++) cin >> v[i];

	int numero = numBingo(v, 0, (int)v.size(), num);
	if (numero != -1) {
		cout << numero << "\n";
	}
	else{ cout << "NO\n"; }
	return true;
}

int main() {
	int tam;
	cin >> tam;
	for (int i = 0; i < tam; i++) {
		resuelveCaso();
	}
	return 0;
}