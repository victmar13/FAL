//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;
struct tDatos {
	int numAmigos, numCanoas, pesoMax;
	vector<int> pesos;
	vector<vector<int>> rencillas;
};

//sol[pos].size() = contador de como de llena esta la barca pos

struct tSol {
	vector<vector<int>> sol;
	int contBarcas;
	vector<bool> usadas;
};

bool tienenRencillas(tDatos const& d, int persona, tSol& s, int const& pos) {
	for (int i = 0; i < s.sol[pos].size(); i++) {
		if (d.rencillas[persona][s.sol[pos][i]] == 1) {
			return false;
		}
	}
	return true;
}

// d = struct de datos que cogemos de pantalla, 
//sol = solucion que vamos sacando, 
//pos = pos del vector sol por la que vamos(barca que estamos llenando)
//sumaPesos = vector de pesos en cada barca
//minBarcas = minimos de barcas que podemos usar
void resolver(tDatos const& d, int pos, tSol& s, vector<int>& sumaPesosBarco, int& minBarcas, int const& personasUtilizadas, vector<int> const& minimos) {

	if (personasUtilizadas == d.numAmigos) { // es solucion

		if (s.contBarcas < minBarcas) {
			minBarcas = s.contBarcas;
		}
		return;
	}

	if (pos > d.numCanoas || s.contBarcas >= minBarcas) { // si nos pasamos de cantidad de canoas que disponemos
		return;
	}
	//NO hay sol, seguimos metiendo personas
	for (int i = 0; i < d.numAmigos; i++) {
		if (sumaPesosBarco[pos] == 0) {
			s.contBarcas++;
		}
		//  persona no usada && su peso + pesoAct barca <= max peso && no tiene redencillas con personas de la barca && no hay mas de 3 personas en la barca
		s.sol[pos].push_back(i);
		if (!s.usadas[i] && sumaPesosBarco[pos] + d.pesos[i] <= d.pesoMax && tienenRencillas(d, i, s, pos) && s.sol[pos].size() <= 3) {
			if (minimos[i] + sumaPesosBarco[pos] <= d.pesoMax) {

				s.usadas[i] = true;
				sumaPesosBarco[pos] += d.pesos[i];
				resolver(d, pos, s, sumaPesosBarco, minBarcas, personasUtilizadas + 1, minimos);
				sumaPesosBarco[pos] -= d.pesos[i];
				s.sol[pos].pop_back();
				s.usadas[i] = false;
			}
		}
		//en caso de que no se meta persona porque pesa demasiado la barca || en caso de que ya haya 3 personas en la barca
		else if (sumaPesosBarco[pos] + d.pesos[i] > d.pesoMax || s.sol[pos].size() == 3) {
			s.sol[pos].pop_back();
			resolver(d, pos + 1, s, sumaPesosBarco, minBarcas, personasUtilizadas, minimos);
		}

		else {
			s.sol[pos].pop_back();
		}
		if (sumaPesosBarco[pos] == 0) {
			s.contBarcas--;
		}
	}
}

bool resuelveCaso() {
	tDatos d;
	cin >> d.numAmigos >> d.numCanoas >> d.pesoMax;
	//soluciones
	for (int i = 0; i < d.numAmigos; i++) {
		int peso;
		cin >> peso;
		d.pesos.push_back(peso);
	}

	for (int i = 0; i < d.numAmigos; i++) {
		vector<int> aux(d.numAmigos);
		for (int j = 0; j < d.numAmigos; j++) {
			cin >> aux[j];
		}
		d.rencillas.push_back(aux);
	}

	vector<int> minimos(d.numAmigos);
	minimos[d.numAmigos - 1] = d.pesos[d.numAmigos - 1];
	for (int i = d.numAmigos - 2; i >= 0; i--) {
		if (d.pesos[i] < minimos[i + 1]) {
			minimos[i] = d.pesos[i];
		}
		else { minimos[i] = minimos[i + 1]; }
	}

	minimos.insert(minimos.begin(), 0);
	tSol s;
	s.contBarcas = 0;
	s.usadas.assign(d.numAmigos, false);
	s.sol.resize(d.numCanoas);
	vector<int> sumaPesosBarca(d.numCanoas, 0);
	//vector<int> solMejor;
	int minBarcas = d.numCanoas + 1;
	resolver(d, 0, s, sumaPesosBarca, minBarcas, 0, minimos);

	if (minBarcas < d.numCanoas + 1) {
		cout << minBarcas;
	}
	else cout << "IMPOSIBLE";

	cout << "\n";

	return true;
}

int main() {

	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		resuelveCaso();
	}

	return 0;
}