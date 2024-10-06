//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

//funcion que resuelve el problema
bool resolver(vector<int> const& v, int d) {
	int tam = v.size();
	int cont = 1;
	for (int i = 1; i < tam; i++) {
		if (v[i] - v[i - 1] > 1 || v[i] - v[i - 1] < 0) {
			return false;
		}
		else if (v[i] - v[i - 1] == 0) {
			cont++;
			if (cont > d) {
				return false;
			}
		}
		else { cont = 1; }
	}
	return true;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int repes;
	int tam;
	cin >> repes >> tam;
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}

	bool sol = resolver(lista, repes);
	if (sol) { cout << "SI\n"; }
	else { cout << "NO\n"; }
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