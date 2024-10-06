// Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

using lli = long long int;

//funcion que resuelve el problema
int resolver(vector<int> const& v, int k) {

	int tam = v.size();
	int ini = 0, fin = 0, cont = 0;

	while (ini <= fin && fin < tam) {
		if (v[fin] - v[ini] == k) {
			cont++;
			fin++, ini++;
		}
		else if (v[fin] - v[ini] < k) {
			fin++;
		}
		else {
			ini++;
		}
	}

	return cont;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	//leer los datos de la entrada
	int tam, k;
	cin >> tam;
	if (tam < 0) {
		return false;
	}
	cin >> k;
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}

	int sol = resolver(lista, k);

	cout << sol << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	while (resuelveCaso())
		;

	return 0;
}
