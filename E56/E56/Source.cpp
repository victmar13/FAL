//Victoria Martin Rojo
//A43

#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>


using namespace std;

long long int recursivo(int n, int y) { // 
	//caso base n == 0{
	if (n == 0) {
		return 1;
	}
	//caso base 2 n == 1
	else if (n == 1) {
		return 2 * y;
	}
	//caso recursivo en caso de n > 1
	else {
		return 2 * y * recursivo(n - 1, y) - (2 * (n - 1) * recursivo(n - 2, y));
	}
}

//Resuelve un caso de prueba, leyendo de la entrada la
//configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	//leer los datos de la entrada
	int tramos, maxParadas;
	cin >> tramos >> maxParadas;
	if ((tramos  == 0 && maxParadas == 0) || tramos == 0) { return false; }
	vector<int> tiempos(tramos);
	for(int i = 0; i < tramos; i++) {
		cin >> tiempos[i];
	}

	long long int sol = recursivo(n, y);
	cout << sol << "\n";
	return true;
}
int main() {
	// Para la entrada por fichero.

	while (resuelveCaso());

	return 0;
}