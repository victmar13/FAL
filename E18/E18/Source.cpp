//Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>


using namespace std;

//funcion que resuelve el problema
vector<int> resolver(vector<int> const& v1, vector<int> const& v2) {
	vector<int> res;
	int cont1 = 0, cont2 = 0;
	while (cont1 < v1.size() && cont2 < v2.size()) {
		if (v1[cont1] < v2[cont2]) {
			res.push_back(v1[cont1]);
			cont1++;
		}
		else if (v1[cont1] > v2[cont2]) {
			res.push_back(v2[cont2]);
			cont2++;
		}
		else {
			res.push_back(v1[cont1]);
			res.push_back(v2[cont2]);
			cont1++; cont2++;
		}
	}
	while (cont1 < v1.size()) {
		res.push_back(v1[cont1]);
		cont1++;
	}
	while (cont2 < v2.size()) {
		res.push_back(v2[cont2]);
		cont2++;
	}


	return res;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int tam1, tam2;
	cin >> tam1 >> tam2;
	vector<int> lista1(tam1);
	for (int i = 0; i < tam1; i++) {
		cin >> lista1[i];
	}
	vector<int> lista2(tam2);
	for (int i = 0; i < tam2; i++) {
		cin >> lista2[i];
	}

	vector<int> sol = resolver(lista1, lista2);
	for (int i = 0; i < sol.size(); i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
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