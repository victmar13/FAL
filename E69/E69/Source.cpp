//A43
//Victoria Martin Rojo

#include <iostream>
#include <vector>


using namespace std;

struct tDatos {
	vector<int> consumos;
	vector<int> apariciones;
	int sols = 0;
	int consumoMax;
	vector<int> sol;
};

// Escribe una solucion
// Calcula de forma recursiva las combinaciones de los elementos
void combinaciones(int longit, int colores, tDatos& d, int pos, int consumoRestante, int ultimoNum, bool repe) {

	if (pos == longit ) {
		if (d.consumoMax >= consumoRestante) {
			d.sols++;
		}
		return;
	}

	for (int i = 0; i < colores; ++i) { // recorre la posicion pos metiendole todos los tipos de colores que se puedan meter
		//sol[k] = i;
		//metemos el tipo i en la posicion pos y aumentamos su numero de apariciones
		d.sol.push_back(i);
		d.apariciones[i]++;
		if ((ultimoNum != i || !repe) && (d.apariciones[i] <= (pos/2 + 1))){ // Si se añade la luz
			if (ultimoNum == i) {
				combinaciones(longit, colores, d, pos + 1, consumoRestante + d.consumos[i], i, true);
			}
			else {

				combinaciones(longit, colores, d, pos + 1, consumoRestante + d.consumos[i], i, false);
			}

		}
		d.apariciones[i]--;
		d.sol.pop_back();
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	tDatos d;
	int longitud, colores;
	cin >> longitud;
	if (!cin || longitud == 0) return false;
	cin >> colores >> d.consumoMax;
	if ((longitud <= 1)|| (colores <= 1) || d.consumoMax <= 0) {
		return false;
	}
	int aux;
	for (int i = 0; i < colores; i++) {
		cin >> aux;
		d.consumos.push_back(aux);
	}
	// Generar las soluciones
	d.apariciones.assign(colores, 0);
	combinaciones(longitud, colores, d, 0, 0, -1, false);

	
	cout << d.sols << "\n";
	return true;
}
int main() {

	while (resuelveCaso()) {} // Resolvemos todos los casos

	return 0;
}
