//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento

bool buscarNum(vector<int> const& v, int num, int ini, int fin) {
	
	if (ini >= fin) return false;

	int mitad = (ini + fin) / 2;
	if (v[mitad] == num) {
		return true;
	}
	if (v[mitad] < v[ini]) {
		if (v[mitad] < num && num <= v[fin - 1]) {
			return buscarNum(v, num, mitad + 1, fin);
		}
		else return buscarNum(v, num, ini, mitad);
	}

	else {
		if (v[ini] <= num && num < v[mitad]) {
			return buscarNum(v, num, ini, mitad);
		}
		else 
			return buscarNum(v, num, mitad + 1, fin);
	}
}

bool resuelveCaso() {
	int numelem;
	cin >> numelem;
	if (numelem == -1) return false;
	vector<int> v(numelem);
	int buscar;
	cin >> buscar;

	for (int i = 0; i < numelem; i++) {
		cin >> v[i];
	}

		bool num = buscarNum(v, buscar, 0, v.size());
		
		if (num) { cout << "SI" << "\n"; }
		else { cout << "NO\n"; }

	return true;
}

int main() {
	while (resuelveCaso());
	return 0;
}