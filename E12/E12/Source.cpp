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

	int tam = v.size();
	int cont = 0;
	int par = 0;
	for (int i = tam - 1; i >= 0; i--) {
		if (v[i] % 2 == 0) {
			par += 1;
		}
		else {
			cont += par;
		}
	}
	
	return cont;

}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	int tam;
	cin >> tam;
	//leer los datos de la entradaç
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}

	int sol = resolver(lista);
	cout << sol << endl;

	return true;
}
int main() {
	// Para la entrada por fichero.
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso()
		;

	return 0;
}
