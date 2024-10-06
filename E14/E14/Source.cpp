// Nombre del alumno Victoria Martin Rojo
//Usuario del Juez A43
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

using lli = long long int;

//funcion que resuelve el problema
void resolver(vector<int> const& a, vector<lli>& v) {

	int tam = v.size();

	for (int i = 1; i < tam; ++i){
		v[i] = v[i - 1] + a[i - 1];
	}


}
//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {

	//leer los datos de la entrada
	int ini, fin;
	cin >> ini >> fin;
	int tam = fin - ini + 1;
	if (ini == 0 && fin == 0 || !cin) {
		return false;
	}
	vector<int> lista(tam);
	for (int i = 0; i < tam; i++) {
		cin >> lista[i];
	}

	vector<lli> salida(lista.size() + 1);
	resolver(lista, salida);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int f1, f2;
		cin >> f1 >> f2;
		cout << salida[f2 - ini + 1] - salida[f1 - ini] << "\n";
	}
	cout << " ---\n";
	return true;
}
int main() {
	// Para la entrada por fichero.
	while (resuelveCaso())
		;

	return 0;
}
