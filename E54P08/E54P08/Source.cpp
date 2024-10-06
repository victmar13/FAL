// Victoria Martin Rojo
//A43

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//COSTE:
// Las operaciones en cada nivel de recursión son de tiempo constante, realizando comparaciones y asignaciones.
//Recurrencia : Siendo n la diferencia entre fin e ini la recurrencia es T(n) = T (n/2) + Orden
//Orden : O(log(n))  siendo n la diferencia entre fin e ini-> en cada nivel el trabajo es constante O(1)

int numFalta(vector<int>const& v1, vector<int>const& v2, int ini, int fin) {
	int sol;
	if (ini == fin) { sol = v1[ini]; }//b vacio o falta el elem que tiene a

	else if (fin - ini == 1 && v2[ini] == v1[ini]) { sol = v1[fin]; } // quedan 2 nums en el vector 1 y en el 2 solo uno, si coinciden es que el que falta en el vector 2 es el otro del vector 1, osea v1[fin] 
	else if (fin - 1 == ini) { sol = v1[ini]; } // igual que el anterior pero no coinciden los numeros por lo que el numero que le falta al v2 es el v1[ini]
	else {// LLAMADA RECURSIVA 
		int mit = (ini + fin) / 2;
		//derecha
		if (v1[mit] == v2[mit]) { // si la mitad de ambos es el mismo numero, es que el numero que falta tiene que estar a la derecha  
			sol = numFalta(v1, v2, mit, fin);
		}
		//izquierda
		else { sol = numFalta(v1, v2, ini, mit); } //si la mitad de ambos es distinto numero, es que el numero que falta tiene que estar a la izquerda pues un hueco ha alterado la serie de números
	}
	return sol;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int n;
	cin >> n;
	vector<int> v1(n);
	vector<int> v2(n - 1);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> v2[i];
	}
	int sol = numFalta(v1, v2, 0, v2.size());

	// escribir sol
	cout << sol << "\n";

}
int main() {
	// Para la entrada por fichero.
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}