#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>


using namespace std;


//funcion que resuelve el problema
pair<int, pair<int, int>> resolver(vector<int> const& v, int benefMin) {
	int ganancia = 0, ini = 0, fin = 0;
	pair<int, pair<int, int>> aux;
	aux.first = 0; aux.second.first = 0; aux.second.second = 0;
	for (int i = 0; i < v.size(); i++) {
		ganancia += v[i];
		if (ganancia >= benefMin) {
			fin = i;
		}
		if (ganancia - v[ini] > ganancia) {
			ini++;
			ganancia -= v[ini - 1];
		}
		if (ganancia > aux.first || (ganancia == aux.first && (fin - ini) < (aux.second.second - aux.second.first))) {
			aux.second.first = ini;
			aux.second.second = fin;
			aux.first = ganancia;
		}
	}

	return aux;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int tam, benefMin;
	cin >> tam >> benefMin;
	if (benefMin < 0) { return false; }

	vector<int> v(tam);
	for (int i = 0; i < tam; i++) {
		cin >> v[i];
	}
	pair<int, pair<int, int>> sol = resolver(v, benefMin);
		if (sol.first < benefMin) {
			cout << "NO COMPENSA \n";
		}
		else { cout << sol.first << " " << sol.second.first << " " << sol.second.second << "\n"; }
	return true;
}
int main() {
	// Para la entrada por fichero.
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}