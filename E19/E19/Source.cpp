#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>


using namespace std;

//funcion que resuelve el problema
vector<int> resolver(vector<int> const& v1, vector<int> const& v2) {
	vector<int> res;
	int cont1 = 0, cont2 = 0;
	while (cont1 < v1.size() && cont2 < v2.size()) {
		if (v1[cont1] == v2[cont2]) {
			res.push_back(v1[cont1]);
			cont1++, cont2++;
		}
		else if (v1[cont1] > v2[cont2]) {
			cont2++;
		}
		else {
			cont1++; 
		}
	}
	

	return res;
}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	vector<int> lista1;
	int i;
	cin >> i;
	while (i != 0) {
		lista1.push_back(i);
		cin >> i;
	}
	if (lista1.size() > 1) {

	sort(lista1.begin(), lista1.end());
	}
	vector<int> lista2;
	int j;
	cin >> j;
	while (j != 0) {
		lista2.push_back(j);
		cin >> j;
	}

	if (lista2.size() > 1) {

		sort(lista2.begin(), lista2.end());
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