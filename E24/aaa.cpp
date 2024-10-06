//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<algorithm>


using namespace std;

int resolver(vector<int> const& v) { // 
	int tam = v.size();
	sort(v.begin(), v.end());

	int sol, cont = 0, max = 0;

	for (int i = 1; i < tam; i++) {
		if (v[i] == v[i - 1]) {
			cont++;
		}
		else if (v[i] > v[i - 1]) {
			if (cont > max) {
				max = cont;
				sol = v[i - 1];
			}
			cont = 0;
		}
	}
	

	return sol;
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	
	int tam;

	cin >> tam;

	if (tam < 0) {
		return false;
	}

	vector<int> lista(tam);

	for(int i = 0; i < tam; i++){
		cin >> lista[i];
	}
	
	int sol = resolver(lista);
	
	cout << sol << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.

	while (resuelveCaso());
	

	return 0;
}