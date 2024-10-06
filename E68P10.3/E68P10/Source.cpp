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

bool esValida(vector<int>& sol, vector<int>& PPuestas, int pos) {
	//no puede haber 2 verddes seguidas ni verdes > azules
	if ((sol[pos] == 2 && sol[pos - 1] == 2) || (PPuestas[2] > PPuestas[0])) {
		return false;
	}
	else return true;
}

// Calcula de forma recursiva las combinaciones de los elementos
void combinaciones(int altura, int pos, vector<int>& sol, vector <int> & color, vector<int>PPuestas, int &contS) {
	if (altura == pos) { //Caso base, es solucion
		if (PPuestas[1] > (PPuestas[0]+PPuestas[2])) { //sol valida
			escribirSolucion(sol);
			contS++;
		}
		return;
	}
	for (int i = 0; i < 3; ++i) { //caso recursivo
		if (color[i] > 0) {
			sol[pos] = i;
			color[i]--;
			PPuestas[i]++;
			if (esValida(sol, PPuestas, pos)) { //comprobar restricciones
				combinaciones(altura, pos + 1, sol, color, PPuestas, contS);
			}
			color[i]++;
			PPuestas[i]--;

		}
	}
}
// Resuelve un caso de prueba , leyendo de la entrada la
// configuracion , y escribiendo la respuesta
bool resuelveCaso() {
	// Lectura de los datos de entrada
	int n;
	cin >> n;
	if (!cin || n < 2) return false;
	vector<int> colores_arv(3); //azul = 0, rojo = 1, verde = 2
	cin >> colores_arv[0] >> colores_arv[1] >> colores_arv[2];
	// Generar las soluciones
	vector<int> sol(n);
	sol[0] = 1; // siempre empieza por el rojo
	colores_arv[1]--;
	vector<int> piezasPuestas(3); // piezasPuestas[1]cada vez que se pone una roja, piezasPuestas[0] azules [2]verdes
	piezasPuestas[1]++;
	// par= tamaño torre, pos donde se empieza, vector solucion, vector de contador de colores
	int contSols = 0;
	combinaciones(n, 1, sol, colores_arv, piezasPuestas, contSols);
	if (contSols == 0) {
		cout << "SIN SOLUCION";
	}
	cout << "\n";
	return true;
}
int main() {

	while (resuelveCaso()) {} // Resolvemos todos los casos

	return 0;
}