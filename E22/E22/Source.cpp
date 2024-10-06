//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

vector<int> resolver(vector<int> const& v, int tam) { // 
	int vueltas = v.size();
	int max = 0;
	vector<int> sol;
	vector<int> cont(tam + 1, 0);
	for (int i = 0; i < vueltas; i++) {
		cont[v[i]] ++;
		if (cont[v[i]] > max) {
			max = cont[v[i]];
			sol.clear();
			sol.push_back(v[i]);
		}
		else if (cont[v[i]] == max) {
			sol.push_back(v[i]);
		}
	}
	return sol;
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int tiradas, maximo;
	cin >> tiradas;
	if (tiradas < 1) { return false; }
	cin >> maximo;
	vector<int> valores(tiradas);
	for (int i = 0; i < tiradas; i++) {
		cin >> valores[i];
	}

	vector<int> sol = resolver(valores, maximo);
	int tam = sol.size();
	for (int i = 0; i < tam; i++) {
		cout << sol[i] << " ";
	}
	cout << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.

	while (resuelveCaso());

	return 0;
}