//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
struct tHeroe {
	vector<int> clase;
	vector<int> nivel;
	vector<int> ptosAtaque;
};
struct tDatos {
	int numHeroes, nCristales, maxLevelCristal, PV;
	tHeroe heroe; //[x] == num Heroe ,
};

struct tSol {
	vector<int> sol;
	int sumaAct;
	vector<bool> puestoCogido;
};


void resolver(tDatos const& d, int pos, tSol& s, int& min, vector<int> const& acum) {
	for (int i = 0; i < d.numFunc; i++) {
		s.sol[pos] = d.tardan[pos][i];
		if (!s.puestoCogido[i]) { //pos en asig de i esta vacia(es false)
			s.sumaAct += d.tardan[pos][i];
			s.puestoCogido[i] = true;
			if (pos == s.sol.size() - 1) { // puede ser solucion
				if (s.sumaAct < min)min = s.sumaAct;
			}
			else {//no es sol
				if ((s.sumaAct + acum[pos + 1]) < min) {
					resolver(d, pos + 1, s, min, acum);
				}

			}
			s.puestoCogido[i] = false;
			s.sumaAct -= d.tardan[pos][i];
		}
	}
}

bool resuelveCaso() {
	tDatos d;
	cin >> d.numHeroes >> d.nCristales >> d.maxLevelCristal >> d.PV;
	
	//soluciones
	int aux;
		for (int j = 0; j < d.numHeroes; j++) {
			cin >> aux;
			d.heroe.clase.push_back(aux);
		}
		for (int j = 0; j < d.numHeroes; j++) {
			cin >> aux;
			d.heroe.nivel.push_back(aux);
		}
		for (int j = 0; j < d.numHeroes; j++) {
			cin >> aux;
			d.heroe.ptosAtaque.push_back(aux);
		}
		int sumaPtos = 0;
		for (int i = 0; i < d.numHeroes; i++) {
			sumaPtos += d.heroe.ptosAtaque[i];
		}

		vector<int> acum(d.numHeroes);
		acum[d.numHeroes - 1] = d.heroe.ptosAtaque[d.numHeroes - 1];
		for (int i = d.numHeroes - 2; i <= 0; i--) {
			acum[i - 1] += acum[i];
		}

	//Vector con el minimo de cada funcionario
	vector<int> acum(d.numFunc);
	for (int i = 0; i < d.numFunc; i++) {
		int minAux = d.tardan[i][0];
		for (int j = 1; j < d.trabajos; j++) {
			if (minAux > d.tardan[i][j]) minAux = d.tardan[i][j];
		}
		acum[i] = minAux;
	}
	//sumamos acumulados 
	for (int i = (int)acum.size() - 1; i > 0; i--) {
		acum[i - 1] += acum[i];
	}
	//inicializacion
	int minTardan = 0;
	for (int i = 0; i < d.numFunc; i++) {
		minTardan += d.tardan[i][i];
	}

	tSol s;
	s.sol.assign(d.numFunc, 0);
	s.sumaAct = 0;
	s.puestoCogido.assign(d.numFunc, false);
	vector<bool> asignados(d.numFunc, false);
	resolver(d, 0, s, minTardan, acum);

	cout << minTardan << "\n";

	return true;
}

int main() {

	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}

	return 0;
}