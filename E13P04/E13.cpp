// Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

//funcion que resuelve el problema
void resolver(vector<int> & v) {
	
	int tam = v.size();
	int alante = 1;
	
	for (int i = 1; i < tam; i++) {
		if (v[i] != v[i - 1]) {
			v[alante] = v[i];
			alante++;
		}
	}
	v.resize(alante);

}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	//leer los datos de la entrada
	int tam;
	cin >> tam;

	if (tam <= 0 || tam > 150000 || !cin) {
		return false;
	}
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}
	sort(lista.begin(), lista.end());
	resolver(lista);
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i] << " ";
	}
	cout << endl;
	return true;
}
int main() {
	// Para la entrada por fichero.
	while (resuelveCaso())
		;

	return 0;
}
