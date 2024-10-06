// Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

//funcion que resuelve el problema
void resolver(vector<long long int>& v, int malo) {

	int tam = v.size();
	int alante = 0;

	for (int i = 0; i < tam; i++) {
		if (v[i] != malo) {
			v[alante] = v[i];
			alante++;
		}
	}
	v.resize(alante);

}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	//leer los datos de la entradaç
	int tam;
	int num_malo;
	cin >> tam >> num_malo;
	vector<long long int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}

	resolver(lista, num_malo);
	cout << lista.size() << endl;
	for (int i = 0; i < lista.size(); i++) {
		cout << lista[i] << " ";
	}
	cout << endl;

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
