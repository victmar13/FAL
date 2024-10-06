//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int tam;
	cin >> tam;

	if (tam == -1)
		return false;

	vector<int> aux(tam);
	vector<long long int> etapas(tam + 1);
	etapas[tam] = 0;
	for (int i = 0; i < tam; i++)
		cin >> aux[i];

	for (int k = tam - 1; k > -1; k--)
		etapas[k] = etapas[k + 1] + aux[k];

	long long int d;
	cin >> d;

	// escribir sol
	for (int j = 0; j < d; j++) {
		int p;
		cin >> p;
		cout << etapas[p - 1] << endl;
	}
	cout << "---" << endl;

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}
 