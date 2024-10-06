//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>


using namespace std;

// Escribe una solucion
void escribirSolucion(vector <int> const& v) {
	for (int i = 0; i < v.size(); i++) {
		switch (v[i]) {
		case 0: cout << "azul ";
			break;
		case 1: cout << "rojo ";
			break;
		case 2: cout << "verde ";
			break;

		default:
			break;
		}
	}
	cout << "\n";
}
// Calcula de forma recursiva las combinaciones de los elementos
void combinaciones(int n, int k, vector<int>& sol) {
	for (int i = 0; i < 3; ++i) {
		sol[k] = i;
		if (i != 2 || (i == 2 && sol[k - 1] != 2)) {

			if (k == n - 1) { // Es solucion
				escribirSolucion(sol);
			}
			else { // Sigue completando la solucion
				combinaciones(n, k + 1, sol);
			}
		}
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int n; 
	cin >> n;
	if (!cin || n == 0) return false;

	// Generar las soluciones
	vector<int> sol(n);
	sol[0] = 1;

	if (sol.size() == 1) {
		escribirSolucion(sol);
	}
	else {

		combinaciones(n, 1, sol);
	}

	cout << "\n";
	return true;
}
int main() {

	while (resuelveCaso()) {} // Resolvemos todos los casos

	return 0;
}