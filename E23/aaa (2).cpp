//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

pair<int, int> resolver(vector<int> const& v, int max) { // 
	int tam = v.size();
	int cont = 0, maxSeq = 0, inicio = 0, fin = 0;

	for (int i = 0; i < tam; i++) {
		if (v[i] > max) {
			cont++;
		}
		if (v[i] <= max && cont > 0) {
			if (maxSeq < cont) {
				maxSeq = cont;
				inicio = i - cont;
				fin = i - 1;
			}
			cont = 0;
		}

	}

	return {inicio, fin};
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	
	int tam, max;

	cin >> tam >> max;

	vector<int> lista(tam);

	for(int i = 0; i < tam; i++){
		cin >> lista[i];
	}
	
	pair<int, int> sol = resolver(lista, max);
	
	cout << sol.first << " " << sol.second << "\n";
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