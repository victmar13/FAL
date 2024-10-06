//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
struct tDatos {
	int numJug, numNin;
	vector<vector<int>> ilusiones;
};

struct tSol {
	vector<int> sol;
	int sumaIdeal;
};


void resolver(tDatos const& d, int pos, tSol& s, vector<bool>& asig, int& masIlu, vector<int> const& maximos, vector<int> const& minimos) {
	for (int i = 0; i < d.numJug; i++) {
		s.sol[pos] = i;
		if (!asig[i]) { //pos en asig de i esta vacia(es false)
			s.sumaIdeal += d.ilusiones[pos][i];
			asig[i] = true;
			if (pos == s.sol.size() - 1) { // es solucion
				if (s.sumaIdeal > masIlu)masIlu = s.sumaIdeal; // es mejor solucion
			}
			else {//no es sol
				if () {//estimacion

				}
				if (s.sumaIdeal + maximos[pos + 1] > masIlu && s.sumaIdeal + minimos[pos+1] > masIlu) { // optimizacion, solo si es max
					resolver(d, pos + 1, s, asig, masIlu, maximos, minimos);
				}
			}
			asig[i] = false;
			s.sumaIdeal -= d.ilusiones[pos][i];
		}

	}
}

bool resuelveCaso() {
	tDatos d;
	cin >> d.numJug;
	if (!cin) { return false; }
	cin >> d.numNin;
	//soluciones
	for (int i = 0; i < d.numNin; i++) {
		vector<int> aux(d.numJug);
		for (int j = 0; j < d.numJug; j++) {
			cin >> aux[j];
		}
		d.ilusiones.push_back(aux);
	}
	vector<int> minimos(d.numNin);
	for (int i = 0; i < d.numNin; i++) {
		int minAux = d.ilusiones[i][0];
		for (int j = 1; j < d.numJug; j++) {
			if (minAux > d.ilusiones[i][j]) minAux = d.ilusiones[i][j];
		}
		minimos[i] = minAux;
	}
	//sumamos acumulados 
	for (int i = (int)minimos.size() - 1; i > 0; i--) {
		minimos[i - 1] += minimos[i];
	}

	vector<int> maximos(d.numNin);
	for (int i = 0; i < d.numNin; i++) {
		int maxAux = d.ilusiones[i][0];
		for (int j = 1; j < d.numJug; j++) {
			if (maxAux < d.ilusiones[i][j]) maxAux = d.ilusiones[i][j];
		}
		maximos[i] = maxAux;
	}
	//sumamos acumulados 
	for (int i = (int)maximos.size() - 1; i > 0; i--) {
		maximos[i - 1] += maximos[i];
	}
	//inicializacion
	int masIlusion = 0;
	for (int i = 0; i < d.numNin; i++) {
		masIlusion += d.ilusiones[i][i];
	}

	tSol s;
	s.sol.assign(d.numNin, 0);
	s.sumaIdeal = 0;
	vector<bool> asignados(d.numJug, false);
	resolver(d, 0, s, asignados, masIlusion, maximos, minimos);
	cout << masIlusion << "\n";

	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}