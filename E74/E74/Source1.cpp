//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
struct tDatos {
	int numHab, numSitios, posBruja;
	vector<vector<int>> satisfac;
};

struct tSol {
	vector<int> sol;
	int sumaAct;
	int contMax = 0;
	vector<bool> habCogido;
};

void resolver(tDatos const& d, int pos, tSol& s, int& max, int supersticion) { //, vector<int> const& acum
	for (int i = 0; i < d.numHab; i++) {
		s.sol[pos] = i;
		if (!s.habCogido[i] && d.satisfac[pos][i] > 0) {
			if (i == pos) {
				supersticion++;
			}
			s.sumaAct += d.satisfac[pos][i];
			s.habCogido[i] = true;
			
			//mirar es solucioon
			if (pos == s.sol.size() - 1) {
				//solucion valida
				if (supersticion <= d.numHab / 3 && s.habCogido[d.posBruja]) {
					//mejora solucion o la iguala?
					if (s.sumaAct >= max) {
						if (s.sumaAct == max) { s.contMax++; }
						else { max = s.sumaAct; s.contMax = 1; }
					}
				}
			}
			else {
				resolver(d, pos + 1, s, max, supersticion);
			}

			if (i == pos) { supersticion--; }
			s.sumaAct -= d.satisfac[pos][i];
			s.habCogido[i] = false;
		}
	}

}

bool resuelveCaso() {
	tDatos d;
	cin >> d.numHab;
	if (!cin || d.numHab == 0) { return false; }
	cin >> d.numSitios >> d.posBruja;
	if (d.numSitios > d.numHab) { return false; }
	//satisf
	for (int i = 0; i < d.numSitios; i++) {
		vector<int> aux(d.numHab);
		for (int j = 0; j < d.numHab; j++) {
			cin >> aux[j];
		}
		d.satisfac.push_back(aux);
	}
	int max = 0;

	tSol s;
	s.sol.assign(d.numSitios, 0);
	s.sumaAct = 0;
	s.habCogido.assign(d.numHab, false);
	resolver(d, 0, s, max, 0);
	if (s.contMax > 0) {
		cout << max << " " << s.contMax << "\n";
	}
	else { cout << "No\n"; }

	return true;
}

int main() {

	while (resuelveCaso()) {}

	return 0;
}