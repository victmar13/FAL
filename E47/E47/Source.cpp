//Victoria Martin Rojo
//A43

#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

// Funcion que busca la posicion mas a la izquierda del elemento
template < class T >

int binarySearchIz(vector < T > const& v, T elem, int ini, int fin) {
	if (ini >= fin) return ini; // vector vacio
	else if (ini + 1 == fin) return ini; // vector 1 elemento
	else { // Vector de dos o mas elementos
		int mitad = (ini + fin - 1) / 2; 
		if (v[mitad] < elem) return binarySearchIz(v, elem, mitad + 1, fin);
		else return binarySearchIz(v, elem, ini, mitad + 1); // incluye la mitad
	}
}
// Funcion que busca la posicion mas a la derecha del elemento
template <class T >
int binarySearchDr(vector <T > const& v, T elem, int ini, int fin) {
	if (ini >= fin) return ini; // vector vacio
	else if (ini + 1 == fin) return ini; // vector un elemento
	else { // vector 2 o mas elementos
		int mitad = (ini + fin) / 2;
		if (elem < v[mitad]) return binarySearchDr(v, elem, ini, mitad);
		else return binarySearchDr(v, elem, mitad, fin); // Incluye el elemento mitad
	}
}
bool resuelveCaso() {
	int numelem, elem;
	cin >> numelem;
	if (!cin) return false;
	cin >> elem;
	vector < int > v(numelem);
	for (int& n : v) cin >> n;

	// Busca en el lado izquierdo
	int posIz = binarySearchIz(v, elem, 0, (int)v.size());

	if (posIz == v.size() || v[posIz] != elem)
		cout << "NO EXISTE \n";
	else {
		// Si existe el elemento busca en el lado derecho
		int posDr = binarySearchDr(v, elem, 0, (int)v.size());
		if (posIz == posDr) cout << posIz << "\n";
		else cout << posIz << " " << posDr << "\n";
	}
	return true;
}

int main() {
		while (resuelveCaso());
	return 0;
}