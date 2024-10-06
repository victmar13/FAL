// Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

//funcion que resuelve el problema
int resolver(vector<int> const& v) {
	int cont = 0;
	int tam = v.size();
	int consecutivos = 0;
	int sum = 0;

	for (int i = 1; i < tam; i++) {
		if (v[i - 1] != v[i] - 1 && v[i - 1] != v[i] + 1) {// no es consecutivo
			if (consecutivos >= 1) {
				cont += sum;
			}
			sum = 0;
			consecutivos = 0;
		}
		else { // son consecutivos
			consecutivos++;
			sum += consecutivos;
		}
	}
	if (consecutivos >= 1) {
		cont += sum;
	}
	return cont;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	//leer los datos de la entrada
	int tam;
	cin >> tam;

	if (tam < 0 || tam > 150000 || !cin) {
		return false;
	}
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}
	if (tam == 1 || tam == 0) {
		cout << "0";
	}
	else {
		int sol = resolver(lista);
		cout << sol;
	}
	cout << endl;
	return true;
}
int main() {
	// Para la entrada por fichero.
	int casos;
	cin >> casos;
	for (int i = 0; i < casos; i++) {
		resuelveCaso();
	}
		;

	return 0;
}
