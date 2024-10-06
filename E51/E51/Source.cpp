//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento

char letraFalta(vector <char> const& v, int ini, int fin, char letraIni, char letraFin) {
	char sol;
	if (fin - ini == 1 && v[0] != letraIni) { // caso solo se tiene un preso y falta el anterior a el 
		sol = letraIni;
	}

	else if (fin - ini == 1 && v[v.size() - 1] != letraFin) {
		sol = letraFin;
	}

	else if (fin - ini == 1) {
		sol = v[ini] + 1;
	}
	else {
		int mitad = (ini + fin) / 2;
		if (v[mitad] - v[ini] == mitad - ini) {
			sol = letraFalta(v, mitad, fin, letraIni, letraFin);
		}

		else { sol = letraFalta(v, ini, mitad, letraIni, letraFin); }
	}

	return sol;
}

void resuelveCaso() {
	char ini, fin;
	cin >> ini >> fin;

	int tam = fin - ini;
	vector < char > v(tam);
	for (int i = 0; i < tam; i++) cin >> v[i];

	char letra = letraFalta(v, 0, (int)v.size(), ini, fin);
	cout << letra << "\n";
	
}

int main() {
	int tam;
	cin >> tam;
	for (int i = 0; i < tam; i++) {
		resuelveCaso();
	}
	return 0;
}